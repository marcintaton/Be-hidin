#include "Turret_enemy_factory.h"
#include "../EC/Components.h"

extern Entity_manager manager;

void Turret_enemy_factory::create(double      transform_x,
                                  double      transform_y,
                                  double      transform_h,
                                  double      transform_w,
                                  double      transform_scale,
                                  std::string sprite_path,
                                  std::string collider_tag,
                                  std::string bullet_sprite_path,
                                  double      shot_cd) {

    auto& turret(manager.add_entity());

    turret.add_component<Transform_component>(
        transform_x, transform_y, transform_h, transform_w, transform_scale);
    turret.add_component<Sprite_component>(sprite_path.c_str());
    turret.add_component<Collider_component>("enemy");
    turret.add_component<State_machine>("enemy_turret");
    turret.add_component<Shooter_component>(shot_cd, bullet_sprite_path);
    turret.add_group(Game_controler::g_enemies);
}