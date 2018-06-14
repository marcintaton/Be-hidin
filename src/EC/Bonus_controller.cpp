#include "Bonus_controller.h"

Bonus_controller::Bonus_controller() {
    bonus = nullptr;
}

Bonus_controller::~Bonus_controller() {
}

void Bonus_controller::update() {
    if (bonus != nullptr) {
        bonus->update();
        if (bonus->active == false) {
            delete (bonus);
            bonus = nullptr;
        }
    }
}

void Bonus_controller::add_bonus(Bonus* _bonus) {
    bonus = _bonus;
    bonus->on_enable();
}