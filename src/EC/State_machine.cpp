#include "State_machine.h"
#include "../States/States.h"

State_machine::State_machine(std::string type) {

    if (type == "player") {
        states.push_back(new State_player_idle(this));
        states.push_back(new State_player_run(this));
        states.push_back(new State_player_jump(this));
        states.push_back(new State_player_climb_l(this));
        states.push_back(new State_player_climb_r(this));
        active = states[0];
    } else if (type == "enemy_turret") {
        states.push_back(new State_turret_idle(this));
        states.push_back(new State_turret_active(this));
        active = states[1];
    }
}

State_machine::~State_machine() {
}

void State_machine::set_active(std::string name) {
    active->on_disable();
    for (const auto& s : states) {
        if (s->name == name) {
            active = s;
            break;
        }
    }
    active->on_enable();
}

void State_machine::init() {
    transform = &parent_entity->get_component<Transform_component>();
    sprite    = &parent_entity->get_component<Sprite_component>();
}

void State_machine::quick_update() {
    rollback_position = transform->position;
}

void State_machine::update() {

    active->update();
    // std::cout << active->name << std::endl;
}

void State_machine::late_update() {
    rollback_collider = collider =
        parent_entity->get_component<Collider_component>().collider;

    rollback_collider.x += transform->velocity.x * transform->speed;
    rollback_collider.y += transform->velocity.y * transform->speed;

    active->late_update();
}