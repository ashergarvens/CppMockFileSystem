#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/CommandPrompt.h"
#include "../include/mockos/RemoveCommand.h"
#include "../include/mockos/LSCommand.h"
#include "../include/mockos/CatCommand.h"
#include "../include/mockos/CopyCommand.h"
#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/MacroCommand.h"
#include "../include/mockos/RenameParsingStrategy.h"
#include "../include/mockos/ESParsingStrategy.h"

#include <vector>

int main(int argc, char** argv) {
    // set up of the file system and factory to be added to command prompt
    AbstractFileSystem * system = new SimpleFileSystem();
    AbstractFileFactory * factory = new SimpleFileFactory();

    // loads everything into command prompt
    auto * cmdPrompt = new CommandPrompt();
    cmdPrompt->setFileFactory(factory);
    cmdPrompt->setFileSystem(system);

    // all commands that are added to command prompt are below
    auto *  touch = new TouchCommand(system, factory);
    auto * rm = new RemoveCommand(system);
    auto * ls = new LSCommand(system);
    auto * cat = new CatCommand(system);
    auto * cp = new CopyCommand(system);
    auto * ds = new DisplayCommand(system);
    auto * rn = new MacroCommand(system);
    auto * es = new MacroCommand(system);
    auto * ess = new ESParsingStrategy;
    auto * ps = new RenameParsingStrategy;

    // macro commands added after macro command is created
    rn->setParseStrategy(ps);
    rn->addCommand(cp);
    rn->addCommand(rm);

    es->setParseStrategy(ess);
    es->addCommand(cat);
    es->addCommand(ds);

    // all commands added to command prompt here
    cmdPrompt->addCommand("touch", touch);
    cmdPrompt->addCommand("rm", rm);
    cmdPrompt->addCommand("ls", ls);
    cmdPrompt->addCommand("cat", cat);
    cmdPrompt->addCommand("cp", cp);
    cmdPrompt->addCommand("ds", ds);
    cmdPrompt->addCommand("rn", rn);
    cmdPrompt->addCommand("es", es);

    // runs the command prompt, returning the error code as the exit code for the file.
    return cmdPrompt->run();
}