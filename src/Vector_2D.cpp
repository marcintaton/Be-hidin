#include "Vector_2D.h"

Vector_2D::Vector_2D() {

    x = 0.0;
    y = 0.0;
}

Vector_2D::Vector_2D(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector_2D& Vector_2D::zero() {
    this->x = 0;
    this->y = 0;
    return *this;
}

Vector_2D& Vector_2D::add(const Vector_2D& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}
Vector_2D& Vector_2D::subtract(const Vector_2D& other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}
Vector_2D& Vector_2D::multiply(const Vector_2D& other) {
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}
Vector_2D& Vector_2D::divide(const Vector_2D& other) {
    this->x /= other.x;
    this->y /= other.y;
    return *this;
}

Vector_2D& operator+(Vector_2D& vec1, const Vector_2D& vec2) {
    return vec1.add(vec2);
}
Vector_2D& operator-(Vector_2D& vec1, const Vector_2D& vec2) {
    return vec1.subtract(vec2);
}
Vector_2D& operator*(Vector_2D& vec1, const Vector_2D& vec2) {
    return vec1.multiply(vec2);
}
Vector_2D& operator/(Vector_2D& vec1, const Vector_2D& vec2) {
    return vec1.divide(vec2);
}

Vector_2D& Vector_2D::operator*(const int& i) {
    this->x *= i;
    this->y *= i;
    return *this;
}

Vector_2D& Vector_2D::operator+=(const Vector_2D& vec) {
    return this->add(vec);
}
Vector_2D& Vector_2D::operator-=(const Vector_2D& vec) {
    return this->subtract(vec);
}
Vector_2D& Vector_2D::operator*=(const Vector_2D& vec) {
    return this->multiply(vec);
}
Vector_2D& Vector_2D::operator/=(const Vector_2D& vec) {
    return this->divide(vec);
}

std::ostream& operator<<(std::ostream& os, const Vector_2D& vec) {

    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}