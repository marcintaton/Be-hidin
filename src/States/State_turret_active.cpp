#include "State_turret_active.h"
#include "../Linecast.h"
#include "../Singletons/Player.h"

State_turret_active::State_turret_active() {
    name = "turret_active";
}

State_turret_active::State_turret_active(State_machine* state_machine) {
    name           = "turret_active";
    parent_machine = state_machine;
}

State_turret_active::~State_turret_active() {
}

void State_turret_active::on_enable() {
    parent_machine->sprite->set_src_rect(0, 0);
}

void State_turret_active::update() {
    bool invis = false;
    if (Player::Get_instance()->get_component<Bonus_controller>().get_bonus() !=
        nullptr) {
        if (typeid(*(Player::Get_instance()
                         ->get_component<Bonus_controller>()
                         .get_bonus())) == typeid(Invis_bonus)) {
            invis = true;
        }
    }

    if (Linecast::linecast(parent_machine->transform->position,
                           Player::Get_instance()
                               ->get_component<Transform_component>()
                               .position) ||
        invis == true || Player::act == false) {
        parent_machine->set_active("turret_idle");
    }

    parent_machine->parent_entity->get_component<Shooter_component>().shot();
}