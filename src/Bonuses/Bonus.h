#pragma once

#include "stdint.h"

class Bonus_controller;

class Bonus {

   protected:
    uint32_t bonus_start;
    uint32_t bonus_timer;

   public:
    Bonus_controller* controller;
    bool              active = false;

    Bonus();
    ~Bonus();

    virtual void on_enable();
    virtual void on_disable();
    virtual void update();
};