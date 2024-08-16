#include "../../include/mockos/PasswordProxy.h"

/**
 * constructor for password-protected file
 * @param file pointer to file to add a password for
 * @param password password for file
 */
PasswordProxy::PasswordProxy(AbstractFile * file, std::string& password) {
    this->file = file;
    this->password = password;
}

/**
 * delete file pointer
 */
PasswordProxy::~PasswordProxy() {
    delete file;
}

/**
 * passwordPrompt: ask for password and get user input
 * @return input
 */
std::string PasswordProxy::passwordPrompt() {
    std::string input;

    std::cout << "Enter the password: " << std::endl;
    std::getline(std::cin, input);

    return input;
}

/**
 * checkPassword: check if input matches the file's passwrd
 * @param str input
 * @return 1 if strings match, 0 if not
 */
bool PasswordProxy::checkPassword(const std::string& str) {
    return str == password;
}

/**
 * read: ask for password and call read on the file if correct
 * @return vector of the file's contents or empty vector if the password is
 * incorrect
 */
std::vector<char> PasswordProxy::read() {
    if (checkPassword(passwordPrompt())) {
        return file->read();
    }
    return std::vector<char>{};
}

/**
 * write: ask for password and call write on the file if correct
 * @param vec vector of chars to be written to the file
 * @return success of writing or error code for wrong password
 */
int PasswordProxy::write(std::vector<char> vec) {
    if (checkPassword(passwordPrompt())) {
        return file->write(vec);
    }
    return WRONG_PASSWORD;
}

/**
 * append: ask for password and call append on the file if correct
 * @param vec vector of chars to be appended to the file
 * @return success of appending or error code for wrong password
 */
int PasswordProxy::append(std::vector<char> vec) {
    if (checkPassword(passwordPrompt())) {
        return file->append(vec);
    }
    return WRONG_PASSWORD;
}

/**
 * getSize: get size of file (not protected)
 * @return size of file
 */
unsigned int PasswordProxy::getSize() {
    return file->getSize();
}

/**
 * getSize: get name of file (not protected)
 * @return name of file
 */
std::string PasswordProxy::getName() {
    return file->getName();
}

/**
 * accept: call accept on the file and pass the visitor as the parameter if
 * the password is correct
 * @param visitor pointer to be used for visitor pattern
 */
void PasswordProxy::accept(AbstractFileVisitor * visitor) {
    if (checkPassword(passwordPrompt())) {
        file->accept(visitor);
    }
}

/**
 * clone: create a new password-protected file with a new name
 * @param name new file name for clone
 * @return new file object
 */
AbstractFile *PasswordProxy::clone(std::string & name) {
    // make sure to also create new file pointer
    return new PasswordProxy(file->clone(name), password);

}
