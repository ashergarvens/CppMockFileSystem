#include "../../include/mockos/RemoveCommand.h"

/**
 * Constructor
 * @param sys: corresponding file system that the command can use
 */
RemoveCommand::RemoveCommand(AbstractFileSystem * sys) {
    fileSystem = sys;
}

/**
 * displayInfo: gives information about the command and how to use it
 */
void RemoveCommand::displayInfo() {
    std::cout<< "rm creates a file, rm can be invoked with the command:"
                " rm <fileName>" << std::endl;
}

/**
 * execute: deletes the file from the file system given the file name
 * @param fileName
 * @return exit code based on success of execution
 */
int RemoveCommand::execute(std::string fileName) {
    if (fileName.empty()) { // check that a file name exists
        return INVALID_ARGS;
    }

    // return success of deleting file
    return fileSystem->deleteFile(fileName);
}
