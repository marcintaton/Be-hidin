#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include <SDL2/SDL.h>
#include <string>
#include "Components.h"
#include "EC.h"

class Transform_component;

class Collider_component : public Component {

   private:
   public:
    SDL_Rect             collider;
    std::string          tag;
    Transform_component* transform;

    Collider_component(std::string tag);

    void init() override;
    void update() override;
};

#endif