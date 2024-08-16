#include "mockos/MetadataDisplayVisitor.h"

/**
 * visit_TextFile: print out file name, type ("text"), and size
 * @param file file to be visited
 */
void MetadataDisplayVisitor::visit_TextFile(TextFile *file) {
    std::cout << std::setw(fileAndInfo) << file->getName() <<
    std::setw(fileAndInfo) << FILE_INFO::text << std::setw(fileAndInfo)
    << file->getSize() <<std::endl;
}

/**
 * visit_ImageFile: print out file name, type ("image"), and size
 * @param file file to be visited
 */
void MetadataDisplayVisitor::visit_ImageFile(ImageFile *file) {

    std::cout << std::setw(fileAndInfo) << file->getName() <<
    std::setw(fileAndInfo)  << FILE_INFO::img << std::setw
            (fileAndInfo) << file->getSize() << std::endl; //
}
