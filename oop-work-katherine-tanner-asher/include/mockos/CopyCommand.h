/*
 * Defines the CopyCommand class which implements the AbstractCommand interface. This command
 * facilitates copying files within the file system managed by AbstractFileSystem. It checks for
 * file existence and utilizes services provided by the filesystem to perform the copy operation.
 */

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "PasswordProxy.h"
#include <iostream>
#include <sstream>

class CopyCommand : public AbstractCommand {
private:
    AbstractFileSystem* fileSystem;
    bool fileExists(const std::string&);
public:
    explicit CopyCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string input) override;
};