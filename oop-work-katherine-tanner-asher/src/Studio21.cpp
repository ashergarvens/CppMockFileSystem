#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/CommandPrompt.h"
#include <vector>

int main(int argc, char** argv) {
    AbstractFileSystem *system = new SimpleFileSystem();
    AbstractFileFactory *factory = new SimpleFileFactory();

    std::string imgfilename = "ImageFile.img";


    CommandPrompt * cp = new CommandPrompt();

    cp->setFileFactory(factory);
    cp->setFileSystem(system);
    TouchCommand *  touch = new TouchCommand(system, factory);
    cp->addCommand("touch", touch);

    cp->run();

    AbstractFile * imgfile = system->openFile(imgfilename);

    std::vector<char> vec = {'X', ' ','X', ' ','X', ' ','X', ' ', 'X', '3'};
    for (auto& val : imgfile->read()){
        std::cout << val;
    }
    std::cout << std::endl;
    imgfile->write(vec);
    for (auto& val : imgfile->read()){
        std::cout << val;
    }
    std::cout << std::endl;
    std::cout << system->closeFile(imgfile) << std::endl;
    std::cout << system->deleteFile(imgfilename) << std::endl;



    return 0;
}