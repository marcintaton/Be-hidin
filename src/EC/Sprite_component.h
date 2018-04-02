#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include <SDL2/SDL.h>
#include "Components.h"
#include "SDL2/SDL_image.h"

class Transform_component;

class Sprite_component : public Component {

   private:
    Transform_component* transform;
    SDL_Texture*         texture;
    SDL_Rect             src;
    SDL_Rect             dst;

   public:
    Sprite_component() = default;
    Sprite_component(const char* tex_path);
    ~Sprite_component();

    void set_texture(const char* tex_path);
    void init() override;
    void update() override;
    void draw() override;
};

#endif