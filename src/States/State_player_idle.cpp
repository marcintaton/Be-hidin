#include "State_player_idle.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "../Collision.h"
#include "../EC/Shooter_component.h"

extern std::vector<Entity*>& colliders;

State_player_idle::State_player_idle() {
    name = "player_idle";
}

State_player_idle::State_player_idle(State_machine* state_machine) {
    name           = "player_idle";
    parent_machine = state_machine;
}

State_player_idle::~State_player_idle() {
}

void State_player_idle::on_keydown() {

    switch (Game_controler::event.key.keysym.sym) {
        case SDLK_w:
            parent_machine->transform->velocity.y = -3;
            parent_machine->set_active("player_jump");
            break;
        case SDLK_s:
            // parent_machine->transform->velocity.y = 1;
            // parent_machine->set_active("player_run");
            break;
        case SDLK_a:
            parent_machine->transform->velocity.x = -1;
            parent_machine->set_active("player_run");
            parent_machine->sprite->flip(true);
            break;
        case SDLK_d:
            parent_machine->transform->velocity.x = 1;
            parent_machine->set_active("player_run");
            parent_machine->sprite->flip(false);
            break;
        case SDLK_e:
            parent_machine->parent_entity->get_component<Shooter_component>()
                .shot();
            break;
        default:
            break;
    }
}

void State_player_idle::on_keyup() {
}

void State_player_idle::on_enable() {
    parent_machine->transform->velocity.x = 0;
    parent_machine->transform->velocity.y = 0;
    parent_machine->sprite->play("idle");

    const Uint8* keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_A]) {
        parent_machine->transform->velocity.x = -1;
        parent_machine->set_active("player_run");
    } else if (keys[SDL_SCANCODE_D]) {
        parent_machine->transform->velocity.x = 1;
        parent_machine->set_active("player_run");
    }
}

void State_player_idle::on_disable() {
}

void State_player_idle::update() {

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

void State_player_idle::late_update() {

    bool grav = true;

    for (auto& c : colliders) {
        SDL_Rect c_col = c->get_component<Collider_component>().collider;
        if (Collision::aabb_pt_left_high(parent_machine->rollback_collider,
                                         c_col) ||
            Collision::aabb_pt_left_low(parent_machine->rollback_collider,
                                        c_col) ||
            Collision::aabb_pt_right_high(parent_machine->rollback_collider,
                                          c_col) ||
            Collision::aabb_pt_right_low(parent_machine->rollback_collider,
                                         c_col)) {
            parent_machine->set_active("player_idle");
            parent_machine->transform->position =
                parent_machine->rollback_position;
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