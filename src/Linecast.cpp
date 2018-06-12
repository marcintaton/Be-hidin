#include "Linecast.h"
#include <algorithm>
#include <vector>
#include "Collision.h"
#include "EC/Components.h"

extern std::vector<Entity*>& colliders;

bool Linecast::linecast(Vector_2D a, Vector_2D b) {

    bool ret = false;

    for (auto& c : colliders) {

        SDL_Rect col = c->get_component<Collider_component>().collider;
        SDL_Rect suspected_area;
        suspected_area.x = std::min(a.x, b.x);
        suspected_area.y = std::min(a.y, b.y);
        suspected_area.w = std::abs(a.x - b.x);
        suspected_area.h = std::abs(a.y - b.y);

        if (Collision::aabb(col, suspected_area)) {
            double func_a = (a.y - b.y) / (a.x - b.x);
            double func_b = -1 * a.x * func_a + a.y;

            double pr_x1 = func_a * col.x + func_b;
            double pr_y1 = (col.y - func_b) / func_a;

            double pr_x2 = func_a * (col.x + col.w) + func_b;
            double pr_y2 = (col.y + col.h - func_b) / func_a;

            if ((pr_x1 > col.y && pr_x1 < col.y + col.h) ||
                (pr_y1 > col.x && pr_y1 < col.x + col.w) ||
                (pr_x2 > col.y && pr_x2 < col.y + col.h) ||
                (pr_y2 > col.x && pr_y2 < col.x + col.w)) {
                ret = true;
            }
        }
    }

    return ret;
}
