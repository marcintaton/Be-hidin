#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include <SDL2/SDL.h>
#include "Components.h"
#include "SDL2/SDL_image.h"

class Position_component;

class Sprite_component : public Component {

   private:
    Position_component* position;
    SDL_Texture*        texture;
    SDL_Rect            src;
    SDL_Rect            dst;

   public:
    Sprite_component();
    Sprite_component(const char* tex_path);
    ~Sprite_component();

    void init() override;
    void update() override;
    void draw() override;
};

#endif