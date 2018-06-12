#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "../EC/Transform_component.h"

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
    static Camera*        instance;

    Camera(Transform_component*  _player_trans,
           std::vector<Entity*>& _tiles,
           std::vector<Entity*>& _colliders,
           int                   _resolutiom_w,
           int                   _resolutiom_h);

   public:
    ~Camera();

    static Camera* Get_instance();
    static void    Create_instance(Transform_component*  _player_trans,
                                   std::vector<Entity*>& _tiles,
                                   std::vector<Entity*>& _colliders,
                                   int                   _resolutiom_w,
                                   int                   _resolutiom_h);
    void           update();
};

#endif