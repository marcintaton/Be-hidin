#include "Projectile_component.h"
#include "../Collision.h"
#include "../Singletons/Player.h"

extern std::vector<Entity*>& colliders;

Projectile_component::Projectile_component() {
}
Projectile_component::~Projectile_component() {
}

void Projectile_component::update() {

    SDL_Rect col = parent_entity->get_component<Collider_component>().collider;

    if (Collision::aabb(col, Player::Get_instance()
                                 ->get_component<Collider_component>()
                                 .collider)) {
        parent_entity->set_inactive();
        Player::Get_instance()->set_inactive();
        Player::act = false;
    }

    for (auto& c : colliders) {
        if (Collision::aabb(col,
                            c->get_component<Collider_component>().collider)) {
            parent_entity->set_inactive();
        }
    }
}