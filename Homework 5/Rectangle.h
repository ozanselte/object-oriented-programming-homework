//
// Created by ozanselte on 12/19/18.
//

#ifndef HW5_RECTANGLE_H
#define HW5_RECTANGLE_H

#include "Shape.h"
#include <stdexcept>

using std::out_of_range;

class Rectangle : public Shape{
public:
    Rectangle();
    Rectangle(double w, double h);
    Rectangle(double w, double h, double _x, double _y);
    void setSize(double w, double h);
    void setWidth(double w) throw(out_of_range);
    void setHeight(double h) throw(out_of_range);
    void setLocation(double _x, double _y);
    void setX(double _x) throw(out_of_range);
    void setY(double _y) throw(out_of_range);

    inline ShapeType getType() const { return ShapeType::Rectangle; };
    inline double getWidth() const { return width; };
    inline double getHeight() const { return height; };
    inline double getX() const { return x; };
    inline double getY() const { return y; };

    double area() const;
    double perimeter() const;
    void draw(ostream& stream, string fill, string border) const;
    Rectangle *clone() const;
    Rectangle& operator ++();
    Rectangle& operator --();
    const Rectangle& operator ++(int);
    const Rectangle& operator --(int);

private:
    double width = 0.0, height = 0.0;
    double x = 0.0, y = 0.0;
};

#endif //HW5_RECTANGLE_H
