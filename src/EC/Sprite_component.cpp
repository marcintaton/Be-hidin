#include "Sprite_component.h"
#include "../Texture_manager.h"

Sprite_component::Sprite_component(const char* tex_path) {
    set_texture(tex_path);
}

Sprite_component::~Sprite_component() {
    SDL_DestroyTexture(texture);
}

void Sprite_component::set_texture(const char* tex_path) {
    texture = Texture_manager::load_texture(tex_path);
}

void Sprite_component::init() {

    if (!parent_entity->has_component<Transform_component>()) {
        parent_entity->add_component<Transform_component>();
    }
    transform = &parent_entity->get_component<Transform_component>();

    src.x = 0;
    src.y = 0;
    src.h = transform->height;
    src.w = transform->width;
}

void Sprite_component::update() {

    dst.x = (int)transform->position.x;
    dst.y = (int)transform->position.y;
    dst.h = transform->height * transform->scale;
    dst.w = transform->width * transform->scale;
}

void Sprite_component::draw() {

    Texture_manager::draw(texture, src, dst);
}