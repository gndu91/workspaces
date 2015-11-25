#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include <windows.h>
#include <WinBase.h>

std::string getFromEnv(std::vector<std::string> env, std::string var);
std::vector<std::string> convert(char** tab);
bool beginWith(std::string,std::string);

#include "include/workspace.h"

#define DESKTOP_DIRECTORY(x) "#x"

/**
Mentions légales:
qui contacter
*/
