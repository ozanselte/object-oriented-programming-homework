//
// Created by ozanselte on 12/19/18.
//

#include "Circle.h"
#include <cmath>

using std::endl;

Circle::Circle()
{
    setRadius(0);
    setLocation(0, 0);
}

Circle::Circle(double r)
{
    setRadius(r);
    setLocation(r, r);
}

Circle::Circle(double r, double _x, double _y)
{
    setRadius(r);
    setLocation(_x, _y);
}

void Circle::setRadius(double r) throw(out_of_range)
{
    if(0 > r){
        throw out_of_range("Circle Radius cannot be lower than 0!");
    }
    radius = r;
}

void Circle::setLocation(double _x, double _y)
{
    setX(_x);
    setY(_y);
}

void Circle::setX(double _x) throw(out_of_range)
{
    if(0 > _x){
        throw out_of_range("Circle X-coordinate cannot be lower than zero!");
    }
    x = _x;
}

void Circle::setY(double _y) throw(out_of_range)
{
    if(0 > _y){
        throw out_of_range("Circle Y-coordinate cannot be lower than zero!");
    }
    y = _y;
}

double Circle::area(void) const
{
    return radius * radius * M_PI;
}

double Circle::perimeter(void) const
{
    return radius * M_PI * 2.0;
}

void Circle::draw(ostream& stream, string fill, string border) const
{
    stream <<
           "<circle " <<
           "r=\"" << radius << "\" " <<
           "cx=\"" << x << "\" " <<
           "cy=\"" << y << "\" " <<
           "fill=\"" << fill << "\" " <<
           "stroke=\"" << border << "\" />" <<
           endl;
}

Circle *Circle::clone() const
{
    Circle *copy = new Circle(*this);
    return copy;
}

Circle& Circle::operator ++()
{
    ++x;
    ++y;
    return *this;
}

Circle& Circle::operator --()
{
    --x;
    --y;
    return *this;
}

const Circle& Circle::operator ++(int)
{
    delete tempShape;
    tempShape = dynamic_cast<Shape *>(this->clone());
    ++(*this);
    return *dynamic_cast<Circle *>(tempShape);
}

const Circle& Circle::operator --(int)
{
    delete tempShape;
    tempShape = dynamic_cast<Shape *>(this->clone());
    --(*this);
    return *dynamic_cast<Circle *>(tempShape);
}