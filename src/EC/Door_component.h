#pragma once

#include "Components.h"

class Door_component : public Component {

   private:
   public:
    Door_component();
    ~Door_component();

    void update() override;
};