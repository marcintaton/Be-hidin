#ifndef HELPER_STRUCTS_H
#define HELPER_STRUCTS_H

#include <SDL2/SDL.h>

#include <iostream>
#include "SDL2/SDL_image.h"

struct SDL_window_destroyer {
    void operator()(SDL_Window* w) const {
        SDL_DestroyWindow(w);
    }
};

struct SDL_renderer_destroyer {
    void operator()(SDL_Renderer* r) const {
        SDL_DestroyRenderer(r);
    }
};

#endif