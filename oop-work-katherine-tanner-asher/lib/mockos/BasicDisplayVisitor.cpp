#include "../../include/mockos/BasicDisplayVisitor.h"

/**
 * print out contents of text file
 * @param file to be visited by the visitor
 */
void BasicDisplayVisitor::visit_TextFile(TextFile *file) {
    std::vector<char> contents = file->read();
    std::copy(contents.begin(), contents.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << '\n';
}

/**
 * print out contents of image file formatted for display
 * @param file to be visited by the visitor
 */
void BasicDisplayVisitor::visit_ImageFile(ImageFile *file) {
    int size = file->getDimensions();
    std::vector<char> contents = file->read();

    // print from top to bottom, left to right
    for (unsigned int row = size - OFFSET; row < size; row--) {
        for (unsigned int col = INIT; col < size; col++) {
            std::cout << contents[size * row + col];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}
