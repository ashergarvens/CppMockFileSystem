#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/AbstractFileFactory.h"

#include <vector>

int main(int argc, char** argv) {
    AbstractFileSystem *system = new SimpleFileSystem();
    AbstractFileFactory *factory = new SimpleFileFactory();

    std::string textfilename = "TextFile.txt";
    std::string imgfilename = "ImageFile.img";
    AbstractFile * textfile = factory->createFile(textfilename);
    AbstractFile * imgfile = factory->createFile(imgfilename);

    system->addFile(textfilename, textfile);
    system->addFile(imgfilename, imgfile);

    system->openFile(imgfilename);

    std::vector<char> vec = {'X', ' ','X', ' ','X', ' ','X', ' ', 'X', '3'};
    for (auto& val : imgfile->read()){
        std::cout << val;
    }
    std::cout << std::endl;
    imgfile->write(vec);
//    std::cout << imgfile->read();
    for (auto& val : imgfile->read()){
        std::cout << val;
    }
    std::cout << std::endl;
    std::cout << system->closeFile(imgfile) << std::endl;
    std::cout << system->deleteFile(imgfilename) << std::endl;


    return 0;
}