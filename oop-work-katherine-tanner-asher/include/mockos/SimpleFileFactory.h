/*
 * Defines the SimpleFileFactory class, which implements the AbstractFileFactory interface.
 * This factory class is responsible for creating file objects based on the provided file name.
 * It decides the type of file object to create (e.g., TextFile, ImageFile) based on specific
 * criteria or file extensions mentioned in the file name. This class simplifies the process
 * of file object creation, centralizing the logic for instantiating different types of files.
 */
#pragma once

#include "AbstractFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
    AbstractFile * createFile(std::string name) override;
};