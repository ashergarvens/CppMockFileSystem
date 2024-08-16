//
// Created by katherine on 5/3/24.
//
#include "mockos/ESParsingStrategy.h"

/**
 * parse: go through the entire input string given and re-organize the string
 * to be used for a series of individual commands
 * @param input
 * @return
 */
std::vector<std::string> ESParsingStrategy::parse(std::string input) {
    std::vector<std::string> args;

    std::string dFlag = "-d";
    std::string aFlag = "-a";
    bool dSet = false;
    bool aSet = false;
    std::istringstream iss(input);
    std::string temp;
    std::string fileName;

    while (iss >> temp) {
        if (temp == dFlag) { // check for flags
            dSet = true;
        }
        else if (temp == aFlag) {
            aSet = true;
        }
        else {
            fileName = temp; // get file name from input
        }
    }

    std::string catArgs = fileName;

    if (aSet) {
        catArgs += " " + aFlag;
    }

    args.push_back(catArgs); // add the file name and flag if set for cat

    std::string dsArgs = fileName;

    if (dSet) {
        dsArgs += " " + dFlag;
    }

    args.push_back(dsArgs); // add the file name and flag if set for ds

    return args;
}

/**
 * getInfo: prints information about the corresponding macro command
 */
void ESParsingStrategy::getInfo() {
    std::cout << "es concatenates to a file and then displays the file's "
                 "contents, es can be invoked with the command:"
                " es <fileName_with_extension> [-a] [-d]. \nthe d and a flags"
                " can be set in any order to append to the file rather than "
                "overwrite the contents (a) and to show the data of the "
                "file rather than display the formatted file (d)."
                << std::endl;
}

