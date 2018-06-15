#pragma once

#include <functional>
#include "Components.h"
#include "EC.h"

class Bonus_component : public Component {

   private:
    std::function<void()> create_bonus;

   public:
    Bonus_component(std::function<void()> _creator);
    ~Bonus_component();

    void update() override;
};