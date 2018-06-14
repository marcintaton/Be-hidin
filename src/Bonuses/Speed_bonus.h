#pragma once

#include "../EC/Components.h"

class Bonus;

class Speed_bonus : public Bonus {

   private:
   public:
    Speed_bonus(Bonus_controller* _ctrl);
    ~Speed_bonus();

    void on_enable() override;
    void on_disable() override;
    void update() override;
};