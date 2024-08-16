#include "../../include/mockos/TouchCommand.h"

/**
 * Constructor
 * @param sys: corresponding file system to handle files
 * @param fac: corresponding file factory to make files
 */
TouchCommand::TouchCommand(AbstractFileSystem * sys, AbstractFileFactory
* fac){
    fileFactory = fac;
    fileSystem = sys;
}

/**
 * displayInfo: gives information about the command and how to use it
 */
void TouchCommand::displayInfo() {
    std::cout<< "touch creates a file, touch can be invoked with the command:"
                "touch <file_name> or touch <file_name> -p to create a "
                "password protected file" << std::endl;
}

/**
 * execute: creates a file and adds it to the file system
 * @param input
 * @return
 */
int TouchCommand::execute(std::string input) {
    if (input.empty()) {
        return INVALID_ARGS;
    }

    // parse input to see if there is a space
    std::istringstream iss(input);
    std::string flag, fileName;
    iss >> fileName;

    // check if the flag is there, if not set default value
    if (!(iss >> flag)) flag = "";
    bool isPasswordProtected = flag == "-p";

    // Create the file without the flag
    AbstractFile* file = fileFactory->createFile(fileName);

    if (file == nullptr) {
        return INVALID_FILE; // Failed to create file
    }

    // if the p flag is set, ask for a password and create a new
    // password-protected file and add it to the system
    int result;
    if (isPasswordProtected) {
        std::string password;

        std::cout << "Create a password: " << std::endl;
        std::getline(std::cin, password);

        // Wrap the file with a PasswordProxy
        file = new PasswordProxy(file, password);

    }

    // make sure it is possible to add the file to the system
    result = fileSystem->addFile(fileName, file);

    if (result != SUCCESS) {
        delete file; // delete file if not added to the system to prevent
        // memory issues
    }

    return result;
}


