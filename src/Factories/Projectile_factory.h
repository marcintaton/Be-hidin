#pragma once
#include "../EC/Components.h"
#include "../Vector_2D.h"

extern Entity_manager manager;

class Projectile_factory {

   private:
   public:
    static void create(Vector_2D caster, Vector_2D dst, std::string tex_path);
};