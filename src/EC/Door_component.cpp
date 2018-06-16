#include "Door_component.h"
#include "../Collision.h"
#include "../Singletons/Player.h"

Door_component::Door_component() {
}

Door_component::~Door_component() {
}

void Door_component::update() {
    bool quest_completed = false;
    if (Collision::aabb(
            parent_entity->get_component<Collider_component>().collider,
            Player::Get_instance()
                ->get_component<Collider_component>()
                .collider)) {

        for (auto& i : Player::Get_instance()
                           ->get_component<Inventory_component>()
                           .inventory) {
            if (i->is_quest_item == true) {
                quest_completed = true;
            }
        }
    }

    if (quest_completed == true) {
        std::cout << "GG WP" << std::endl;
        Game_controler::running = false;
    }
}