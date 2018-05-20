#ifndef GAME_CONTROLER_H
#define GAME_CONTROLER_H

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <vector>
#include "Helper_structs.h"
#include "SDL2/SDL_image.h"

class Collider_component;

class Game_controler {

   private:
    int                                               loop_cnt;
    bool                                              running;
    std::unique_ptr<SDL_Window, SDL_window_destroyer> window;

   public:
    Game_controler();

    ~Game_controler();

    void initialize(const char* title,
                    int         x_pos,
                    int         y_pos,
                    int         width,
                    int         height,
                    bool        fullscreen);
    void handle_events();
    void update();
    void render();
    void clear();
    bool is_running();

    static void addMapTile(int src_x, int src_y, int x, int y);

    static std::vector<Collider_component*> colliders;

    static std::unique_ptr<SDL_Renderer, SDL_renderer_destroyer> renderer;
    static SDL_Event                                             event;
};

#endif
