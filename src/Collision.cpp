#include "Collision.h"
#include "EC/Collider_component.h"

bool Collision::aabb(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {

    if (rec_a.x + rec_a.w > rec_b.x && rec_b.x + rec_b.w > rec_a.x &&
        rec_a.y + rec_a.h > rec_b.y && rec_b.y + rec_b.h > rec_a.y) {

        return true;
    } else {
        return false;
    }
}

bool Collision::aabb(const Collider_component& col_a,
                     const Collider_component& col_b) {

    if (aabb(col_a.collider, col_b.collider)) {
        return true;
    } else {
        return false;
    }
}

bool Collision::aabb_low_edge(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    if (rec_a.x <= rec_b.x + rec_b.w && rec_a.x + rec_a.w >= rec_b.x &&
        rec_a.y <= rec_b.y && rec_a.y + rec_a.h >= rec_b.y) {

        return true;
    } else {
        return false;
    }
}

bool Collision::aabb_low_edge(const Collider_component& col_a,
                              const Collider_component& col_b) {

    if (aabb_low_edge(col_a.collider, col_b.collider)) {
        return true;
    } else {
        return false;
    }
}

bool Collision::aabb_right_edge(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    if (rec_a.y <= rec_b.y + rec_b.h && rec_a.y + rec_a.h >= rec_b.y &&
        rec_a.x <= rec_b.x && rec_a.x + rec_a.w >= rec_b.x) {

        return true;
    } else {
        return false;
    }
}

bool Collision::aabb_right_edge(const Collider_component& col_a,
                                const Collider_component& col_b) {

    if (aabb_right_edge(col_a.collider, col_b.collider)) {
        return true;
    } else {
        return false;
    }
}

bool Collision::aabb_top_edge(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    if (rec_a.x <= rec_b.x + rec_b.w && rec_a.x + rec_a.w >= rec_b.x &&
        rec_a.y >= rec_b.y && rec_a.y <= rec_b.y + rec_b.h) {

        return true;
    } else {
        return false;
    }
}

bool Collision::aabb_top_edge(const Collider_component& col_a,
                              const Collider_component& col_b) {

    if (aabb_top_edge(col_a.collider, col_b.collider)) {
        return true;
    } else {
        return false;
    }
}

bool Collision::aabb_left_edge(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {
    // rec_a - main collider : low edge collision detected on this
    // rec_b - secondary collider : low edge collision detected against this
    if (rec_a.y <= rec_b.y + rec_b.h && rec_a.y + rec_a.h >= rec_b.y &&
        rec_a.x <= rec_b.x + rec_b.w && rec_a.x >= rec_b.x) {

        return true;
    } else {
        return false;
    }
}

bool Collision::aabb_left_edge(const Collider_component& col_a,
                               const Collider_component& col_b) {

    if (aabb_left_edge(col_a.collider, col_b.collider)) {
        return true;
    } else {
        return false;
    }
}