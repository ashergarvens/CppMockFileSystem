/* Abstract File System is the interface for adding deleting and closing new files. You can also get a list of file names.
 * */

#pragma once

#include <string>
#include <set>
#include "AbstractFile.h"

class AbstractFileSystem{
public:
    virtual int addFile(std::string name, AbstractFile * p) = 0;
    virtual int deleteFile(std::string name) = 0;
    virtual AbstractFile * openFile(std::string name) = 0;
    virtual int closeFile(AbstractFile * p) = 0;
    virtual std::set<std::string> getFileNames() = 0;
};