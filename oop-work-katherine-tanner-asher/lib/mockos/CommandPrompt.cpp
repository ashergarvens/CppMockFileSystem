#include  "../../include/mockos/CommandPrompt.h"

/**
 * Constructor to set initial values for member variables
 */
CommandPrompt::CommandPrompt() {
    fileSystem = nullptr;
    fileFactory = nullptr;
}

/**
 * setFileSystem: sets fileSystem member variable
 * @param s
 */
void CommandPrompt::setFileSystem(AbstractFileSystem * s) {
    fileSystem = s;
}

/**
 * setFileFactory: sets fileFactory member variable
 * @param f
 */
void CommandPrompt::setFileFactory(AbstractFileFactory * f) {
    fileFactory = f;
}

/**
 * addCommand: adds a command pointer and the string used to call the command to
 * the map of commands
 * @param identifier
 * @param pCommand
 * @return error code if there is one
 */
int CommandPrompt::addCommand(const std::string& identifier, AbstractCommand * pCommand) {
    auto result = commands.insert(std::make_pair(identifier, pCommand));
    // add string and pointer pair to the map

    if (result.second) {
        return SUCCESS;
    }

    // if the pair wasn't added successfully, return error
    return COMMAND_ALREADY_EXISTS;
}

/**
 * listCommands: prints out each command string in the map
 */
void CommandPrompt::listCommands() {
    for (auto & c : commands) {
        std::cout << c.first << " " << std::endl;
    }
}

/**
 * prompt: print helpful information and get input from command line
 * @return user input
 */
std::string CommandPrompt::prompt() {
    std::string input;

    std::cout << "Enter a command, 'q' to quit, 'help' for a list of "
                 "commands, or 'help' followed by a command name for more "
                 "information about that command.\n$    ";

    std::getline(std::cin, input);

    return input;
}

/**
 * run: repeatedly get input and execute corresponding commands
 * @return error code if there is one
 */
int CommandPrompt::run() {
    std::string input;

    while(true) {
        input = prompt();

        if (input == "q") { // check for quit
            exportFiles(); // export files to DIR when exiting properly
            return QUIT;
        }
        else if (input == "help") {
            listCommands();
        }
        else {
            size_t pos = input.find(' ');

            if (pos == std::string::npos) { // look for command string from
                // input
                auto it = commands.find(input);

                if (it == commands.end()) {
                    std::cout << "Command not found" << std::endl;
                }
                else { // get corresponding command pointer
                    AbstractCommand * command = it->second;

                    if (command) { // call execute with empty string and return
                        // execution result
                        int result = command->execute(std::string());

                        if (result != SUCCESS) {
                            std::cout << "Command failed" << std::endl;
                        }
                    }
                }

            }
            else { // split input string into 2 parts
                std::string cmd = input.substr(INIT, pos);
                input = input.substr(pos + OFFSET);
                if (cmd == "help") { // check if first word is "help" and
                    // call displayInfo on the command after help

                    auto it = commands.find(input);

                    if (it == commands.end()) {
                        std::cout << "Command does not exist" << std::endl;
                    }
                    else {
                        AbstractCommand * command = it->second;
                        if (command) {
                            command->displayInfo();
                        }
                    }
                }
                else { // look for command in map and call execute on the
                    // command
                    auto it = commands.find(cmd);

                    if (it == commands.end()) {
                        std::cout << "Command not found" << std::endl;
                    }
                    else {
                        AbstractCommand * command = it->second;
                        // passing everything after the command string as the
                        // parameter
                        if (command) {
                            int result = command->execute(input); // return
                            // success status of execution

                            if (result != SUCCESS) {
                                std::cout << "Command failed" << std::endl;
                            }
                        }
                    }
                }
            }
        }

    }
}
/// exported the files to a real file system after the program is quit.
void CommandPrompt::exportFiles() {
    if (fileSystem == nullptr){
        return;
    }

    ExternalFileDisplayVisitor efdVisitor;

    for (const std::string& fileName : fileSystem->getFileNames()){
        AbstractFile * file = fileSystem->openFile(fileName);
        file->accept(&efdVisitor);
        fileSystem->closeFile(file);
    }
}
