//
// Created by ozanselte on 12/20/18.
//

#ifndef HW5_POLYGON_H
#define HW5_POLYGON_H

#include "Shape.h"
#include "Point2D.h"


class Polygon : public Shape{
public:
    inline double area() const { return a; };
    double perimeter() const { return p; };
    void draw(ostream& stream, string fill, string border) const;
    virtual Polygon *clone() const =0;

    Polygon& operator ++();
    const Polygon& operator ++(int);
    Polygon& operator --();
    const Polygon& operator --(int);

    virtual size_t getSize() const =0;

    virtual double getX(int i) const =0;
    virtual double getY(int i) const =0;
    virtual void setX(int i, double val) =0;
    virtual void setY(int i, double val) =0;

protected:
    double a, p;
};


#endif //HW5_POLYGON_H
