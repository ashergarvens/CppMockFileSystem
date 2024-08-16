#include "../../include/mockos/CopyCommand.h"

/// constructor needs a file system to work.
/// \param fileSystem
CopyCommand::CopyCommand(AbstractFileSystem * fileSystem) {
    this->fileSystem = fileSystem;
}

// displays use of this command
void CopyCommand::displayInfo() {
    std::cout << "cp creates a copy of a file, cp can be invoked with the command: \n"
                 "cp <file_name> <new_file_name_without_extension>"<< std::endl;
}

/// copies the file inputted, new file must not include extension since its automatically added
/// \param input from command line
/// \return error code if there is one
int CopyCommand::execute(std::string input) {
    if (input.empty()) {
        return INVALID_ARGS;
    }

    std::istringstream iss(input);
    std::string originalFileName, newFileName;

    if (!(iss >> originalFileName)){
        return INVALID_ARGS;
    }

    if (!fileExists(originalFileName)){
        return FILE_NOT_FOUND;
    }

    std::string ext = originalFileName.substr(originalFileName.length() -
            EXT_INFO::EXT_LENGTH);

    if (!(iss >> newFileName)){
        return INVALID_ARGS;
    }

    if (fileExists(newFileName + EXT_INFO::DOT + ext)){
        return FILE_ALREADY_EXISTS;
    }


    AbstractFile * originalFile = fileSystem->openFile(originalFileName);
    AbstractFile * copiedFile = originalFile->clone(newFileName);
    fileSystem->closeFile(originalFile);


    if (copiedFile == nullptr){
        // if this code exits, it is likely because of incorrect password
        return WRONG_PASSWORD;
    } else {
        fileSystem->addFile(copiedFile->getName(), copiedFile);
        return SUCCESS;
    }
}

/// checks if a file is in the system
/// \param fileName
/// \return true if yes, else no
bool CopyCommand::fileExists(const std::string& fileName) {

    auto fileNames = fileSystem->getFileNames();
    auto result = fileNames.find(fileName);
    return result != fileNames.end();
}
