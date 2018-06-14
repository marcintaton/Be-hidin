#include "Bonus_component.h"
#include "../Bonuses/Bonuses.h"
#include "../Collision.h"
#include "../Singletons/Player.h"

Bonus_component::Bonus_component() {
}

Bonus_component::~Bonus_component() {
}

void Bonus_component::update() {

    if (Collision::aabb(
            parent_entity->get_component<Collider_component>().collider,
            Player::Get_instance()
                ->get_component<Collider_component>()
                .collider)) {
        Player::Get_instance()->get_component<Bonus_controller>().add_bonus(
            new Speed_bonus(
                &Player::Get_instance()->get_component<Bonus_controller>()));
        parent_entity->set_inactive();
    }
}