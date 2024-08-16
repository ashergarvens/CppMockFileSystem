/*
 * Defines the MetadataDisplayVisitor class which implements the AbstractFileVisitor interface.
 * This visitor class is specialized for displaying metadata associated with file objects, such as TextFile
 * and ImageFile. It formats and outputs metadata details, tailored to the needs of different file types
 * within the system, using standard output with specified formatting widths.
 */
#pragma once
#include "../../include/mockos/AbstractFileVisitor.h"
#include "../../include/mockos/TextFile.h"
#include "../../include/mockos/ImageFile.h"
#include <vector>
#include <iostream>
#include <iomanip>

class MetadataDisplayVisitor : public AbstractFileVisitor {
    int fileAndInfo = 20;
    void visit_TextFile(TextFile* file) override;
    void visit_ImageFile(ImageFile* file) override;
};