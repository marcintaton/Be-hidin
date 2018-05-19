#ifndef ANIMATION_COMPONENT_H
#define ANIMATION_COMPONENT_H

#include "Components.h"
#include "EC.h"
#include "Sprite_component.h"

class Sprite_component;

class Animation_component : public Component {

   private:
    Sprite_component* sprite;
    int               frame_num;
    int               animation_delay;
    bool              animate = false;
    std::string       state_tag;

   public:
    // Animation_component() = default;
    Animation_component(int _frame_num, int _animation_speed);
    ~Animation_component();

    void init() override;
    void update() override;
    void draw() override;

    void set_state_tag(std::string tag);
};

#endif