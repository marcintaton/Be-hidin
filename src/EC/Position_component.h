#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include "Components.h"

class Position_component : public Component {

   private:
    int x_pos;
    int y_pos;

   public:
    Position_component();
    Position_component(int x, int y);

    int  get_x();
    int  get_y();
    void set_x(int x);
    void set_y(int y);

    void init() override;
    void update() override;
    void draw() override;
};

#endif