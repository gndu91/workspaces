#include "main.h"

using namespace std;

int main(int argc, char** argv,char** env,char** env2) {
    WorkSpace workSpace(getFromEnv(convert(env), "USERPROFILE"));
    return 0;
}
std::vector<std::string> convert(char** tab) {
    std::vector<std::string> r;
    std::string line;
    for(int i(0);tab[i] != '\0';++i) {
        while(line.size())
            line.pop_back();
        for(int j(0);tab[i][j] != '\0';++j) {
            line.push_back(tab[i][j]);
        }
        r.push_back(line);
    }
    return r;
}
std::string getFromEnv(std::vector<std::string> env, std::string var) {
    for(auto line : env) {
        if(line.size() > var.size() and beginWith(line,var)) {
            std::string after;
            for(int i = var.size() + 1; i < line.size(); ++i)
                after.push_back(line.at(i));
            return after;
        }
    }
    return "a";
}

bool beginWith(std::string from,std::string to){///, bool caseSensitive) {
    if(from.size() < to.size())
        return false;
    for(int i = 0; i < to.size(); ++i) {
        if(from.at(i) != to.at(i))
            return false;
    }
    return true;
}
