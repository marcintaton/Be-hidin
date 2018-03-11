#include "Position_component.h"

Position_component::Position_component() {
    x_pos = 0;
    y_pos = 0;
}

Position_component::Position_component(int x, int y) {

    y_pos = y;
    x_pos = x;
}

int Position_component::get_x() {
    return x_pos;
}

int Position_component::get_y() {
    return y_pos;
}

void Position_component::set_x(int x) {
    this->x_pos = x;
}

void Position_component::set_y(int y) {
    this->y_pos = y;
}

void Position_component::init() {
    x_pos = 0;
    y_pos = 0;
}

void Position_component::update() {
    x_pos++;
    y_pos++;
}

void Position_component::draw() {
}