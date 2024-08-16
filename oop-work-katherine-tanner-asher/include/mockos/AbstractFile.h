// This file has the interface for any file types in the file system. This is the interface that must be used to implement
// the mock file system.

#pragma once
#include <vector>
#include <string>
#include "Constants.h"

class AbstractFileVisitor;

class AbstractFile {
public:
    virtual std::vector<char> read() = 0;
    virtual int write(std::vector<char>) = 0;
    virtual int append(std::vector<char>) = 0;
    virtual unsigned int getSize() = 0;
    virtual std::string getName() = 0;
    virtual ~AbstractFile() = default;
    virtual void accept(AbstractFileVisitor*) = 0;
    virtual AbstractFile * clone(std::string&) = 0;
};