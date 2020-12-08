//
// Created by ozanselte on 12/19/18.
//

#ifndef HW5_TRIANGLE_H
#define HW5_TRIANGLE_H

#include "Shape.h"
#include <stdexcept>

using std::out_of_range;

class Triangle : public Shape {
public:
    Triangle();
    Triangle(double sideLength);
    Triangle(double sideLength, double topX, double topY);
    Triangle(double sideLength, double topX, double topY, bool isUpsideDown);
    double getX(int point) const throw(out_of_range);
    double getY(int point) const throw(out_of_range);
    void setTriangle(double sideLength, double topX, double topY, bool isUpsideDown) throw(out_of_range);

    inline ShapeType getType() const { return ShapeType::Triangle; };
    double area() const;
    double perimeter() const;
    void draw(ostream& stream, string fill, string border) const;
    Triangle *clone() const;
    Triangle& operator ++();
    Triangle& operator --();
    const Triangle& operator ++(int);
    const Triangle& operator --(int);

private:
    double xa = 0.0, ya = 0.0;
    double xb = 0.0, yb = 0.0;
    double xc = 0.0, yc = 0.0;
};

#endif //HW5_TRIANGLE_H
