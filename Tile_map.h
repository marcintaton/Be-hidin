#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "Game_controler.h"

class Tile_map {

   private:
    SDL_Rect                                            src;
    SDL_Rect                                            dst;
    std::unique_ptr<SDL_Texture, SDL_texture_destroyer> brick;

   public:
    Tile_map();
    ~Tile_map();

    void load_map();
    void draw_map();
};

#endif