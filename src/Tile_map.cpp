#include "Tile_map.h"
#include <fstream>
#include "Game_controler.h"

Tile_map::Tile_map() {
}

Tile_map::~Tile_map() {
}

void Tile_map::load_map(std::string file_path,
                        int         size_x,
                        int         size_y,
                        int         offset_x,
                        int         offset_y) {

    char         tile;
    std::fstream input_file;
    input_file.open(file_path);

    int src_x;
    int src_y;

    for (int y = 0; y < size_y; ++y) {
        for (int x = 0; x < size_x; ++x) {

            input_file.get(tile);
            src_y = atoi(&tile) * 32;
            input_file.get(tile);
            src_x = atoi(&tile) * 32;
            Game_controler::addMapTile(src_x, src_y, (x + offset_x) * 32,
                                       (y + offset_y) * 32);
            input_file.ignore();
        }
    }

    input_file.close();
}
