#pragma once

#include "../EC/State_machine.h"
#include "States.h"

class State_machine;

class State_player_run : public State {

   private:
   public:
    State_player_run();
    State_player_run(State_machine* sm);
    ~State_player_run();

    void on_keydown() override;
    void on_keyup() override;
    void on_enable() override;
    void on_disable() override;
    void update() override;
    void late_update() override;
};