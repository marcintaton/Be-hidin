#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "EC/Transform_component.h"

class Transform_component;

class Camera {

   private:
    Transform_component*  player_trans;
    std::vector<Entity*>& tiles;
    int                   offset_x;
    int                   offset_y;

   public:
    Camera(Transform_component* _player_trans, std::vector<Entity*>& _tiles);
    ~Camera();

    void update();
};

#endif