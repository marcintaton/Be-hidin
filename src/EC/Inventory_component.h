#pragma once

#include <list>
#include "../Inventory/Item.h"
#include "Components.h"

class Inventory_component : public Component {

   private:
   public:
    std::list<Item*> inventory;

    Inventory_component();
    ~Inventory_component();

    void add_item(Item* _item);
};