#pragma once

#include "../Factories/Projectile_factory.h"
#include "EC.h"

class Shooter_component : public Component {

   private:
    uint32_t    last_shot;
    int         shoot_cd;
    std::string tex_path;

   public:
    bool active;
    Shooter_component();
    Shooter_component(double cooldown, std::string path);
    ~Shooter_component();

    void shot();

    void update() override;
};
