#pragma once

#include <vector>

#include <string>

class Bonus_factory {

   public:
    static void create_speed_bonus(double      transform_x,
                                   double      transform_y,
                                   double      transform_h,
                                   double      transform_w,
                                   double      transform_scale,
                                   std::string sprite_path,
                                   std::string collider_tag);
};