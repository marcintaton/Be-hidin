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
    std::unique_ptr<SDL_Window, SDL_window_destroyer> window;
    int                                               w;
    int                                               h;

   public:
    static bool running;
    bool        quit = false;

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

    static void lvl_clear();

    void create_lvl_1();
    void create_lvl_2();

    enum grup_tags : std::size_t {
        g_map,
        g_players,
        g_enemies,
        g_colliders,
        g_map_binded,
        g_projectiles,
        g_pickable,
        g_static_map_elems
    };

    static std::unique_ptr<SDL_Renderer, SDL_renderer_destroyer> renderer;
    static SDL_Event                                             event;
};

#endif
