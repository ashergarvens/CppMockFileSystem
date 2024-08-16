#include "../../include/mockos/SimpleFileSystem.h"

/**
 * addFile: add a file to the map of all files
 * @param name file name to be added
 * @param p pointer to the file
 * @return success of adding the file
 */
int SimpleFileSystem::addFile(std::string name, AbstractFile *p) {
    if (allFiles.count(name) == INVALID) { // check that the file is not in
        // the map
        if(p != nullptr) { // check that the pointer is not null
            allFiles.insert(std::make_pair(name, p));
            return SUCCESS;
        }
        return INVALID_FILE;
    }
    return FILE_ALREADY_EXISTS;
}

/**
 * openFile: open a file by adding it to the set of open files
 * @param name file to be opened
 * @return pointer to opened file
 */
AbstractFile *SimpleFileSystem::openFile(std::string name) {
    if (allFiles.count(name) == VALID){ // make sure the file exists in the map
        AbstractFile * file = allFiles[name];
        if (openFiles.count(file) == INVALID){ // make sure that the file is
            // not already open
            openFiles.insert(file); // add file to set of oepn files
            return file;
        }
    }
    return nullptr;
}

/**
 * closeFile: close a file by removing it from the set of open files
 * @param p pointer to file to be closed
 * @return exit code based on success
 */
int SimpleFileSystem::closeFile(AbstractFile *p) {
    if (openFiles.count(p) == VALID){ // check that the file is in the set of
        // open files
        openFiles.erase(p); // delete the pointer from the set
        return SUCCESS;
    }
    return FILE_NOT_FOUND;
}

/**
 * deleteFile: delete file from the map of all files
 * @param name name of file to be deleted
 * @return exit code based on success
 */
int SimpleFileSystem::deleteFile(std::string name) {
    if (allFiles.count(name) == VALID){ // check that the file exists in the map
        AbstractFile * file = allFiles[name];
        if (openFiles.count(file) == INVALID){ // make sure that the file is
            // not open
            allFiles.erase(name); // remove from map
            delete file; // delete pointer to the file
            return SUCCESS;
        }
        return FILE_IS_OPEN;
    }
    return FILE_NOT_FOUND;
}

/**
 * getFileNames: return a set of all file names in system
 * @return set of names
 */
std::set<std::string> SimpleFileSystem::getFileNames() {
    std::set<std::string> fileNames = {};
    for (auto & pair : allFiles) {
        fileNames.insert(pair.first);
    }

    return fileNames;
}

