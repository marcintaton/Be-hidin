#include "Camera.h"

Camera::Camera(Transform_component*  _player_trans,
               std::vector<Entity*>& _tiles,
               int                   _resolutiom_w,
               int                   _resolutiom_h)
    : tiles(_tiles) {

    player_trans = _player_trans;
    // tiles        = _tiles;

    offset_x = 0;
    offset_y = 0;

    resolutiom_w = _resolutiom_w;
    resolutiom_h = _resolutiom_h;
}

Camera::~Camera() {
}

void Camera::update() {
    // std::cout << player_trans->position.x << " " << player_trans->position.y
    //           << std::endl;

    if (player_trans->position.x > resolutiom_w) {
        player_trans->position.x = 0;
        offset_x                 = -resolutiom_w;
    } else if (player_trans->position.x < 0) {
        player_trans->position.x = resolutiom_w;
        offset_x                 = resolutiom_w;
    }

    if (player_trans->position.y > resolutiom_h) {
        player_trans->position.y = 0;
        offset_y                 = -resolutiom_h;
    } else if (player_trans->position.y < 0) {
        player_trans->position.y = resolutiom_h;
        offset_y                 = resolutiom_h;
    }

    if (offset_x != 0 || offset_y != 0) {
        for (auto& t : tiles) {
            if (t->has_component<Tile_component>()) {
                t->get_component<Tile_component>().dst.x += offset_x;
                t->get_component<Tile_component>().dst.y += offset_y;
            }
        }
        offset_x = 0;
        offset_y = 0;
    }
}