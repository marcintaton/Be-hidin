#include "Inventory_component.h"

Inventory_component::Inventory_component() {
}

Inventory_component::~Inventory_component() {
}

void Inventory_component::add_item(Item* _item) {
    inventory.push_back(_item);
}