#include "State_turret_idle.h"
#include "../Linecast.h"
#include "../Singletons/Player.h"

State_turret_idle::State_turret_idle() {
    name = "turret_idle";
}

State_turret_idle::State_turret_idle(State_machine* state_machine) {
    name           = "turret_idle";
    parent_machine = state_machine;
}

State_turret_idle::~State_turret_idle() {
}

void State_turret_idle::on_enable() {
    parent_machine->sprite->set_src_rect(32, 0);
}

void State_turret_idle::update() {

    bool invis = false;
    if (Player::Get_instance()->get_component<Bonus_controller>().get_bonus() !=
        nullptr) {
        if (typeid(*(Player::Get_instance()
                         ->get_component<Bonus_controller>()
                         .get_bonus())) == typeid(Invis_bonus)) {
            invis = true;
        }
    }

    if (Player::act != false && invis == false &&
        !Linecast::linecast(parent_machine->transform->position,
                            Player::Get_instance()
                                ->get_component<Transform_component>()
                                .position)) {

        parent_machine->set_active("turret_active");
    }
}