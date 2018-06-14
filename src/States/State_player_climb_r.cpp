#include "State_player_climb_r.h"
#include <iostream>
#include "../Collision.h"

extern std::vector<Entity*>& colliders;

State_player_climb_r::State_player_climb_r() {
    name = "player_climb_r";
}

State_player_climb_r::State_player_climb_r(State_machine* state_machine) {
    name           = "player_climb_r";
    parent_machine = state_machine;
}

State_player_climb_r::~State_player_climb_r() {
}

void State_player_climb_r::on_keydown() {

    switch (Game_controler::event.key.keysym.sym) {
        case SDLK_w:
            parent_machine->sprite->play("climb");
            parent_machine->transform->velocity.y = -1;
            break;
        case SDLK_s:
            parent_machine->sprite->play("climb");
            parent_machine->transform->velocity.y = 1;
            break;
        case SDLK_a:
            parent_machine->set_active("player_jump");
            parent_machine->sprite->flip(true);
            parent_machine->transform->velocity.x = -1;
            break;
        case SDLK_d:
            break;
        default:
            break;
    }
}

void State_player_climb_r::on_keyup() {

    switch (Game_controler::event.key.keysym.sym) {
        case SDLK_w:
            parent_machine->sprite->play("climb_idle");
            parent_machine->transform->velocity.y = 0;
            break;
        case SDLK_s:
            parent_machine->sprite->play("climb_idle");
            parent_machine->transform->velocity.y = 0;
            break;
        case SDLK_a:
            break;
        case SDLK_d:
            break;
        default:
            break;
    }
}

void State_player_climb_r::on_enable() {
    parent_machine->sprite->flip(false);
    parent_machine->sprite->play("climb_idle");
    parent_machine->transform->velocity.zero();
}

void State_player_climb_r::on_disable() {
}

void State_player_climb_r::update() {
}

void State_player_climb_r::late_update() {

    bool fall = true;

    SDL_Rect jump_col = parent_machine->rollback_collider;

    jump_col.x += 3;

    for (auto& c : colliders) {

        SDL_Rect c_col = c->get_component<Collider_component>().collider;

        if (Collision::aabb_edge_bottom(parent_machine->rollback_collider,
                                        c_col)) {
            parent_machine->set_active("player_idle");
        }

        if (Collision::aabb_pt_right_high(jump_col, c_col) ||
            Collision::aabb_pt_right_low(jump_col, c_col)) {

            fall = false;
        }
    }

    const Uint8* keys = SDL_GetKeyboardState(NULL);

    if (fall == true) {
        parent_machine->set_active("player_jump");
        if (keys[SDL_SCANCODE_W]) {
            parent_machine->transform->velocity.y = -2;
        }
    }
}