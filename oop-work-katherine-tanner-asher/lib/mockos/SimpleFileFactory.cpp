#include "../../include/mockos/SimpleFileFactory.h"

/**
 * createFile: create a new file given a file name
 * @param name
 * @return
 */
AbstractFile * SimpleFileFactory::createFile(std::string name) {
    std::string ext = name.substr(name.length() - EXT_INFO::EXT_LENGTH);

    // create new file based on extension of the file and return the file
    if (ext == EXT_INFO::IMG_EXT) {
        return new ImageFile(name);

    } else if (ext == EXT_INFO::TXT_EXT) {
        return new TextFile(name);
    }
    return nullptr; // return nullptr if there is an invalid extension
}
