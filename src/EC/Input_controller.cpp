#include "Input_controller.h"
#include "../States/States.h"

Input_controller::Input_controller() {
}

void Input_controller::init() {
    transform = &parent_entity->get_component<Transform_component>();
    sprite    = &parent_entity->get_component<Sprite_component>();
}

void Input_controller::update() {

    if (Game_controler::event.type == SDL_KEYDOWN) {

        parent_entity->get_component<State_machine>().active->on_keydown();
    }

    if (Game_controler::event.type == SDL_KEYUP) {
        parent_entity->get_component<State_machine>().active->on_keyup();
    }
}