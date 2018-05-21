#include "Physics_component.h"

Physics_component::Physics_component() {
}

Physics_component::~Physics_component() {
}

void Physics_component::init() {
    gravity = true;
    if (!parent_entity->has_component<Transform_component>()) {
        parent_entity->add_component<Transform_component>();
    }
    transform = &parent_entity->get_component<Transform_component>();
}

void Physics_component::quick_update() {
    rollback_collider =
        parent_entity->get_component<Collider_component>().collider;
    rollback_position =
        parent_entity->get_component<Transform_component>().position;
    if (gravity) {
        if (transform->velocity.y < 1)
            transform->velocity.y += 0.3;
    } else {
        transform->velocity.y = 0;
    }
    std::cout << gravity << std::endl;
}

void Physics_component::update() {
}

void Physics_component::late_update() {

    rollback_collider.x += transform->velocity.x * transform->speed;
    rollback_collider.y += transform->velocity.y * transform->speed;
    gravity = true;
    for (auto& c : colliders) {
        SDL_Rect c_col = c->get_component<Collider_component>().collider;

        if (Collision::aabb_low_edge(rollback_collider, c_col) ||
            Collision::aabb_top_edge(rollback_collider, c_col)) {
            gravity               = false;
            transform->position.y = rollback_position.y;
        }
        if (Collision::aabb(c_col, rollback_collider)) {
            transform->position.x = rollback_position.x;
        }
    }
}