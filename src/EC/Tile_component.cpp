#include "Tile_component.h"
#include "../Texture_dataclass.h"

Tile_component::Tile_component(int x, int y, int width, int height, int id) {

    rect.x  = x;
    rect.y  = y;
    rect.w  = width;
    rect.h  = height;
    tile_ID = id;

    path = Texture_dataclass::return_path("map_tiles", id);
}

void Tile_component::init() {

    if (!parent_entity->has_component<Transform_component>()) {
        parent_entity->add_component<Transform_component>(rect.x, rect.y,
                                                          rect.w, rect.h, 1);
    }
    transform = &parent_entity->get_component<Transform_component>();

    if (!parent_entity->has_component<Sprite_component>()) {
        parent_entity->add_component<Sprite_component>(path);
    }
    sprite = &parent_entity->get_component<Sprite_component>();
}