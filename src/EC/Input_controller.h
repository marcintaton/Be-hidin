#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include "../Game_controler.h"
#include "Components.h"
#include "EC.h"

class Transform_component;

class Input_controller : public Component {

   private:
   public:
    Transform_component* transform;

    Input_controller();

    void init() override;
    void update() override;
};

#endif