#include "Shooter_component.h"
#include "../Singletons/Player.h"
#include "../Vector_2D.h"

Shooter_component::Shooter_component() {
}

Shooter_component::Shooter_component(double cooldown, std::string path) {
    tex_path  = path;
    shoot_cd  = cooldown * 1000;
    last_shot = 0;
}

Shooter_component::~Shooter_component() {
}

void Shooter_component::shot() {

    if (SDL_GetTicks() > (last_shot + shoot_cd)) {
        last_shot = SDL_GetTicks();

        Projectile_factory::create(
            parent_entity->get_component<Transform_component>().position,
            Player::Get_instance()
                ->get_component<Transform_component>()
                .position,
            tex_path.c_str());
    }
}

void Shooter_component::update() {
}
