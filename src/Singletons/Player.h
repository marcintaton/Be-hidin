#pragma once

#include "../EC/EC.h"

class Player {

   private:
    static Entity* instance;

   public:
    static bool    act;
    static void    Set_instance(Entity* _instance);
    static Entity* Get_instance();
    static void    Remove_instance();
};