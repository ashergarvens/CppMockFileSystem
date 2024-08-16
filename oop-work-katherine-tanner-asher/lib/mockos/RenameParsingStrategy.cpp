#include "../../include/mockos/RenameParsingStrategy.h"

/**
 * parse: go through the entire input string given and re-organize the string
 * to be used for a series of individual commands
 * @param input
 * @return
 */
std::vector<std::string> RenameParsingStrategy::parse(std::string input) {
    std::vector<std::string> args{};

    size_t pos = input.find(' ');

    if (pos != std::string::npos) {
        // split the string into the existing file name and the new file name
        std::string existing_file = input.substr(INIT, pos);
        std::string new_name = input.substr(pos + OFFSET);

        args.push_back(existing_file + " " + new_name); // for cp command
        args.push_back(existing_file); // for rm command
    }

    // return vector of arguments (incorrectly formatted input will be an
    // empty vector)
    return args;
}

/**
 * getInfo: prints information about the corresponding macro command
 */
void RenameParsingStrategy::getInfo() {
    std::cout << "rn renames a file, rn can be invoked with the command:"
                 " rn <fileName_with_extension> "
                 "<new_fileName_without_extension>"
              << std::endl;
}
