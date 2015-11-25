#include "WorkSpace.h"

WorkSpace::WorkSpace() {
    //ctor
}

WorkSpace::WorkSpace(std::string path) {
    std::cout << "Initialization of workspace at: " << path << std::endl;
    std::cout << "Backing up... " << std::endl;
    this->backUpBefore();
    std::cout << "Please Wait";
    this->directory = path;
    std::cout << ".";
    this->init();
    std::cout << ".";
}

WorkSpace::~WorkSpace() {
    //dtor
}

void WorkSpace::init() {
    system("dir");
}

void WorkSpace::backUpBefore() {
    std::vector<std::string> folders;

    std::string backUpDirectory = "backUp";
    std::string command;



    command = "u:&cd\\example&md ";
    command+= backUpDirectory;
    command+= "&for /d %d in (*) do (md .\\";
    command+= backUpDirectory;
    command+= "\\\"%d\"& (if not %d==\"";
    command+= backUpDirectory;
    command+= "\" (robocopy \".\\%d\\\" \".\\";
    command+= backUpDirectory;
    command+= "\\%d\" /move ) ) )";
    system(command.c_str());
}
/*
void WorkSpace::backUpBefore() {
    std::string backUpDirectory = "backUp";
    std::string command;
    command = "u:&cd\\example&md ";
    command+= backUpDirectory;
    command+= "&for /d %d in (*) do (md .\\";
    command+= backUpDirectory;
    command+= "\\\"%d\"& (if not %d==\"";
    command+= backUpDirectory;
    command+= "\" (robocopy \".\\%d\\\" \".\\";
    command+= backUpDirectory;
    command+= "\\%d\" /move ) ) )";
    system(command.c_str());
}*/
