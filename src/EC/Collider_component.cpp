#include "Collider_component.h"
#include "../Texture_manager.h"

Collider_component::Collider_component(std::string _tag) {
    tag = _tag;
}

Collider_component::Collider_component(std::string _tag,
                                       int         pos_x,
                                       int         pos_y,
                                       int         size) {
    tag = _tag;

    collider.x = pos_x;
    collider.y = pos_y;
    collider.h = size;
    collider.w = size;
}

void Collider_component::init() {
    if (!parent_entity->has_component<Transform_component>()) {
        parent_entity->add_component<Transform_component>();
    }
    transform = &parent_entity->get_component<Transform_component>();

    coll_tex = Texture_manager::load_texture("assets/map/collider.png");
    src.x    = 0;
    src.y    = 0;
    src.w    = 32;
    src.h    = 32;

    dst.x = collider.x;
    dst.y = collider.y;
    dst.w = collider.w;
    dst.h = collider.h;
}

void Collider_component::update() {

    if (tag != "terrain") {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = static_cast<int>(transform->width * transform->scale);
        collider.h = static_cast<int>(transform->height * transform->scale);
    }

    // offset colliderów
}

void Collider_component::draw() {
    Texture_manager::draw(coll_tex, src, dst, SDL_FLIP_NONE);
}