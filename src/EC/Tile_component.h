#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include <SDL2/SDL.h>
#include "Components.h"
#include "EC.h"

class Tile_component : public Component {

   private:
   public:
    SDL_Rect     src;
    SDL_Rect     dst;
    SDL_Texture* texture;

    Tile_component() = default;
    Tile_component(int         src_x,
                   int         src_y,
                   int         pos_x,
                   int         pos_y,
                   const char* path);
    ~Tile_component();

    void init() override;
    void draw() override;
};

#endif