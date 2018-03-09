#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Game_controler.h"

class Game_object {

   private:
    int                                                 x_pos;
    int                                                 y_pos;
    std::unique_ptr<SDL_Texture, SDL_texture_destroyer> texture;
    SDL_Rect                                            src_rect;
    SDL_Rect                                            dst_rect;

   public:
    Game_object(const char* texture_file, int init_x, int init_y);
    ~Game_object();

    void update();
    void render();
};

#endif