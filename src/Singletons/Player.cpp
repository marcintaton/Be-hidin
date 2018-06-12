#include "Player.h"

Entity* Player::instance = nullptr;
bool    Player::act      = true;

Entity* Player::Get_instance() {

    return Player::instance;
}

void Player::Set_instance(Entity* _instance) {

    if (instance == nullptr) {
        Player::instance = _instance;
    }
}

void Player::Remove_instance() {
    // Player::instance = nullptr;
    Player::act = false;
}