#include "Camera.h"

Camera::Camera(Transform_component* _player_trans, std::vector<Entity*>& _tiles)
    : tiles(_tiles) {

    player_trans = _player_trans;
    // tiles        = _tiles;

    offset_x = 0;
    offset_y = 0;
}

Camera::~Camera() {
}

void Camera::update() {
    // std::cout << player_trans->position.x << " " << player_trans->position.y
    //           << std::endl;

    if (player_trans->position.x > 800) {
        player_trans->position.x = 0;
        offset_x                 = -25 * 32;
    } else if (player_trans->position.x < 0) {
        player_trans->position.x = 800;
        offset_x                 = 25 * 32;
    }

    if (player_trans->position.y > 640) {
        player_trans->position.y = 0;
        offset_y                 = -20 * 32;
    } else if (player_trans->position.y < 0) {
        player_trans->position.y = 640;
        offset_y                 = 20 * 32;
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