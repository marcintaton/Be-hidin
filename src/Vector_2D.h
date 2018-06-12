#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <iostream>

class Vector_2D {

   private:
   public:
    double x;
    double y;
    Vector_2D();
    Vector_2D(double x, double y);

    double     length();
    Vector_2D& zero();
    Vector_2D& normalize();

    Vector_2D& add(const Vector_2D& other);
    Vector_2D& subtract(const Vector_2D& other);
    Vector_2D& multiply(const Vector_2D& other);
    Vector_2D& divide(const Vector_2D& other);

    friend Vector_2D& operator+(Vector_2D& vec1, const Vector_2D& vec2);
    friend Vector_2D& operator-(Vector_2D& vec1, const Vector_2D& vec2);
    friend Vector_2D& operator*(Vector_2D& vec1, const Vector_2D& vec2);
    friend Vector_2D& operator/(Vector_2D& vec1, const Vector_2D& vec2);

    Vector_2D& operator*(const int& i);

    Vector_2D& operator+=(const Vector_2D& vec);
    Vector_2D& operator-=(const Vector_2D& vec);
    Vector_2D& operator*=(const Vector_2D& vec);
    Vector_2D& operator/=(const Vector_2D& vec);

    friend std::ostream& operator<<(std::ostream& os, const Vector_2D& vec);
};
#endif