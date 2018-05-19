#include "Animation_component.h"
#include "../Texture_dataclass.h"

Animation_component::Animation_component(int _frame_num, int _animation_delay) {
    frame_num       = _frame_num;
    animation_delay = _animation_delay;
}

Animation_component::~Animation_component() {
}

void Animation_component::init() {
    if (!parent_entity->has_component<Sprite_component>()) {
        parent_entity->add_component<Sprite_component>();
    }
    sprite = &parent_entity->get_component<Sprite_component>();

    animate   = true;
    state_tag = "player_idle";
}

void Animation_component::update() {

    if (animate == true) {
        sprite->set_texture(Texture_dataclass::return_path(
            state_tag,
            static_cast<int>((SDL_GetTicks() / animation_delay) % frame_num)));
    }
}

void Animation_component::draw() {
}

void Animation_component::set_state_tag(std::string tag) {

    state_tag = tag;
}