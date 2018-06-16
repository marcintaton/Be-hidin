#include "Door_factory.h"
#include "../EC/Components.h"

extern Entity_manager manager;

void Door_factory::create(double      transform_x,
                          double      transform_y,
                          double      transform_h,
                          double      transform_w,
                          double      transform_scale,
                          std::string sprite_file_path) {

    auto& door(manager.add_entity());

    door.add_component<Transform_component>(
        transform_x, transform_y, transform_h, transform_w, transform_scale);
    door.add_component<Sprite_component>(sprite_file_path.c_str());
    door.add_component<Collider_component>("door");
    door.add_component<Door_component>();

    door.add_group(Game_controler::g_map_binded);
    door.add_group(Game_controler::g_static_map_elems);
}