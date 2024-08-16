/*
* Defines the CatCommand class which implements the AbstractCommand interface.
* This command is used to display file contents within the file system managed by AbstractFileSystem.
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

#include <iostream>
#include <sstream>
#include <string>

class CatCommand: public AbstractCommand{
private:
    AbstractFileSystem* fileSystem;
    static std::vector<char> promptInput();
public:
    explicit CatCommand(AbstractFileSystem* fileSystem);
    void displayInfo() override;
    int execute(std::string input) override;
};