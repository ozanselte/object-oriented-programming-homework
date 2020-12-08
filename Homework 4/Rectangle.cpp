//
// Created by ozanselte on 11/22/18.
//

#include "Rectangle.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using std::cerr;
using std::endl;
using std::ostream;
using std::string;

double Rectangle::totalPerimeter = 0.0;
double Rectangle::totalArea = 0.0;

Rectangle::Rectangle(void)
{
    setSize(0, 0);
    setLocation(0, 0);
}

Rectangle::Rectangle(double w, double h, double _x, double _y)
{
    setSize(w, h);
    setLocation(_x, _y);
}

void Rectangle::setSize(double w, double h)
{
    setWidth(w);
    setHeight(h);
}

void Rectangle::setLocation(double _x, double _y)
{
    setX(_x);
    setY(_y);
}

void Rectangle::setWidth(double w)
{
    if(0 > w){
        cerr << "Rectangle Width cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    totalPerimeter -= getPerimeter();
    totalArea -= getArea();
    width = w;
    totalPerimeter += getPerimeter();
    totalArea += getArea();
}

void Rectangle::setHeight(double h)
{
    if(0 > h){
        cerr << "Rectangle Height cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    totalPerimeter -= getPerimeter();
    totalArea -= getArea();
    height = h;
    totalPerimeter += getPerimeter();
    totalArea += getArea();
}

void Rectangle::setX(double _x)
{
    if(0 > _x){
        cerr << "Rectangle X-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    x = _x;
}

void Rectangle::setY(double _y)
{
    if(0 > _y){
        cerr << "Rectangle Y-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    y = _y;
}

double Rectangle::getWidth(void) const
{
    return width;
}

double Rectangle::getHeight(void) const
{
    return height;
}

double Rectangle::getX(void) const
{
    return x;
}

double Rectangle::getY(void) const
{
    return y;
}

double Rectangle::getPerimeter(void) const
{
    return (width + height) * 2.0;
}

double Rectangle::getArea(void) const
{
    return width * height;
}

void Rectangle::draw(ostream& stream, string color, string stroke) const
{
    stream <<
           "<rect " <<
           "width=\"" << width << "\" " <<
           "height=\"" << height << "\" " <<
           "x=\"" << x << "\" " <<
           "y=\"" << y << "\" " <<
           "fill=\"" << color << "\" " <<
           "stroke=\"" << stroke << "\" />" <<
           endl;
}

Rectangle& Rectangle::operator ++()
{
    ++x;
    ++y;
    return *this;
}

const Rectangle Rectangle::operator ++(int)
{
    Rectangle temp(width, height, x, y);
    ++x;
    ++y;
    return temp;
}

Rectangle& Rectangle::operator --()
{
    --x;
    --y;
    return *this;
}

const Rectangle Rectangle::operator --(int)
{
    Rectangle temp(width, height, x, y);
    --x;
    --y;
    return temp;
}

const Rectangle Rectangle::operator +(double d) const
{
    Rectangle temp(width + d, height + d, x, y);
    return temp;
}

const Rectangle Rectangle::operator -(double d) const
{
    Rectangle temp(width - d, height - d, x, y);
    return temp;
}

double Rectangle::getTotalPerimeter(void)
{
    return totalPerimeter;
}

double Rectangle::getTotalArea(void)
{
    return totalArea;
}

ostream& operator <<(ostream& stream, const Rectangle& obj)
{
    obj.draw(stream, "green", "black");
    return stream;
}