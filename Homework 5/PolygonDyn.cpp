//
// Created by ozanselte on 12/20/18.
//

#include "PolygonDyn.h"
#include <cmath>

PolygonDyn::PolygonDyn(const PolygonDyn& obj)
{
    size = obj.getSize();
    a = obj.area();
    p = obj.perimeter();
    pointPtr = new Point2D[size];
    for(int i = 0; i < size; i++){
        pointPtr[i].setX(obj.getX(i));
        pointPtr[i].setY(obj.getY(i));
    }
}

PolygonDyn& PolygonDyn::operator =(const PolygonDyn& obj)
{
    delete[] pointPtr;
    size = obj.getSize();
    a = obj.area();
    p = obj.perimeter();
    pointPtr = new Point2D[size];
    for(int i = 0; i < size; i++){
        pointPtr[i].setX(obj.getX(i));
        pointPtr[i].setY(obj.getY(i));
    }
    return *this;
}

PolygonDyn::~PolygonDyn()
{
    delete[] pointPtr;
}

PolygonDyn::PolygonDyn(const Rectangle& obj)
{
    size = 4;
    a = obj.area();
    p = obj.perimeter();
    pointPtr = new Point2D[size];
    pointPtr[0] = Point2D(obj.getX(), obj.getY());
    pointPtr[1] = Point2D(obj.getX(), obj.getY() + obj.getWidth());
    pointPtr[2] = Point2D(obj.getX() + obj.getHeight(), obj.getY() + obj.getWidth());
    pointPtr[3] = Point2D(obj.getX() + obj.getHeight(), obj.getY());
}

PolygonDyn::PolygonDyn(const Circle& obj)
{
    size = 100;
    a = obj.area();
    p = obj.perimeter();
    pointPtr = new Point2D[size];
    for (int i = 0; i < size; ++i) {
        pointPtr[i] = Point2D(cos(2*i*M_PI / 100) * obj.getRadius() + obj.getX(),
                                      sin(2*i*M_PI / 100) * obj.getRadius() + obj.getY());
    }
}

PolygonDyn::PolygonDyn(const Triangle& obj)
{
    size = 3;
    a = obj.area();
    p = obj.perimeter();
    pointPtr = new Point2D[size];
    for (int i = 0; i < size; ++i) {
        pointPtr[i] = Point2D(obj.getX(i), obj.getY(i));
    }
}

PolygonDyn *PolygonDyn::clone() const
{
    PolygonDyn *copy = new PolygonDyn(*this);
    return copy;
}

size_t PolygonDyn::getSize() const
{
    return size;
}

double PolygonDyn::getX(int i) const throw(out_of_range)
{
    if(size < i){
        throw out_of_range("Array index cannot be higher than array size!");
    }
    else if(0 > i){
        throw out_of_range("Array index cannot be lower than 0!");
    }
    return pointPtr[i].getX();
}

double PolygonDyn::getY(int i) const throw(out_of_range)
{
    if(size < i){
        throw out_of_range("Array index cannot be higher than array size!");
    }
    else if(0 > i){
        throw out_of_range("Array index cannot be lower than 0!");
    }
    return pointPtr[i].getY();
}

void PolygonDyn::setX(int i, double val) throw(out_of_range)
{
    if(size < i){
        throw out_of_range("Array index cannot be higher than array size!");
    }
    else if(0 > i){
        throw out_of_range("Array index cannot be lower than 0!");
    }
    pointPtr[i].setX(val);
}

void PolygonDyn::setY(int i, double val) throw(out_of_range)
{
    if(size < i){
        throw out_of_range("Array index cannot be higher than array size!");
    }
    else if(0 > i){
        throw out_of_range("Array index cannot be lower than 0!");
    }
    pointPtr[i].setY(val);
}