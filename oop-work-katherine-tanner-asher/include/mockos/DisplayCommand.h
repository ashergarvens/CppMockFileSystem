/*
 * Defines the DisplayCommand class which implements the AbstractCommand interface.
 * This command is designed to display the contents of a file using the BasicDisplayVisitor.
 * It leverages the AbstractFileSystem to access and manipulate files for display purposes.
 */

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "BasicDisplayVisitor.h"
#include <string>
#include <sstream>

class DisplayCommand : public AbstractCommand {
    AbstractFileSystem * fileSystem;
public:
    DisplayCommand(AbstractFileSystem *);
    int execute(std::string) override;
    void displayInfo() override;
};