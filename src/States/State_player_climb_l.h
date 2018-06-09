#pragma once

#include "../EC/State_machine.h"
#include "States.h"

class State_machine;

class State_player_climb_l : public State {

   private:
   public:
    State_player_climb_l();
    State_player_climb_l(State_machine* sm);
    ~State_player_climb_l();

    void on_keydown() override;
    void on_keyup() override;
    void on_enable() override;
    void on_disable() override;
    void update() override;
    void late_update() override;
};