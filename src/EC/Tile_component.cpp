#include "Tile_component.h"
#include "../Texture_manager.h"

Tile_component::Tile_component(int         src_x,
                               int         src_y,
                               int         pos_x,
                               int         pos_y,
                               const char* path) {

    texture = Texture_manager::load_texture(path);

    src.x = src_x;
    src.y = src_y;
    src.w = 32;
    src.h = 32;

    dst.x = pos_x;
    dst.y = pos_y;
    dst.w = 32;
    dst.h = 32;
}

Tile_component::~Tile_component() {
    SDL_DestroyTexture(texture);
}

void Tile_component::init() {
}

void Tile_component::draw() {

    Texture_manager::draw(texture, src, dst, SDL_FLIP_NONE);
}