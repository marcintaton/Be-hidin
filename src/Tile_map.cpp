#include "Tile_map.h"
#include <fstream>
#include "Game_controler.h"

Tile_map::Tile_map() {
}

Tile_map::~Tile_map() {
}

void Tile_map::load_map(std::string file_path, int size_x, int size_y) {

    char         tile;
    std::fstream input_file;
    input_file.open(file_path);

    for (int y = 0; y < size_y; ++y) {
        for (int x = 0; x < size_x; ++x) {
            input_file.get(tile);
            Game_controler::addMapTile(x * 32, y * 32, atoi(&tile));
            input_file.ignore();
        }
    }

    input_file.close();
}
