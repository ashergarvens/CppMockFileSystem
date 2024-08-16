/*
 * Defines the TouchCommand class, which implements the AbstractCommand interface. This command is used
 * to create new files within the file system. Leveraging the AbstractFileSystem and AbstractFileFactory,
 * it allows for the creation of files which may include regular files or password-protected files through
 * the use of a PasswordProxy. The TouchCommand handles file creation logic, checking for existing files
 * and invoking file factory methods to instantiate new file objects as necessary.
 */
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "PasswordProxy.h"
#include <iostream>
#include <sstream>

class TouchCommand : public AbstractCommand {
private:
    AbstractFileSystem * fileSystem;
    AbstractFileFactory * fileFactory;
public:

    TouchCommand(AbstractFileSystem *, AbstractFileFactory *);
    void displayInfo() override;
    int execute(std::string input) override;

};