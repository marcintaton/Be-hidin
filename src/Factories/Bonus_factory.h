#pragma once

#include <functional>
#include <string>
#include <vector>
#include "../EC/EC.h"

class Bonus_factory {

   private:
    static std::function<void()> create_speed;
    static std::function<void()> create_invis;
    static std::function<void()> create_freeze;

    static Entity& add_components(double      transform_x,
                                  double      transform_y,
                                  double      transform_h,
                                  double      transform_w,
                                  double      transform_scale,
                                  std::string sprite_path,
                                  std::string collider_tag);

   public:
    static void create_speed_bonus(double      transform_x,
                                   double      transform_y,
                                   double      transform_h,
                                   double      transform_w,
                                   double      transform_scale,
                                   std::string sprite_path,
                                   std::string collider_tag);

    static void create_invis_bonus(double      transform_x,
                                   double      transform_y,
                                   double      transform_h,
                                   double      transform_w,
                                   double      transform_scale,
                                   std::string sprite_path,
                                   std::string collider_tag);

    static void create_freeze_bonus(double      transform_x,
                                    double      transform_y,
                                    double      transform_h,
                                    double      transform_w,
                                    double      transform_scale,
                                    std::string sprite_path,
                                    std::string collider_tag);
};