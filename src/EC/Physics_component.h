#ifndef PHYSICS_COMPONENT_H
#define PHYSICS_COMPONENT_H

#include "../Collision.h"
#include "../Vector_2D.h"
#include "Components.h"

class Transform_component;

extern std::vector<Entity*>& colliders;

class Physics_component : public Component {

   private:
    Vector_2D rollback_position;
    SDL_Rect  rollback_collider;

   public:
    bool                 gravity;
    Transform_component* transform;

    Physics_component();
    ~Physics_component();

    void init() override;
    void quick_update() override;
    void update() override;
    void late_update() override;
};

#endif