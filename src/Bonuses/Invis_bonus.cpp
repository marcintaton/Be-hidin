#include "Invis_bonus.h"

Invis_bonus::Invis_bonus(Bonus_controller* _ctrl) {

    controller  = _ctrl;
    bonus_start = 0;
    bonus_timer = 9000;
}

Invis_bonus::~Invis_bonus() {
}

void Invis_bonus::on_enable() {
    bonus_start = SDL_GetTicks();
    active      = true;
    controller->parent_entity->get_component<Sprite_component>().set_texture(
        invis_tex_path);
}

void Invis_bonus::on_disable() {
    controller->parent_entity->get_component<Sprite_component>().set_texture(
        normal_tex_path);
}

void Invis_bonus::update() {

    if (SDL_GetTicks() > bonus_start + bonus_timer) {
        on_disable();
        active = false;
    }
}