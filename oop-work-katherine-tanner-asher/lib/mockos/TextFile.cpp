#include "../../include/mockos/TextFile.h"

/**
 * constructor
 * @param name file name
 */
TextFile::TextFile(std::string name) {
    this->name = std::move(name);
}

/**
 * getSize
 * @return total size of the file contents
 */
unsigned int TextFile::getSize(){
    return contents.size();
}

/**
 * read: return contents of the file
 * @return contents
 */
std::vector<char> TextFile::read() {
    return contents;
}

/**
 * write: write data to the file
 * @param vec data to be written
 * @return success based on execution
 */
int TextFile::write(std::vector<char> vec){
    contents = vec;
    return SUCCESS;
}

/**
 * append: append data to the file
 * @param vec data to be appended
 * @return success based on execution
 */
int TextFile::append(std::vector<char> vec){
    contents.insert(std::end(contents), std::begin(vec), std::end(vec));
    return SUCCESS;
}

/**
 * getName(): return file name
 * @return
 */
std::string TextFile::getName(){
    return name;
}

/**
 * accept: calls visit_TextFile on visitor passed
 * @param visitor pointer to type of visitor to be used by visitor pattern
 */
void TextFile::accept(AbstractFileVisitor * visitor){
    visitor->visit_TextFile(this);
}

/**
 * copy constructor
 * @param name new file name
 * @param originalFile original file to be copied
 */
TextFile::TextFile(std::string& name, TextFile * originalFile) {
    this->name = name + EXT_INFO::DOT + EXT_INFO::TXT_EXT; // this must be here to
    // ensure copy is of same type
    this->contents = originalFile->read();
}

/**
 * clone: creates copy of text file
 * @param cloneName new file name
 * @return new file
 */
AbstractFile * TextFile::clone(std::string& cloneName) {
    return new TextFile(cloneName, this);
}
