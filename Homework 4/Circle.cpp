//
// Created by ozanselte on 11/22/18.
//

#include "Circle.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>

using std::cerr;
using std::endl;
using std::ostream;
using std::string;

double Circle::totalPerimeter = 0.0;
double Circle::totalArea = 0.0;

Circle::Circle()
{
    setRadius(0);
    setLocation(0, 0);
}

Circle::Circle(double r, double _x, double _y)
{
    setRadius(r);
    setLocation(_x, _y);
}

void Circle::setRadius(double r)
{
    if(0 > r){
        cerr << "Circle Radius cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    totalPerimeter -= getPerimeter();
    totalArea -= getArea();
    radius = r;
    totalPerimeter += getPerimeter();
    totalArea += getArea();
}


double Circle::getPerimeter(void) const
{
    return radius * M_PI * 2.0;
}

double Circle::getArea(void) const
{
    return radius * radius * M_PI;
}

void Circle::setLocation(double _x, double _y)
{
    setX(_x);
    setY(_y);
}

void Circle::setX(double _x)
{
    if(0 > _x){
        cerr << "Circle X-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    x = _x;
}

void Circle::setY(double _y)
{
    if(0 > _y){
        cerr << "Circle Y-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    y = _y;
}

double Circle::getRadius(void) const
{
    return radius;
}

double Circle::getX(void) const
{
    return x;
}

double Circle::getY(void) const
{
    return y;
}

void Circle::draw(ostream& stream, string color, string stroke) const
{
    stream <<
           "<circle " <<
           "r=\"" << radius << "\" " <<
           "cx=\"" << x << "\" " <<
           "cy=\"" << y << "\" " <<
           "fill=\"" << color << "\" " <<
           "stroke=\"" << stroke << "\" />" <<
           endl;
}

Circle& Circle::operator ++()
{
    ++x;
    ++y;
    return *this;
}

const Circle Circle::operator ++(int)
{
    Circle temp(radius, x, y);
    ++x;
    ++y;
    return temp;
}

Circle& Circle::operator --()
{
    --x;
    --y;
    return *this;
}

const Circle Circle::operator --(int)
{
    Circle temp(radius, x, y);
    --x;
    --y;
    return temp;
}

const Circle Circle::operator +(double d) const
{
    Circle temp(radius + d, x, y);
    return temp;
}

const Circle Circle::operator -(double d) const
{
    Circle temp(radius - d, x, y);
    return temp;
}

double Circle::getTotalPerimeter(void)
{
    return totalPerimeter;
}

double Circle::getTotalArea(void)
{
    return totalArea;
}

ostream& operator <<(ostream& stream, const Circle& obj)
{
    obj.draw(stream, "green", "black");
    return stream;
}