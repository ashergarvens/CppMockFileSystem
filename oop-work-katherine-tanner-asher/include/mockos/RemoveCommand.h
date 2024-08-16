/*
 * Defines the RemoveCommand class which implements the AbstractCommand interface. This command
 * facilitates the removal of files within the file system managed by AbstractFileSystem. It is designed
 * to handle the deletion of files by name, ensuring that file system integrity and rules are respected
 * during the operation. This class plays a crucial role in file management operations, providing user
 * feedback and comprehensive handling of potential errors during the file removal process.
 */
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include <iostream>

class RemoveCommand : public AbstractCommand {
private:
    AbstractFileSystem * fileSystem;
public:

    RemoveCommand(AbstractFileSystem *);
    void displayInfo() override;
    int execute(std::string fileName) override;

};