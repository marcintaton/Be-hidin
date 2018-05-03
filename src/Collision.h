#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>

class Collider_component;

class Collision {

   public:
    static bool aabb(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb(const Collider_component& col_a,
                     const Collider_component& col_b);
};

#endif