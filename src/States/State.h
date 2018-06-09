#pragma once

#include <string>
#include "../EC/State_machine.h"

class State_machine;

class State {

   public:
    State();
    ~State();

    std::string    name;
    State_machine* parent_machine;

    virtual void on_keydown();
    virtual void on_keyup();
    virtual void on_enable();
    virtual void on_disable();
    virtual void update();
    virtual void late_update();
};