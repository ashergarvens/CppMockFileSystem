/*
 * Defines the ExternalFileDisplayVisitor class, which implements the AbstractFileVisitor interface.
 * This visitor handles the exportation and display of file types within the system, specifically
 * TextFiles and ImageFiles. It provides methods for building exported image filenames and moving
 * files to a designated destination directory. The class is equipped to manage file export operations,
 * leveraging the filesystem and I/O functionalities to handle file manipulation tasks efficiently.
 */

#pragma once
#include "../../include/mockos/AbstractFileVisitor.h"
#include "../../include/mockos/TextFile.h"
#include "../../include/mockos/ImageFile.h"
#include "../../include/mockos/Constants.h"
#include <vector>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>

class ExternalFileDisplayVisitor : public AbstractFileVisitor {
public:
    void visit_TextFile(TextFile *) override;
    void visit_ImageFile(ImageFile *) override;
private:
    static std::string buildExportedImageFileName (std::string);
    static int moveFileToDestination (const std::string);
};