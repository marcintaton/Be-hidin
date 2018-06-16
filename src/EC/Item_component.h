#pragma once

#include "Components.h"

class Item_component : public Component {

   public:
    Item* item;

    Item_component();
    Item_component(Item* _item);
    ~Item_component();

    void update() override;
};