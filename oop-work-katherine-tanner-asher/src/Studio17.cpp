#include "../include/mockos/ImageFile.h"
#include "../include/mockos/AbstractFile.h"
#include "../include/mockos/SimpleFileSystem.h"
#include <iostream>

int main(int argc, char** argv){
    ImageFile test("asdlasdlkfjasdf");
    AbstractFile &p = test;

    std::vector<char> vec = {'X', ' ','X', ' ','X', ' ','X', ' ', 'X', '3'};

    p.write(vec);
    std::cout << p.getName() << std::endl;
    p.read();
    std::cout << std::endl;
    p.append(vec);
    p.read();
    std::cout << p.getSize() << std::endl;

    SimpleFileSystem sys;
    std::string textFile = "TextFile.txt";
    std::string imgFile = "ImageFile.img";

    std::cout << sys.createFile(textFile) << std::endl;
    std::cout << sys.createFile(imgFile) << std::endl;
    AbstractFile * text = sys.openFile(textFile);
    text->write(vec);
    text->read();
    text->append(vec);

    std::cout << sys.closeFile(text) << std::endl;
    std::cout << sys.deleteFile(textFile) << std::endl;

}