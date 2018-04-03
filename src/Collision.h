#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>

class Collision {

   public:
    static bool aabb(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
};

#endif