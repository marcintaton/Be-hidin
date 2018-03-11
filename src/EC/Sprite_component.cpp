#include "Sprite_component.h"

Sprite_component::Sprite_component() {
}

Sprite_component::Sprite_component(const char* tex_path) {
}

Sprite_component::~Sprite_component() {
}

void Sprite_component::init() {

    position = &parent_entity->get_component<Position_component>();

    src.x = 0;
    src.y = 0;
    src.h = 32;
    src.w = 32;

    dst.x = 0;
    dst.y = 0;
    dst.h = 64;
    dst.w = 64;
}

void Sprite_component::update() {

    dst.x = position->get_x();
    dst.y = position->get_y();
}

void Sprite_component::draw() {

    // Texture_manager::draw()
}