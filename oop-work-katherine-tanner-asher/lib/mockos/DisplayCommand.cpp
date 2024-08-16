#include "../../include/mockos/DisplayCommand.h"

/**
 * Constructor
 * @param sys file system command uses to handle files
 */
DisplayCommand::DisplayCommand(AbstractFileSystem * sys) {
    fileSystem = sys;
}

/**
 * execute: displays the contents of the file given by input
 * @param input file name
 * @return success status
 */
int DisplayCommand::execute(std::string input) {
    if (input.empty()) {
        return INVALID_ARGS;
    }

    size_t pos = input.find(' ');
    std::string fileName;
    bool dataOnly = false;

    // pull off the data only flag if it is part of the input
    if (pos != std::string::npos) {
        std::istringstream iss(input);
        std::string flag;
        iss >> fileName >> flag;

        if (flag == "-d") {
            dataOnly = true;
        }
    }
    else {
        fileName = input;
    }

    // open the file given by the file name
    AbstractFile * file = fileSystem->openFile(fileName);

    // make sure the file exists, if not, return error
    if (file == nullptr) {
        return FILE_NOT_FOUND;
    }

    // if the data only flag is set, simply print out the contents of the file
    if (dataOnly) {
        std::vector<char> contents = file->read();
        for (auto& val : contents){
            std::cout << val;
        }
        std::cout << std::endl;
    } else { // if no flag is set, use the visitor to display the formatted file
        BasicDisplayVisitor visitor;
        file->accept(&visitor);
    }

    return fileSystem->closeFile(file);
}

/**
 * displayInfo: gives information about the command and how to use it
 */
void DisplayCommand::displayInfo() {
    std::cout
            << "ds opens a file and displays its contents. It can be invoked "
               "with the command: ds <filename>\nWhen invoked without options,"
               "ds displays the file in a formatted view. Example usage: $ ds "
               "image.img\nThe '-d' option can be used for an un-formatted "
               "data-only view. Example usage: $ ds image.img -d\nThis allows "
               "users to view the content of files directly in the terminal, "
               "with or without formatting."
            << std::endl;
}
