#include "Freeze_bonus.h"

extern std::vector<Entity*>& projectiles;
extern std::vector<Entity*>& enemies;

Freeze_bonus::Freeze_bonus(Bonus_controller* _ctrl) {

    controller  = _ctrl;
    bonus_start = 0;
    bonus_timer = 8000;
}

Freeze_bonus::~Freeze_bonus() {
}

void Freeze_bonus::on_enable() {
    bonus_start = SDL_GetTicks();
    active      = true;
    for (auto& p : projectiles) {
        p->get_component<Transform_component>().speed = 0;
    }
    for (auto& e : enemies) {
        e->get_component<Transform_component>().speed = 0;
        e->get_component<Shooter_component>().active  = false;
    }
}

void Freeze_bonus::on_disable() {

    for (auto& p : projectiles) {
        p->get_component<Transform_component>().speed = 3;
    }
    for (auto& e : enemies) {
        e->get_component<Transform_component>().speed = 3;
        e->get_component<Shooter_component>().active  = true;
    }
}

void Freeze_bonus::update() {

    if (SDL_GetTicks() > bonus_start + bonus_timer) {
        on_disable();
        active = false;
    }
}