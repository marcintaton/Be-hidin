#include "Tile_map.h"
#include "Texture_manager.h"

Tile_map::Tile_map() {
    brick = Texture_manager::load_texture("assets/brick.png");
}

Tile_map::~Tile_map() {
}

void Tile_map::load_map() {
}

void Tile_map::draw_map() {
}