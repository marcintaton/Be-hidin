#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>

class Collider_component;

class Collision {

   public:
    static bool aabb(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb(const Collider_component& col_a,
                     const Collider_component& col_b);

    static bool aabb_edge_bottom(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb_edge_bottom(const Collider_component& col_a,
                                 const Collider_component& col_b);

    static bool aabb_edge_right(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb_edge_right(const Collider_component& col_a,
                                const Collider_component& col_b);

    static bool aabb_edge_top(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb_edge_top(const Collider_component& col_a,
                              const Collider_component& col_b);

    static bool aabb_edge_left(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb_edge_left(const Collider_component& col_a,
                               const Collider_component& col_b);

    static bool aabb_pt_bottom(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb_pt_bottom(const Collider_component& col_a,
                               const Collider_component& col_b);

    static bool aabb_pt_top(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb_pt_top(const Collider_component& col_a,
                            const Collider_component& col_b);

    static bool aabb_pt_left_high(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb_pt_left_high(const Collider_component& col_a,
                                  const Collider_component& col_b);

    static bool aabb_pt_left_low(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb_pt_left_low(const Collider_component& col_a,
                                 const Collider_component& col_b);

    static bool aabb_pt_right_high(const SDL_Rect& rec_a,
                                   const SDL_Rect& rec_b);
    static bool aabb_pt_right_high(const Collider_component& col_a,
                                   const Collider_component& col_b);

    static bool aabb_pt_right_low(const SDL_Rect& rec_a, const SDL_Rect& rec_b);
    static bool aabb_pt_right_low(const Collider_component& col_a,
                                  const Collider_component& col_b);
};

#endif