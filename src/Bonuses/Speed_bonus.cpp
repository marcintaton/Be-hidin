#include "Speed_bonus.h"

Speed_bonus::Speed_bonus(Bonus_controller* _ctrl) {

    controller  = _ctrl;
    bonus_start = 0;
    bonus_timer = 3000;
}

Speed_bonus::~Speed_bonus() {
}

void Speed_bonus::on_enable() {
    bonus_start = SDL_GetTicks();
    active      = true;
    controller->parent_entity->get_component<Transform_component>().speed = 6;
}

void Speed_bonus::on_disable() {
    controller->parent_entity->get_component<Transform_component>().speed = 3;
}

void Speed_bonus::update() {

    if (SDL_GetTicks() > bonus_start + bonus_timer) {
        on_disable();
        active = false;
    }
}