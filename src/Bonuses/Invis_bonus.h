#pragma once

#include "../EC/Components.h"

class Bonus;

class Invis_bonus : public Bonus {

   private:
    const char* invis_tex_path  = "assets/animations/player_invis.png";
    const char* normal_tex_path = "assets/animations/player.png";

   public:
    Invis_bonus(Bonus_controller* _ctrl);
    ~Invis_bonus();

    void on_enable() override;
    void on_disable() override;
    void update() override;
};