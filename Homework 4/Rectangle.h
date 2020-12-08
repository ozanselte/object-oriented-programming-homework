//
// Created by ozanselte on 11/22/18.
//

#ifndef HW4_RECTANGLE_H
#define HW4_RECTANGLE_H

#include <fstream>
#include <string>

using std::ostream;
using std::string;

class Rectangle {
public:
    Rectangle(void);
    Rectangle(double w, double h, double _x, double _y);
    void setSize(double w, double h);
    void setWidth(double w);
    void setHeight(double h);
    void setLocation(double _x, double _y);
    void setX(double _x);
    void setY(double _y);
    double getWidth(void) const;
    double getHeight(void) const;
    double getX(void) const;
    double getY(void) const;
    double getPerimeter(void) const;
    double getArea(void) const;
    void draw(ostream& stream, string color, string stroke) const;

    Rectangle& operator ++();
    const Rectangle operator ++(int);
    Rectangle& operator --();
    const Rectangle operator --(int);
    const Rectangle operator +(double d) const;
    const Rectangle operator -(double d) const;

    static double getTotalPerimeter(void);
    static double getTotalArea(void);

private:
    double width = 0.0, height = 0.0;
    double x = 0.0, y = 0.0;
    static double totalPerimeter;
    static double totalArea;
};

ostream& operator <<(ostream& stream, const Rectangle& obj);

#endif //HW4_RECTANGLE_H
