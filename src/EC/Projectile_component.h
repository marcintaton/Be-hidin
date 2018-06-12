#pragma once

#include "Components.h"

class Projectile_component : public Component {

   private:
   public:
    Projectile_component();
    ~Projectile_component();

    void update() override;
};