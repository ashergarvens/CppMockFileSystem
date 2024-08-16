#include "../../include/mockos/LSCommand.h"

/**
 * LSCommand Constructor
 * @param sys: corresponding file system that the command can use
 */
LSCommand::LSCommand(AbstractFileSystem *sys) {
    fileSystem = sys;
}

/**
 * displayInfo: gives information about the command and how to use it
 */
void LSCommand::displayInfo() {
    std::cout
            << "ls displays all the file names in the current file directory, "
               "ls can be invoked with the command: ls or the command: ls -m\n"
               "With the m flag, ls will display the file name, the type of"
               "file, and the size of the file" << std::endl;

}

/**
 * execute: displays all the files in the current file system. Can also
 * display metadata about the files if the m flag is set
 * @param flag input from the command line
 * @return exit code based on success of execution
 */
int LSCommand::execute(std::string flag) {
    std::set<std::string> fileNames = fileSystem->getFileNames();

    if (flag == "-m") { // check for flag and visit each file with
        // Metadata Display visitor if so

        MetadataDisplayVisitor visitor;
        AbstractFile *temp;
        int exitCode;

        for (const auto &fileName: fileNames) {

            temp = fileSystem->openFile(fileName);
            if (temp == nullptr) {
                return INVALID_FILE;
            }
            temp->accept(&visitor);
            exitCode = fileSystem->closeFile(temp); // make sure to open and
            // close file for safety
            if (exitCode != SUCCESS) {
                return exitCode;
            }
        }
    } else { // otherwise, print out a certain amount of file names each line
        // (in this case 2)
        int count = INIT;

        for (const auto &fileName: fileNames) {
            std::cout << std::left << std::setw(fileLength) <<
            fileName;
            ++count;

            if (count % filesPerLine == INIT) {
                std::cout << std::endl;
            }

        }
        std::cout << std::endl;
    }

    return SUCCESS;
}
