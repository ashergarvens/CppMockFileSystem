/*
 * Defines the PasswordProxy class which implements the AbstractFile interface. This class serves as a
 * security layer over an existing file object, enforcing password protection for any file operations
 * such as read, write, and append. The class delegates file operations to the encapsulated AbstractFile
 * object only if the correct password is provided. It uses a static method for prompting password input
 * and provides a method for password verification. The PasswordProxy enhances file security by ensuring
 * that all file accesses are authenticated.
 */
#pragma once
#include "AbstractFile.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class PasswordProxy : public AbstractFile {
private:
    AbstractFile * file;
    std::string password;
protected:
    static std::string passwordPrompt();
    bool checkPassword(const std::string&);
public:
    PasswordProxy(AbstractFile *, std::string&);
    ~PasswordProxy() override;
    std::vector<char> read() override;
    int write(std::vector<char>) override;
    int append(std::vector<char>) override;
    unsigned int getSize() override;
    std::string getName() override;
    void accept(AbstractFileVisitor*) override;
    AbstractFile * clone(std::string&) override;
};