#include "Bonus_component.h"
#include "../Bonuses/Bonuses.h"
#include "../Collision.h"
#include "../Singletons/Player.h"

Bonus_component::Bonus_component(std::function<void()> _creator) {
    create_bonus = _creator;
}

Bonus_component::~Bonus_component() {
}

void Bonus_component::update() {

    if (Collision::aabb(
            parent_entity->get_component<Collider_component>().collider,
            Player::Get_instance()
                ->get_component<Collider_component>()
                .collider)) {
        if (Player::Get_instance()
                ->get_component<Bonus_controller>()
                .get_bonus() != nullptr) {
            Player::Get_instance()
                ->get_component<Bonus_controller>()
                .remove_bonus();
        }
        create_bonus();
        parent_entity->set_inactive();
    }
}