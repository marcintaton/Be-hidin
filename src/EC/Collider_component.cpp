#include "Collider_component.h"

Collider_component::Collider_component(std::string tag) {
    this->tag = tag;
}

void Collider_component::init() {
    if (!parent_entity->has_component<Transform_component>()) {
        parent_entity->add_component<Transform_component>();
    }
    transform = &parent_entity->get_component<Transform_component>();
}

void Collider_component::update() {
    collider.x = static_cast<int>(transform->position.x);
    collider.y = static_cast<int>(transform->position.y);
    collider.w = static_cast<int>(transform->width * transform->scale);
    collider.h = static_cast<int>(transform->height * transform->scale);
}