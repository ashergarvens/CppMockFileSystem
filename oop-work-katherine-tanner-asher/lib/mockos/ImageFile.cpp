#include "../../include/mockos/ImageFile.h"

/**
 * constructor
 * @param name of file
 */
ImageFile::ImageFile(std::string name){
    this->name = name;
    this->size = INIT;
}

/**
 * getSize: return size of file contents
 * @return size
 */
unsigned int ImageFile::getSize() {
    return contents.size();
}

/**
 * getName
 * @return name of file
 */
std::string ImageFile::getName() {
    return name;
}

/**
 * write: write the contents of a file
 * @param vec data to be written
 * @return success of execution
 */
int ImageFile::write(std::vector<char> vec) {
    size = vec.back() - FILE_INFO::ZERO_CHAR; // get size from the last value
    // in the vector of data

    contents.clear(); // clear the file data

    // make sure that the vector is the correct length based on size of file
    if (vec.size() != (size * size) + OFFSET) {
        size = INIT;
        return INVALID_IMG;
    }

    // check that the file is correctly formatted, if not, clear the file and
    // return early
    for (int i = INIT; i < size * size; ++i) {
        if (vec[i] == FILE_INFO::X_TOKEN || vec[i] == FILE_INFO::SPACE_TOKEN) {
            contents.push_back(vec[i]);
        } else {
            contents.clear();
            size = INIT;
            return INVALID_IMG;
        }
    }
    return SUCCESS;
}

/**
 * append: not supported by image files
 * @return error
 */
int ImageFile::append(std::vector<char>) {
    std::cout << "Image File does not support append!" << std::endl;
    return IMG_DOES_NOT_SUPPORT_APPEND;
}

/**
 * read: get file data
 * @return contents in the file
 */
std::vector<char> ImageFile::read() {
    return contents;
}

/**
 * accept: call visit_ImageFile on the passed visitor pointer
 * @param visitor to be used
 */
void ImageFile::accept(AbstractFileVisitor * visitor) {
    visitor->visit_ImageFile(this);
}

/**
 * getDimensions: get the dimensions of the image (not equal to the size which
 * is the total length of the file)
 * @return dimensions of the file
 */
int ImageFile::getDimensions() const {
    return size;
}

/**
 * copy constructor
 * @param name new file name
 * @param originalFile pointer to file to be copied
 */
ImageFile::ImageFile(std::string name, ImageFile * originalFile) {
    this->name = name + EXT_INFO::DOT + EXT_INFO::IMG_EXT;
    this->contents = originalFile->read();
    this->size = contents.back() - FILE_INFO::ZERO_CHAR;

}

/**
 * clone: creates a copy of this file
 * @param cloneName new file name
 * @return
 */
AbstractFile *ImageFile::clone(std::string & cloneName) {
    return new ImageFile(cloneName, this);
}
