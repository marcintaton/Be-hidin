#include "Input_controller.h"

Input_controller::Input_controller() {
}

void Input_controller::init() {
    transform = &parent_entity->get_component<Transform_component>();
    sprite    = &parent_entity->get_component<Sprite_component>();
}

void Input_controller::update() {

    if (Game_controler::event.type == SDL_KEYDOWN) {
        switch (Game_controler::event.key.keysym.sym) {
            case SDLK_w:
                if (transform->velocity.y == 0) {
                    transform->velocity.y = -5;
                }
                break;
            case SDLK_s:
                // transform->velocity.y = 1;
                break;
            case SDLK_a:
                transform->velocity.x = -1;
                sprite->play("run");
                if (sprite->sprite_flip != SDL_FLIP_HORIZONTAL) {
                    sprite->sprite_flip = SDL_FLIP_HORIZONTAL;
                }
                break;
            case SDLK_d:
                transform->velocity.x = 1;
                sprite->play("run");
                if (sprite->sprite_flip == SDL_FLIP_HORIZONTAL) {
                    sprite->sprite_flip = SDL_FLIP_NONE;
                }
                break;
            default:
                break;
        }
    }

    if (Game_controler::event.type == SDL_KEYUP) {
        switch (Game_controler::event.key.keysym.sym) {
            case SDLK_w:
                sprite->play("idle");
                break;
            case SDLK_s:
                sprite->play("idle");
                break;
            case SDLK_a:
                transform->velocity.x = 0;
                sprite->play("idle");
                break;
            case SDLK_d:
                transform->velocity.x = 0;
                sprite->play("idle");
                break;
            default:
                break;
        }
    }
}