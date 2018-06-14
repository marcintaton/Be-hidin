#pragma once

#include "../Bonuses/Bonuses.h"
#include "Components.h"
#include "EC.h"

class Bonus;

class Bonus_controller : public Component {

   private:
    Bonus* bonus;

   public:
    Bonus_controller();
    ~Bonus_controller();

    void update() override;
    void add_bonus(Bonus* _bonus);
};