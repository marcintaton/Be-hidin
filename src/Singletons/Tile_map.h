#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "../Game_controler.h"

class Tile_map {

   private:
    const char* map_file;
    int         map_scale;
    int         tile_size;
    int         scaled_size;

   public:
    Tile_map(const char* _map_file, int _map_scale, int _tile_size);
    ~Tile_map();

    void load_map(std::string file_path,
                  int         size_x,
                  int         size_y,
                  int         offset_x,
                  int         offset_y);

    void add_map_tile(int src_x, int src_y, int x, int y);
};

#endif