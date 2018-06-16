#include "Item_component.h"

#include "../Collision.h"
#include "../Singletons/Player.h"

Item_component::Item_component() {
}

Item_component::Item_component(Item* _item) {
    item = _item;
}

Item_component::~Item_component() {
}

void Item_component::update() {

    if (Collision::aabb(
            parent_entity->get_component<Collider_component>().collider,
            Player::Get_instance()
                ->get_component<Collider_component>()
                .collider)) {
        Player::Get_instance()->get_component<Inventory_component>().add_item(
            item);
        parent_entity->set_inactive();
    }
}