#include "State_player_run.h"
#include <iostream>
#include "../Collision.h"
#include "../EC/Shooter_component.h"

extern std::vector<Entity*>& colliders;

State_player_run::State_player_run() {
    name = "player_run";
}

State_player_run::State_player_run(State_machine* state_machine) {
    name           = "player_run";
    parent_machine = state_machine;
}

State_player_run::~State_player_run() {
}

void State_player_run::on_keydown() {

    const Uint8* keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_W]) {
        parent_machine->transform->velocity.y = -2;
        parent_machine->set_active("player_jump");
    } else if (keys[SDL_SCANCODE_S]) {
        //
    } else if (keys[SDL_SCANCODE_A]) {
        parent_machine->transform->velocity.x = -1;
        parent_machine->sprite->flip(true);
    } else if (keys[SDL_SCANCODE_D]) {
        parent_machine->transform->velocity.x = 1;
        parent_machine->sprite->flip(false);
    }
    if (keys[SDL_SCANCODE_E]) {
        parent_machine->parent_entity->get_component<Shooter_component>()
            .shot();
    }

    // switch (Game_controler::event.key.keysym.sym) {
    //     case SDLK_w:
    //         parent_machine->transform->velocity.y = -2;
    //         parent_machine->set_active("player_jump");
    //         break;
    //     case SDLK_s:
    //         // parent_machine->set_active("player_idle");
    //         break;
    //     case SDLK_a:
    //         parent_machine->transform->velocity.x = -1;
    //         break;
    //     case SDLK_d:
    //         parent_machine->transform->velocity.x = 1;
    //         break;
    //     default:
    //         break;
    // }
}

void State_player_run::on_keyup() {

    const Uint8* keys = SDL_GetKeyboardState(NULL);

    if (!keys[SDL_SCANCODE_A] && !keys[SDL_SCANCODE_W] &&
        !keys[SDL_SCANCODE_S] && !keys[SDL_SCANCODE_D]) {
        parent_machine->set_active("player_idle");
    }

    if (keys[SDL_SCANCODE_W]) {
        // parent_machine->transform->velocity.x = -1;
    } else if (keys[SDL_SCANCODE_S]) {
        // parent_machine->transform->velocity.x = 1;
    } else if (keys[SDL_SCANCODE_A]) {
        parent_machine->transform->velocity.x = -1;
    } else if (keys[SDL_SCANCODE_D]) {
        parent_machine->transform->velocity.x = 1;
    }
}

void State_player_run::on_enable() {
    parent_machine->sprite->play("run");
}

void State_player_run::on_disable() {
}

void State_player_run::update() {

    for (auto& c : colliders) {
        SDL_Rect c_col = c->get_component<Collider_component>().collider;

        // if (Collision::aabb_pt_bottom(parent_machine->rollback_collider,
        //                               c_col)) {
        //     std::cout << "pt bottom" << std::endl;
        // }
        // if (Collision::aabb_pt_top(parent_machine->rollback_collider, c_col))
        // {
        //     std::cout << "pt top" << std::endl;
        // }
        // if (Collision::aabb_pt_left_high(parent_machine->rollback_collider,
        //                                  c_col)) {
        //     std::cout << "pt left high" << std::endl;
        // }
        // if (Collision::aabb_pt_left_low(parent_machine->rollback_collider,
        //                                 c_col)) {
        //     std::cout << "pt left low" << std::endl;
        // }
        // if (Collision::aabb_pt_right_high(parent_machine->rollback_collider,
        //                                   c_col)) {
        //     std::cout << "pt right high" << std::endl;
        // }
        // if (Collision::aabb_pt_right_low(parent_machine->rollback_collider,
        //                                  c_col)) {
        //     std::cout << "pt right low" << std::endl;
        // }
    }
}

void State_player_run::late_update() {

    bool grav = true;
    for (auto& c : colliders) {
        SDL_Rect c_col = c->get_component<Collider_component>().collider;

        if (Collision::aabb_edge_left(parent_machine->rollback_collider,
                                      c_col)) {
            parent_machine->transform->position =
                parent_machine->rollback_position;
            parent_machine->transform->velocity.x = 0;
        }
        if (Collision::aabb_edge_right(parent_machine->rollback_collider,
                                       c_col)) {
            parent_machine->transform->position =
                parent_machine->rollback_position;
            parent_machine->transform->velocity.x = 0;
        }

        // handling jumping and gravity
        SDL_Rect jp = parent_machine->rollback_collider;
        jp.y += 5;

        if (Collision::aabb_edge_bottom(jp, c_col)) {
            grav = false;
        }
    }

    if (grav == true) {
        parent_machine->set_active("player_jump");
    }

    for (auto& c : colliders) {
        SDL_Rect c_col = c->get_component<Collider_component>().collider;
        if (Collision::aabb_pt_bottom(parent_machine->rollback_collider,
                                      c_col)) {
            while (Collision::aabb_pt_bottom(parent_machine->rollback_collider,
                                             c_col)) {
                parent_machine->rollback_collider.y -= 1;
            }
            parent_machine->transform->position.y =
                parent_machine->rollback_collider.y;
        }
    }
}