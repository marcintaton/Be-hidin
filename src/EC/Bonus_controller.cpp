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
            remove_bonus();
        }
    }
}

void Bonus_controller::add_bonus(Bonus* _bonus) {
    bonus = _bonus;
    bonus->on_enable();
}

Bonus* Bonus_controller::get_bonus() {
    return bonus;
}

void Bonus_controller::remove_bonus() {
    bonus->on_disable();
    delete (bonus);
    bonus = nullptr;
}