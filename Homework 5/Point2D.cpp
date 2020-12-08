//
// Created by ozanselte on 12/20/18.
//

#include "Point2D.h"

Point2D::Point2D()
{
    setX(0);
    setY(0);
}

Point2D::Point2D(double _x, double _y)
{
    setX(_x);
    setY(_y);
}

Point2D& Point2D::operator =(const Point2D& obj)
{
    setX(obj.getX());
    setY(obj.getY());
}

Point2D::~Point2D()
{ /* EMPTY */ }

void Point2D::setX(double _x)
{
    x = _x;
}

void Point2D::setY(double _y)
{
    y = _y;
}