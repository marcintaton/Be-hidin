#pragma once

#include "../EC/State_machine.h"
#include "States.h"

class State_machine;

class State_player_climb_r : public State {

   private:
   public:
    State_player_climb_r();
    State_player_climb_r(State_machine* sm);
    ~State_player_climb_r();

    void on_keydown() override;
    void on_keyup() override;
    void on_enable() override;
    void on_disable() override;
    void update() override;
    void late_update() override;
};