#pragma once

#include "../EC/State_machine.h"
#include "States.h"

class State_machine;

class State_turret_idle : public State {

   private:
    Transform_component* player_trans;

   public:
    State_turret_idle();
    State_turret_idle(State_machine* sm);
    ~State_turret_idle();

    void on_enable() override;
    void update() override;
};