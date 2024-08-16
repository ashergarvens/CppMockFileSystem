#include "../../include/mockos/CatCommand.h"

CatCommand::CatCommand(AbstractFileSystem* fileSystem) {
    this->fileSystem = fileSystem;
}

// usage command for cat command
void CatCommand::displayInfo() {
    std::cout << "cat edits [or appends to the] contents of a file\n cat "
                 "can be invoked with the command: cat <filename> [-a] "
                 "using the flag for append" << std::endl;
}

int CatCommand::execute(std::string input) {
    if (input.empty()){
        return INVALID_ARGS;
    }

    //parse input to see if there is a space
    std::istringstream iss(input);
    std::string flag, fileName;
    std::string appendMessage = "Enter the data that you would like to append to the existing file. ";
    std::string editMessage = "Enter the data that you would like to write to this file. ";
    std::string usageInformation = "Enter :wq to save and exit and :q to exit without saving.";
    std::vector<char> result;

    iss >> fileName;

    // check if the file exists
    AbstractFile * file = fileSystem->openFile(fileName);

    if (!file){
        return FILE_NOT_FOUND;
    }

    // check if the flag is there, if not set default value
    if (!(iss >> flag)) flag = "";
    bool isAppending = flag == "-a";

    // checks if user is editing or writing
    if (isAppending) {
        std::cout << appendMessage << usageInformation << std::endl;
    }
    else std::cout << editMessage << usageInformation << std::endl;


    std::cout << "root/" << fileName << std::endl;

    if (isAppending) {
        std::vector<char> contents = file->read();
        for (auto& val : contents){
            std::cout << val;
        }
        std::cout << std::endl;
    }


    result = promptInput();

    if (!result.empty()) {
        if (isAppending) {
            int error = file->append(result);
            if (error != SUCCESS) {
                fileSystem->closeFile(file);
                return error;
            }
        }
        else {
            int error = file->write(result);
            if (error != SUCCESS) {
                fileSystem->closeFile(file);
                return error;
            }
        }

        return fileSystem->closeFile(file);
    }

    return SUCCESS;
}

std::vector<char> CatCommand::promptInput() {
    std::vector<char> result;

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        if (input == ":wq") {
            result.pop_back();
            return result;
        } else if (input == ":q") {
            return {}; //defaults to empty array if input not saved
        } else {
            for (char i : input) {
                result.push_back(i);
            }
            result.push_back('\n');
        }
    }
}