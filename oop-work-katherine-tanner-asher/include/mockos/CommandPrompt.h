/*
 * Defines the CommandPrompt class, which serves as the main interface for executing commands
 * within the system. It integrates commands, a file system, and a file factory to provide a
 * comprehensive command-line user interface. Commands are mapped by name and executed through
 * this interface. The class also handles file exportation and displays a list of available commands.
 */
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "Constants.h"
#include "ExternalFileDisplayVisitor.h"

#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>

class CommandPrompt {
    std::map<std::string, AbstractCommand * > commands;
    AbstractFileSystem * fileSystem;
    AbstractFileFactory * fileFactory;
public:
    CommandPrompt();
    virtual ~CommandPrompt() = default;
    void setFileSystem(AbstractFileSystem *);
    void setFileFactory(AbstractFileFactory *);
    int addCommand(const std::string&, AbstractCommand *);
    int run();
protected:
    void listCommands();
    void exportFiles();
    static std::string prompt();
};