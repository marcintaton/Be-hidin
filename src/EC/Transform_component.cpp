#include "Transform_component.h"

Transform_component::Transform_component() {
    position.zero();
}

Transform_component::Transform_component(double x, double y) {

    position.y = y;
    position.x = x;
}

Transform_component::Transform_component(double x,
                                         double y,
                                         int    height,
                                         int    width,
                                         double scale) {

    position.y   = y;
    position.x   = x;
    this->height = height;
    this->width  = width;
    this->scale  = scale;
}

void Transform_component::init() {
    velocity.zero();
    // velocity.y = 1;
}

void Transform_component::update() {

    // if (velocity.y < 1) {
    //     velocity.y += 0.2;
    // } else if (velocity.y > 1) {
    //     velocity.y = 1;
    // }

    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
}

void Transform_component::draw() {
}