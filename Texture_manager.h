#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "Game_controler.h"

class Texture_manager {

   public:
    static std::unique_ptr<SDL_Texture, SDL_texture_destroyer> load_texture(
        const char* file_name);
};

#endif