#include "Item_factory.h"
#include "../EC/Components.h"

extern Entity_manager manager;

void Item_factory::create(double      transform_x,
                          double      transform_y,
                          double      transform_h,
                          double      transform_w,
                          double      transform_scale,
                          std::string sprite_file_path,
                          int         id,
                          bool        quest_item) {

    auto& item(manager.add_entity());

    item.add_component<Transform_component>(
        transform_x, transform_y, transform_h, transform_w, transform_scale);
    item.add_component<Sprite_component>(sprite_file_path.c_str());
    item.add_component<Collider_component>("item");
    item.add_component<Item_component>(new Item(id, quest_item));

    item.add_group(Game_controler::g_map_binded);
    item.add_group(Game_controler::g_pickable);
}