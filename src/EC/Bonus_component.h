#pragma once

#include "Components.h"
#include "EC.h"

class Bonus_component : public Component {

   private:
   public:
    Bonus_component();
    ~Bonus_component();

    void update() override;
};