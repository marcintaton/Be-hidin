#ifndef TEXTURE_DATACLASS_H
#define TEXTURE_DATACLASS_H

#include <cstring>
#include <map>
#include <vector>

class Texture_dataclass {
   public:
    static std::map<std::string, std::vector<std::string>> paths;

    static char* return_path(std::string tag, int id) {
        std::string s    = (paths.find(tag)->second)[id];
        char*       path = new char[s.length() + 1];
        std::strcpy(path, s.c_str());
        return path;
    }
};

#endif