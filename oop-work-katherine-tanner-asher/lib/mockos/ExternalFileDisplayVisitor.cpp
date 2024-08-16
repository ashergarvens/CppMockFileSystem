//
// Created by Asher Garvens on 5/4/24.
//
#include "mockos/ExternalFileDisplayVisitor.h"
#include <cstdio>
using namespace EXPORT_INFO;

/// exports the file to an actual directory
/// \param file file to be exported
void ExternalFileDisplayVisitor::visit_TextFile(TextFile * file) {
    std::string fileName = file->getName();
    std::ofstream outFile(fileName, std::ios::trunc);

    if (outFile.is_open()) {
        for (const char character: file->read()){
            outFile << character;
        }
    } else {
        std::cout << "Unable to export file: " << fileName << std::endl;
        return; // exit if not able to create the file and open it successfully
    }
    moveFileToDestination(fileName);
}

/// exports the file to an actual directory
/// \param file file to be exported
void ExternalFileDisplayVisitor::visit_ImageFile(ImageFile * file) {
    std::string fileName = file->getName();
    std::string newFileName = buildExportedImageFileName(fileName) + ".txt";

    if (newFileName.empty()) {
        std::cout << "Unable to export file: " << fileName << " due to file name."<< std::endl;
        return;
    }
    std::ofstream outFile(newFileName, std::ios::trunc);
    if (outFile.is_open()) {
        int size = file->getDimensions();
        std::vector<char> contents = file->read();

        for (unsigned int row = size - OFFSET; row < size; row--) {
            for (unsigned int col = INIT; col < size; col++) {
                outFile << contents[size * row + col];
            }
            outFile << '\n';
        }
        outFile << '\n';

    } else {
        std::cout << "Unable to export file: " << fileName << std::endl;
        return; // exit if not able to create the file and open it successfully
    }
    if (moveFileToDestination(newFileName) == 0) {
        std::cout << fileName << " was moved successfully to " << EXPORTED_FILE_DESTINATION_DIRECTORY << ".\n";
    } else {
        std::cout <<("Unable to move " + fileName + " to " + EXPORTED_FILE_DESTINATION_DIRECTORY).c_str();
    }
}

/// builds the name for the image file since there is no correlating extension in real file system
/// \param fileName name to be exported
/// \return returns the standardized name
std::string ExternalFileDisplayVisitor::buildExportedImageFileName(std::string fileName) {

    if (fileName.size() >= 4 && fileName.substr(fileName.size() - 4) == ".img") {
        // Remove the last 4 characters (".img")
        fileName.erase(fileName.size() - 4);
    } else {
        return "";
    }
    return fileName + IMAGE_FILE_NAME_TOKEN;
}

/// moves file after creation to assigned directory
/// \param fileName file name to be moved

int ExternalFileDisplayVisitor::moveFileToDestination(const std::string fileName) {
    const std::string destinationDirectory = "../../" + std::string(EXPORTED_FILE_DESTINATION_DIRECTORY) + "/";
    const std::string fullFileName = destinationDirectory + fileName;

    // Attempt to move the file using rename
    if (std::rename(fileName.c_str(), fullFileName.c_str()) == 0) {
        //catching error codes from the function
        return SUCCESS;
    } else {
        return UNABLE_TO_MOVE_FILE;
    }
}


