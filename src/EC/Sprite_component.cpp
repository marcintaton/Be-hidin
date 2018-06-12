#include "Sprite_component.h"
#include "../Texture_manager.h"

Sprite_component::Sprite_component(const char* tex_path) {
    set_texture(tex_path);
}

Sprite_component::Sprite_component(const char* tex_path, bool _animated) {

    animated             = _animated;
    Animation idle       = Animation(0, 4, 100);
    Animation run        = Animation(1, 6, 100);
    Animation jump       = Animation(2, 2, 100);
    Animation climb      = Animation(3, 2, 100);
    Animation climb_idle = Animation(3, 1, 100);

    animations.emplace("idle", idle);
    animations.emplace("run", run);
    animations.emplace("jump", jump);
    animations.emplace("climb", climb);
    animations.emplace("climb_idle", climb_idle);

    play("idle");

    set_texture(tex_path);
}

Sprite_component::~Sprite_component() {
    SDL_DestroyTexture(texture);
}

void Sprite_component::set_texture(const char* tex_path) {
    texture = Texture_manager::load_texture(tex_path);
}

void Sprite_component::init() {

    if (!parent_entity->has_component<Transform_component>()) {
        parent_entity->add_component<Transform_component>();
    }
    transform = &parent_entity->get_component<Transform_component>();

    src.x = 0;
    src.y = 0;
    src.h = transform->height;
    src.w = transform->width;
}

void Sprite_component::update() {

    if (animated) {
        src.x = src.w *
                static_cast<int>((SDL_GetTicks() / anim_delay) % anim_frames);
    }

    src.y = anim_index * transform->height;

    dst.x = static_cast<int>(transform->position.x);
    dst.y = static_cast<int>(transform->position.y);
    dst.h = transform->height * transform->scale;
    dst.w = transform->width * transform->scale;
}

void Sprite_component::draw() {

    Texture_manager::draw(texture, src, dst, sprite_flip);
}

void Sprite_component::play(std::string anim_name) {
    anim_frames = animations[anim_name].frame_num;
    anim_index  = animations[anim_name].index;
    anim_delay  = animations[anim_name].animation_delay;
}

void Sprite_component::flip(bool flip) {
    if (flip) {
        sprite_flip = SDL_FLIP_HORIZONTAL;
    } else {
        sprite_flip = SDL_FLIP_NONE;
    }
}

void Sprite_component::set_src_rect(int x, int y) {
    src.x = x;
    src.y = y;
}