#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "../Vector_2D.h"
#include "Components.h"

class Transform_component;
class State;

// extern std::vector<Entity*>& colliders;

class State_machine : public Component {

   private:
    std::vector<State*> states;

   public:
    State*               active;
    Vector_2D            rollback_position;
    SDL_Rect             rollback_collider;
    SDL_Rect             collider;
    Transform_component* transform;
    Sprite_component*    sprite;

    State_machine(std::string type);
    ~State_machine();

    void set_active(std::string name);

    void init() override;
    void quick_update() override;
    void update() override;
    void late_update() override;
};

#endif