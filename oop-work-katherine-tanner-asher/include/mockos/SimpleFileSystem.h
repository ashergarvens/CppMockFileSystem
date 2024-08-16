/*
 * Defines the SimpleFileSystem class, an implementation of the AbstractFileSystem interface.
 * This class manages file operations within a simple file system, storing all files in a map
 * for quick access by name. It handles basic file management operations such as adding, deleting,
 * opening, and closing files. The class maintains a set of currently open files to manage file access
 * and ensure proper file operation handling. It also provides a method to retrieve the names of all
 * files currently managed by the file system.
 */
#pragma once

#include "AbstractFileSystem.h"
#include <map>
#include <string>
#include <set>

class SimpleFileSystem : public AbstractFileSystem{
private:
    std::map<std::string, AbstractFile *> allFiles;
    std::set<AbstractFile *> openFiles;

public:
    int addFile(std::string name, AbstractFile *p) override;
    int deleteFile(std::string name) override;
    AbstractFile * openFile(std::string name) override;
    int closeFile(AbstractFile *p) override;
    std::set<std::string> getFileNames() override;
};