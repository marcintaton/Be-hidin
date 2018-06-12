#include "Tile_map.h"
#include <fstream>
#include "../EC/Components.h"
#include "../EC/EC.h"
#include "../Game_controler.h"

extern Entity_manager manager;
extern const char*    map_tileset;

Tile_map::Tile_map(const char* _map_file, int _map_scale, int _tile_size) {
    map_file    = _map_file;
    map_scale   = _map_scale;
    tile_size   = _tile_size;
    scaled_size = map_scale * tile_size;
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
            src_y = atoi(&tile) * tile_size;
            input_file.get(tile);
            src_x = atoi(&tile) * tile_size;
            add_map_tile(src_x, src_y, (x + offset_x) * scaled_size,
                         (y + offset_y) * scaled_size);
            input_file.ignore();
        }
    }
    // blank line between map and collidrermap
    input_file.ignore();

    for (int y = 0; y < size_y; ++y) {
        for (int x = 0; x < size_x; ++x) {

            input_file.get(tile);
            if (tile == '0') {
                auto& collider(manager.add_entity());
                collider.add_component<Collider_component>(
                    "terrain", (x + offset_x) * scaled_size,
                    (y + offset_y) * scaled_size, scaled_size);
                collider.add_group(Game_controler::g_colliders);
            }
            input_file.ignore();
        }
    }

    input_file.close();
}

void Tile_map::add_map_tile(int src_x, int src_y, int x, int y) {
    auto& tile(manager.add_entity());
    tile.add_component<Tile_component>(src_x, src_y, x, y, tile_size, map_scale,
                                       map_tileset);
    tile.add_group(Game_controler::g_map);
}
