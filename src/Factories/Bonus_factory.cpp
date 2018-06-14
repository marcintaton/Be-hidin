#include "Bonus_factory.h"
#include "../Bonuses/Bonuses.h"
#include "../EC/Components.h"

extern Entity_manager manager;

void Bonus_factory::create_speed_bonus(double      transform_x,
                                       double      transform_y,
                                       double      transform_h,
                                       double      transform_w,
                                       double      transform_scale,
                                       std::string sprite_path,
                                       std::string collider_tag) {

    auto& bonus(manager.add_entity());

    bonus.add_component<Transform_component>(
        transform_x, transform_y, transform_h, transform_w, transform_scale);
    bonus.add_component<Sprite_component>(sprite_path.c_str());
    bonus.add_component<Collider_component>("bonus");
    bonus.add_component<Bonus_component>();
    bonus.add_group(Game_controler::g_pickable);
    bonus.add_group(Game_controler::g_map_binded);
}