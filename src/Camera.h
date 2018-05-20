#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "EC/Transform_component.h"

class Transform_component;

class Camera {

   private:
    Transform_component*  player_trans;
    std::vector<Entity*>& tiles;
    std::vector<Entity*>& colliders;
    int                   offset_x;
    int                   offset_y;
    int                   resolutiom_w;
    int                   resolutiom_h;

   public:
    Camera(Transform_component*  _player_trans,
           std::vector<Entity*>& _tiles,
           std::vector<Entity*>& _colliders,
           int                   _resolutiom_w,
           int                   _resolutiom_h);
    ~Camera();

    void update();
};

#endif