#include "../../include/mockos/MacroCommand.h"

/**
 * Constructor
 * @param sys: corresponding file system that the command can use
 */
MacroCommand::MacroCommand(AbstractFileSystem * sys) {
    fileSystem = sys;
    parsingStrategy = nullptr;
}

/**
 * execute: execute a series of individual commands
 * @param str: macro command arguments to be organized for individual commands
 * @return
 */
int MacroCommand::execute(std::string str) {
    // get corresponding inputs
    std::vector<std::string> args = parsingStrategy->parse(str);

    int result;
    // execute each individual command in the macro command and preemptively
    // return if a command was not successfully executed
    for(int i = INIT; i < args.size(); ++i) {
        result = commands[i]->execute(args[i]);
        if (result != SUCCESS) {
            return result;
        }
    }

    return SUCCESS;
}

/**
 * addCommand: add a command to the process for the macro command
 * @param cmd
 */
void MacroCommand::addCommand(AbstractCommand * cmd) {
    commands.push_back(cmd);
}

/**
 * setParseStrategy: set the parsing strategy to organize the command arguments
 * @param ps
 */
void MacroCommand::setParseStrategy(AbstractParsingStrategy * ps) {
    parsingStrategy = ps;
}

/**
 * displayInfo: get the information for the macro command based on the
 * parsing strategy
 */
void MacroCommand::displayInfo() {
    parsingStrategy->getInfo();
}