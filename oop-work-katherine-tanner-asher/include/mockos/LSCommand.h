/*
 * Defines the LSCommand class which implements the AbstractCommand interface.
 * This command is responsible for listing files in the system, potentially along with additional
 * metadata, depending on the specified flags. It integrates with the AbstractFileSystem to
 * retrieve file data and uses the MetadataDisplayVisitor to format and display file metadata.
 * The command allows configuration of display properties such as file information width,
 * file name length, and the number of files per line, offering flexible output formatting.
 */

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <iomanip>

class LSCommand : public AbstractCommand {
private:
    AbstractFileSystem * fileSystem;

    int fileAndInfo = 20;
    int fileLength = 30;
    int filesPerLine = 2;

public:

    LSCommand(AbstractFileSystem *);
    void displayInfo() override;
    int execute(std::string flag) override;

};