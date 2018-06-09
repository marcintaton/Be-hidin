#include "Collision.h"
#include "EC/Collider_component.h"

bool Collision::aabb(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {

    return (rec_a.x + rec_a.w >= rec_b.x && rec_b.x + rec_b.w >= rec_a.x &&
            rec_a.y + rec_a.h >= rec_b.y && rec_b.y + rec_b.h >= rec_a.y);
}

bool Collision::aabb(const Collider_component& col_a,
                     const Collider_component& col_b) {

    return aabb(col_a.collider, col_b.collider);
}

bool Collision::aabb_edge_bottom(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    return (rec_a.x < rec_b.x + rec_b.w && rec_a.x + rec_a.w > rec_b.x &&
            rec_a.y < rec_b.y && rec_a.y + rec_a.h > rec_b.y);
}

bool Collision::aabb_edge_bottom(const Collider_component& col_a,
                                 const Collider_component& col_b) {

    return aabb_edge_bottom(col_a.collider, col_b.collider);
}

bool Collision::aabb_edge_right(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    return (rec_a.y < rec_b.y + rec_b.h && rec_a.y + rec_a.h > rec_b.y &&
            rec_a.x < rec_b.x && rec_a.x + rec_a.w > rec_b.x);
}

bool Collision::aabb_edge_right(const Collider_component& col_a,
                                const Collider_component& col_b) {

    return aabb_edge_right(col_a.collider, col_b.collider);
}

bool Collision::aabb_edge_top(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    return (rec_a.x < rec_b.x + rec_b.w && rec_a.x + rec_a.w > rec_b.x &&
            rec_a.y > rec_b.y && rec_a.y < rec_b.y + rec_b.h);
}

bool Collision::aabb_edge_top(const Collider_component& col_a,
                              const Collider_component& col_b) {

    return aabb_edge_top(col_a.collider, col_b.collider);
}

bool Collision::aabb_edge_left(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    return (rec_a.y < rec_b.y + rec_b.h && rec_a.y + rec_a.h > rec_b.y &&
            rec_a.x < rec_b.x + rec_b.w && rec_a.x > rec_b.x);
}

bool Collision::aabb_edge_left(const Collider_component& col_a,
                               const Collider_component& col_b) {

    return aabb_edge_left(col_a.collider, col_b.collider);
}

bool Collision::aabb_pt_bottom(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    return (rec_a.x + rec_a.w / 2 >= rec_b.x &&
            rec_a.x + rec_a.w / 2 <= rec_b.x + rec_b.w &&
            rec_a.y + rec_a.h >= rec_b.y &&
            rec_a.y + rec_a.h <= rec_b.y + rec_b.h);
}

bool Collision::aabb_pt_bottom(const Collider_component& col_a,
                               const Collider_component& col_b) {

    return aabb_pt_bottom(col_a.collider, col_b.collider);
}

bool Collision::aabb_pt_top(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    return (rec_a.x + rec_a.w / 2 >= rec_b.x &&
            rec_a.x + rec_a.w / 2 <= rec_b.x + rec_b.w && rec_a.y >= rec_b.y &&
            rec_a.y <= rec_b.y + rec_b.h);
}

bool Collision::aabb_pt_top(const Collider_component& col_a,
                            const Collider_component& col_b) {

    return aabb_pt_top(col_a.collider, col_b.collider);
}

bool Collision::aabb_pt_left_high(const SDL_Rect& rec_a,
                                  const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    return (rec_a.x >= rec_b.x && rec_a.x <= rec_b.x + rec_b.w &&
            rec_a.y + rec_a.h * (1 / 3) >= rec_b.y &&
            rec_a.y + rec_a.h * (1 / 3) <= rec_b.y + rec_b.h);
}

bool Collision::aabb_pt_left_high(const Collider_component& col_a,
                                  const Collider_component& col_b) {

    return aabb_pt_left_high(col_a.collider, col_b.collider);
}

bool Collision::aabb_pt_left_low(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    return (rec_a.x >= rec_b.x && rec_a.x <= rec_b.x + rec_b.w &&
            rec_a.y + rec_a.h * (2 / 3) >= rec_b.y &&
            rec_a.y + rec_a.h * (2 / 3) <= rec_b.y + rec_b.h);
}

bool Collision::aabb_pt_left_low(const Collider_component& col_a,
                                 const Collider_component& col_b) {

    return aabb_pt_left_low(col_a.collider, col_b.collider);
}

bool Collision::aabb_pt_right_high(const SDL_Rect& rec_a,
                                   const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    return (rec_a.x + rec_a.w >= rec_b.x &&
            rec_a.x + rec_a.w <= rec_b.x + rec_b.w &&
            rec_a.y + rec_a.h * (1 / 3) >= rec_b.y &&
            rec_a.y + rec_a.h * (1 / 3) <= rec_b.y + rec_b.h);
}

bool Collision::aabb_pt_right_high(const Collider_component& col_a,
                                   const Collider_component& col_b) {

    return aabb_pt_right_high(col_a.collider, col_b.collider);
}

bool Collision::aabb_pt_right_low(const SDL_Rect& rec_a,
                                  const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    return (rec_a.x + rec_a.w >= rec_b.x &&
            rec_a.x + rec_a.w <= rec_b.x + rec_b.w &&
            rec_a.y + rec_a.h * (2 / 3) >= rec_b.y &&
            rec_a.y + rec_a.h * (2 / 3) <= rec_b.y + rec_b.h);
}

bool Collision::aabb_pt_right_low(const Collider_component& col_a,
                                  const Collider_component& col_b) {

    return aabb_pt_right_low(col_a.collider, col_b.collider);
}
