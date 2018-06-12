#pragma once

#include <string>

class Turret_enemy_factory {

   public:
    static void create(double      transform_x,
                       double      transform_y,
                       double      transform_h,
                       double      transform_w,
                       double      transform_scale,
                       std::string sprite_path,
                       std::string collider_tag,
                       std::string bullet_sprite_path,
                       double      shot_cd);
};