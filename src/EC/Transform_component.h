#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "../Vector_2D.h"
#include "Components.h"

class Transform_component : public Component {

   private:
   public:
    Vector_2D position;
    Vector_2D velocity;

    int speed = 3;

    int width  = 32;
    int height = 32;
    int scale  = 1;

    Transform_component();
    Transform_component(double x, double y);
    Transform_component(double x, double y, int height, int width, int scale);

    void init() override;
    void update() override;
    void draw() override;
};

#endif