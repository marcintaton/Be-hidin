#include "Collision.h"

bool Collision::aabb(const SDL_Rect& rec_a, const SDL_Rect& rec_b) {

    if (rec_a.x + rec_a.w >= rec_b.x && rec_b.x + rec_b.w >= rec_a.x &&
        rec_a.y + rec_a.h >= rec_b.y && rec_b.y + rec_b.h >= rec_a.y) {

        return true;
    } else {
        return false;
    }
}