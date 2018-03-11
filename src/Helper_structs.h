#ifndef HELPER_STRUCTS_H
#define HELPER_STRUCTS_H

#include <SDL2/SDL.h>

#include <iostream>
#include "SDL2/SDL_image.h"
#include "tmx.h"

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

struct SDL_surface_destroyer {
    void operator()(SDL_Surface* s) const {
        SDL_FreeSurface(s);
    }
};

struct SDL_texture_destroyer {
    void operator()(SDL_Texture* t) const {
        SDL_DestroyTexture(t);
    }
};

#endif