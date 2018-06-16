#include "Projectile_factory.h"
#include <SDL2/SDL.h>

extern Entity_manager manager;

void Projectile_factory::create(Vector_2D   caster,
                                Vector_2D   dst,
                                std::string tex_path) {

    auto& projectile(manager.add_entity());

    projectile.add_component<Transform_component>(caster.x, caster.y, 32, 32,
                                                  0.3);

    projectile.get_component<Transform_component>().velocity =
        Vector_2D(dst.x - caster.x, dst.y - caster.y).normalize();
    projectile.add_component<Sprite_component>(tex_path.c_str());
    projectile.add_component<Collider_component>("Projectile");
    projectile.add_component<Projectile_component>();
    projectile.add_group(Game_controler::g_projectiles);
    projectile.add_group(Game_controler::g_map_binded);
}