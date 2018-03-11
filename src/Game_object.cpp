#include "Game_object.h"

#include "Texture_manager.h"

int x_change = 1;
int y_change = 1;

Game_object::Game_object(const char* texture_file, int init_x, int init_y) {

    texture = Texture_manager::load_texture(texture_file);
    x_pos   = init_x;
    y_pos   = init_y;
}

Game_object::~Game_object() {
}

void Game_object::update() {

    if (x_pos > 720 || x_pos < 0) {
        x_change *= -1;
    }
    if (y_pos > 560 || y_pos < 0) {
        y_change *= -1;
    }

    x_pos += x_change;
    y_pos += y_change;

    src_rect.h = 64;
    src_rect.w = 64;
    src_rect.x = 0;
    src_rect.y = 0;

    dst_rect.h = src_rect.h;
    dst_rect.w = src_rect.w;
    dst_rect.x = x_pos;
    dst_rect.y = y_pos;
}

void Game_object::render() {

    if (x_change == 1) {
        SDL_RenderCopy(Game_controler::renderer.get(), texture.get(), &src_rect,
                       &dst_rect);
    } else {
        SDL_RenderCopyEx(Game_controler::renderer.get(), texture.get(),
                         &src_rect, &dst_rect, 0, NULL, SDL_FLIP_HORIZONTAL);
    }
}