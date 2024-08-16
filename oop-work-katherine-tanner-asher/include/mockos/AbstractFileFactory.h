// This provides the interface for a file factory as a port of the mock file system.

#pragma once
#include "AbstractFile.h"
#include <string>

class AbstractFileFactory {
public:
    virtual AbstractFile * createFile(std::string) = 0;
};