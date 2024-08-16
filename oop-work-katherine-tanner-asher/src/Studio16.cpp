#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFile.h"
#include <iostream>

int main(int argc, char** argv){
    TextFile test("asdlasdlkfjasdf");
    AbstractFile &p = test;

    std::vector<char> vec = {'a', 'b', 'c'};

    p.write(vec);
    std::cout << p.getName() << std::endl;
    p.read();
    std::cout << std::endl;
    p.append(vec);
    p.read();
    std::cout << p.getSize() << std::endl;
}