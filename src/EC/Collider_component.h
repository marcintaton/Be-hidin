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

    SDL_Texture* coll_tex;
    SDL_Rect     src;
    SDL_Rect     dst;

    Collider_component(std::string _tag);
    Collider_component(std::string _tag, int pos_x, int pos_y, int size);

    void init() override;
    void update() override;
    void draw() override;
};

#endif