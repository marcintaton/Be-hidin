#pragma once

#include "../EC/Components.h"

class Bonus;

class Freeze_bonus : public Bonus {

   private:
   public:
    Freeze_bonus(Bonus_controller* _ctrl);
    ~Freeze_bonus();

    void on_enable() override;
    void on_disable() override;
    void update() override;
};