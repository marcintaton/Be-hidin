#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "../Vector_2D.h"
#include "Components.h"

class Transform_component : public Component {

   private:
   public:
    Vector_2D position;
    Transform_component();
    Transform_component(double x, double y);

    void init() override;
    void update() override;
    void draw() override;
};

#endif