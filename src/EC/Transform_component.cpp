#include "Transform_component.h"

Transform_component::Transform_component() {
    position.x = 0;
    position.y = 0;
}

Transform_component::Transform_component(double x, double y) {

    position.y = y;
    position.x = x;
}

void Transform_component::init() {
    velocity.x = 0;
    velocity.y = 0;
}

void Transform_component::update() {
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
}

void Transform_component::draw() {
}