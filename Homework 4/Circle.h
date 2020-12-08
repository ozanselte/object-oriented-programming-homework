//
// Created by ozanselte on 11/22/18.
//

#ifndef HW4_CIRCLE_H
#define HW4_CIRCLE_H

#include <fstream>
#include <string>

using std::ostream;
using std::string;

class Circle {
public:
    Circle();
    Circle(double r, double _x, double _y);
    void setRadius(double r);
    void setLocation(double _x, double _y);
    void setX(double _x);
    void setY(double _y);
    double getRadius(void) const;
    double getPerimeter(void) const;
    double getArea(void) const;
    double getX(void) const;
    double getY(void) const;
    void draw(ostream& stream, string color, string stroke) const;

    Circle& operator ++();
    const Circle operator ++(int);
    Circle& operator --();
    const Circle operator --(int);
    const Circle operator +(double d) const;
    const Circle operator -(double d) const;

    static double getTotalPerimeter(void);
    static double getTotalArea(void);

private:
    double radius = 0.0;
    double x = 0.0, y = 0.0;
    static double totalPerimeter;
    static double totalArea;
};

ostream& operator <<(ostream& stream, const Circle& obj);

#endif //HW4_CIRCLE_H
