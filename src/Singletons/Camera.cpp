#include "Camera.h"

Camera* Camera::instance = nullptr;

Camera::Camera(Transform_component*  _player_trans,
               std::vector<Entity*>& _tiles,
               std::vector<Entity*>& _colliders,
               std::vector<Entity*>& _map_objects,
               int                   _resolutiom_w,
               int                   _resolutiom_h)
    : tiles(_tiles), colliders(_colliders), map_objects(_map_objects) {

    player_trans = _player_trans;

    offset_x = 0;
    offset_y = 0;

    resolutiom_w = _resolutiom_w;
    resolutiom_h = _resolutiom_h;
}

Camera::~Camera() {
}

void Camera::Create_instance(Transform_component*  _player_trans,
                             std::vector<Entity*>& _tiles,
                             std::vector<Entity*>& _colliders,
                             std::vector<Entity*>& _map_objects,
                             int                   _resolutiom_w,
                             int                   _resolutiom_h) {
    if (Camera::instance == nullptr) {
        Camera::instance =
            new Camera(_player_trans, _tiles, _colliders, _map_objects,
                       _resolutiom_w, _resolutiom_h);
    }
}

Camera* Camera::Get_instance() {
    return Camera::instance;
}

void Camera::update() {

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
        for (auto& c : colliders) {
            if (c->has_component<Collider_component>()) {
                c->get_component<Collider_component>().collider.x += offset_x;
                c->get_component<Collider_component>().dst.x += offset_x;
                c->get_component<Collider_component>().collider.y += offset_y;
                c->get_component<Collider_component>().dst.y += offset_y;
            }
        }
        for (auto& m : map_objects) {
            if (m->has_component<Transform_component>()) {
                m->get_component<Transform_component>().position.x += offset_x;
                m->get_component<Transform_component>().position.y += offset_y;
            }
        }
        offset_x = 0;
        offset_y = 0;
    }
}