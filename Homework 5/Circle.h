//
// Created by ozanselte on 12/19/18.
//

#ifndef HW5_CIRCLE_H
#define HW5_CIRCLE_H

#include "Shape.h"
#include <stdexcept>

using std::out_of_range;

class Circle : public Shape {
public:
    Circle();
    Circle(double r);
    Circle(double r, double _x, double _y);
    void setRadius(double r) throw(out_of_range);
    void setLocation(double _x, double _y);
    void setX(double _x) throw(out_of_range);
    void setY(double _y) throw(out_of_range);

    inline ShapeType getType() const { return ShapeType::Circle; };
    inline double getRadius() const { return radius; };
    inline double getX() const { return x; };
    inline double getY() const { return y; };

    double area() const;
    double perimeter() const;
    void draw(ostream& stream, string fill, string border) const;
    Circle *clone() const;
    Circle& operator ++();
    Circle& operator --();
    const Circle& operator ++(int);
    const Circle& operator --(int);

private:
    double radius = 0.0;
    double x = 0.0, y = 0.0;
};

#endif //HW5_CIRCLE_H
