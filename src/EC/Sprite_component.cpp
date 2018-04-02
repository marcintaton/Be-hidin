#include "Sprite_component.h"
#include "../Texture_manager.h"

Sprite_component::Sprite_component(const char* tex_path) {
    set_texture(tex_path);
}

Sprite_component::~Sprite_component() {
}

void Sprite_component::set_texture(const char* tex_path) {
    texture = Texture_manager::load_texture(tex_path);
}

void Sprite_component::init() {

    transform = &parent_entity->get_component<Transform_component>();

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

    dst.x = (int)transform->position.x;
    dst.y = (int)transform->position.y;
}

void Sprite_component::draw() {

    Texture_manager::draw(texture, src, dst);
}