#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "Game_controler.h"

class Tile_map {

   private:
   public:
    Tile_map();
    ~Tile_map();

    static void load_map(std::string file_path, int size_x, int size_y);
};

#endif