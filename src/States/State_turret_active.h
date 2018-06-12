#pragma once

#include "../EC/State_machine.h"
#include "States.h"

class State_machine;

class State_turret_active : public State {

   private:
    Transform_component* player_trans;

   public:
    State_turret_active();
    State_turret_active(State_machine* sm);
    ~State_turret_active();

    void on_enable() override;
    void update() override;
};