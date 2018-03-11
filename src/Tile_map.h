#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "Game_controler.h"

class Tile_map {

   private:
    SDL_Rect     src;
    SDL_Rect     dst;
    SDL_Texture* wall;
    SDL_Texture* platform;
    SDL_Texture* sky;
    int          map[20][25];

   public:
    Tile_map();
    ~Tile_map();

    void load_map(int map[20][25]);
    void draw_map();
};

#endif