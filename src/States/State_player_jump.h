#pragma once

#include "../EC/State_machine.h"
#include "States.h"

class State_machine;

class State_player_jump : public State {

   private:
    int start_pos;

   public:
    State_player_jump();
    State_player_jump(State_machine* sm);
    ~State_player_jump();

    void on_keydown() override;
    void on_keyup() override;
    void on_enable() override;
    void on_disable() override;
    void update() override;
    void late_update() override;
};