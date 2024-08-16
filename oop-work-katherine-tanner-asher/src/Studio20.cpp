#include "../include/mockos/PasswordProxy.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/BasicDisplayVisitor.h"

#include <vector>

int main(int argc, char** argv) {
    std::string password = "password";
    std::string filename = "textfile.txt";
    TextFile * file = new TextFile(filename);
    BasicDisplayVisitor * visitor = new BasicDisplayVisitor();
    std::vector<char> text = {'h', 'i'};

    PasswordProxy proxy(file, password);

    std::vector<char> result;

    proxy.write(text);

    result = proxy.read();
    for (auto& val : result){
        std::cout << val;
    }
    std::cout << std::endl;

    proxy.append(text);

    result = proxy.read();
    for (auto& val : result){
        std::cout << val;
    }
    std::cout << std::endl;

    proxy.accept(visitor);

    return 0;
}