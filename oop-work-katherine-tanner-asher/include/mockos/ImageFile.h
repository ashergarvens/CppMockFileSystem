/*
 * Defines the ImageFile class, which implements the AbstractFile interface.
 * This class is responsible for managing the data associated with image files, including
 * reading, writing, and appending data. It also handles basic file operations like retrieving
 * the file's name and size. The class supports visitor-based operations through the accept
 * method, allowing operations to be performed on image file objects via the AbstractFileVisitor
 * interface. Additionally, it includes functionality for managing image dimensions and cloning
 * the file with modifications.
 */
#pragma once
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"
#include <string>
#include <vector>
#include <iostream>

class AbstractFile;
class AbstractFileVisitor;

class ImageFile: public AbstractFile {
private:
    std::string name;
    std::vector<char> contents;
    char size;
public:
    ImageFile(std::string);
    ImageFile(std::string, ImageFile *);
    std::vector<char> read() override;
    int write(std::vector<char>) override;
    int append(std::vector<char>) override;
    unsigned int getSize() override;
    std::string getName() override;
    void accept(AbstractFileVisitor*) override;
    int getDimensions() const;
    AbstractFile * clone(std::string&) override;
};