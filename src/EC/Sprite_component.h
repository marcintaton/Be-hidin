#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include <SDL2/SDL.h>
#include <map>
#include "Animation.h"
#include "Components.h"
#include "SDL2/SDL_image.h"

class Transform_component;

class Sprite_component : public Component {

   private:
    Transform_component* transform;
    SDL_Texture*         texture;
    SDL_Rect             src;
    SDL_Rect             dst;
    bool                 animated = false;

   public:
    int                              anim_frames;
    int                              anim_index = 0;
    int                              anim_delay;
    std::map<std::string, Animation> animations;

    SDL_RendererFlip sprite_flip = SDL_FLIP_NONE;

    Sprite_component() = default;
    Sprite_component(const char* tex_path);
    Sprite_component(const char* tex_path, bool _animated);
    ~Sprite_component();

    void set_texture(const char* tex_path);
    void init() override;
    void update() override;
    void draw() override;

    void play(std::string amin_name);
    void flip(bool flip);
};

#endif