#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "EC.h"

class Position_component : public Component {

   private:
    int x_pos;
    int y_pos;

   public:
    int  get_x();
    int  get_y();
    void set_x(int x);
    void set_y(int y);

    void init() override;
    void update() override;
    void draw() override;
};

#endif