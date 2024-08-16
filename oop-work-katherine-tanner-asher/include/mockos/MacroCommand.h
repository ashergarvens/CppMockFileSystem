/*
 * Defines the MacroCommand class, an implementation of the AbstractCommand interface.
 * This command facilitates the execution of multiple commands sequentially as a single macro command.
 * It utilizes an AbstractFileSystem for file system operations and leverages an AbstractParsingStrategy
 * to interpret and execute a series of command strings. The class allows for dynamic addition of commands
 * and setting a specific parsing strategy to handle command parsing, making it versatile for various macro
 * operations within the system.
 */
#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>
#include <string>
#include <iostream>

class MacroCommand : public AbstractCommand {
    AbstractFileSystem * fileSystem;
    std::vector<AbstractCommand *> commands;
    AbstractParsingStrategy * parsingStrategy;
public:
    explicit MacroCommand(AbstractFileSystem *);
    int execute(std::string) override;
    void displayInfo() override;
    void addCommand(AbstractCommand *);
    void setParseStrategy(AbstractParsingStrategy *);
};