#include "State_player_jump.h"
#include <iostream>
#include "../Collision.h"

extern std::vector<Entity*>& colliders;

State_player_jump::State_player_jump() {
    name = "player_jump";
}

State_player_jump::State_player_jump(State_machine* state_machine) {
    name           = "player_jump";
    parent_machine = state_machine;
}

State_player_jump::~State_player_jump() {
}

void State_player_jump::on_keydown() {
    switch (Game_controler::event.key.keysym.sym) {
        case SDLK_w:

            break;
        case SDLK_s:

            break;
        case SDLK_a:
            parent_machine->transform->velocity.x = -1;
            parent_machine->sprite->flip(true);
            break;
        case SDLK_d:
            parent_machine->transform->velocity.x = 1;
            parent_machine->sprite->flip(false);
            break;
        default:
            break;
    }
}

void State_player_jump::on_keyup() {
    switch (Game_controler::event.key.keysym.sym) {
        case SDLK_w:
            break;
        case SDLK_s:
            break;
        case SDLK_a:
            parent_machine->transform->velocity.x = 0;
            break;
        case SDLK_d:
            parent_machine->transform->velocity.x = 0;
            break;
        default:
            break;
    }
}

void State_player_jump::on_enable() {
    parent_machine->sprite->play("jump");
}

void State_player_jump::on_disable() {
}

void State_player_jump::update() {

    if (parent_machine->transform->velocity.y < 2) {
        parent_machine->transform->velocity.y += 0.1;
    } else {
        parent_machine->transform->velocity.y = 2;
    }

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

void State_player_jump::late_update() {

    for (auto& c : colliders) {
        SDL_Rect c_col = c->get_component<Collider_component>().collider;
        if (Collision::aabb_edge_bottom(parent_machine->rollback_collider,
                                        c_col)) {
            parent_machine->set_active("player_idle");
        }

        if (Collision::aabb_pt_right_high(parent_machine->rollback_collider,
                                          c_col) &&
            Collision::aabb_pt_right_low(parent_machine->rollback_collider,
                                         c_col)) {
            parent_machine->set_active("player_climb_r");
        }

        if (Collision::aabb_pt_left_high(parent_machine->rollback_collider,
                                         c_col) &&
            Collision::aabb_pt_left_low(parent_machine->rollback_collider,
                                        c_col)) {
            parent_machine->set_active("player_climb_l");
        }

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