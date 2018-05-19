#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "Game_controler.h"

class Texture_manager {

   public:
    static SDL_Texture* load_texture(const char* file_name);
    static void         draw(SDL_Texture*     texture,
                             SDL_Rect         src,
                             SDL_Rect         dst,
                             SDL_RendererFlip flip);
};

#endif