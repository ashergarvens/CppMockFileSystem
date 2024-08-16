/*
 * Defines the TextFile class, an implementation of the AbstractFile interface specifically for handling text files.
 * This class supports basic file operations including reading, writing, and appending data. It also provides
 * functionalities to retrieve the file's size and name, accept file visitors for operations like displaying or
 * editing, and clone itself for creating new file instances with modified properties. The class stores its content
 * in a vector of characters, facilitating efficient data manipulation and access.
 */
#pragma once
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"
#include <vector>
#include <string>
#include <utility>

class AbstractFile;
class AbstractFileVisitor;

class TextFile: public AbstractFile {
public:
    explicit TextFile(std::string);
    TextFile(std::string&, TextFile *);
    std::vector<char> read() override;
    int write(std::vector<char>) override;
    int append(std::vector<char>) override;
    unsigned int getSize() override;
    std::string getName() override;
    void accept(AbstractFileVisitor*) override;
    AbstractFile * clone(std::string&) override;

private:
    std::vector<char> contents;
    std::string name;
};