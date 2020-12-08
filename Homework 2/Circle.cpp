//
// Created by ozanselte on 10/26/18.
//

#include "Circle.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

Circle::Circle()
{
    Circle(0, 0, 0);
}

Circle::Circle(int r, int _x, int _y)
{
    setRadius(r);
    setLocation(_x, _y);
}

void Circle::setRadius(int r)
{
    if(0 > r){
        cerr << "Circle Radius cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    radius = r;
}

void Circle::setLocation(int _x, int _y)
{
    setX(_x);
    setY(_y);
}

void Circle::setX(int _x)
{
    if(0 > _x){
        cerr << "Circle X-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    x = _x;
}

void Circle::setY(int _y)
{
    if(0 > _y){
        cerr << "Circle Y-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    y = _y;
}

int Circle::getRadius(void) const
{
    return radius;
}

int Circle::getX(void) const
{
    return x;
}

int Circle::getY(void) const
{
    return y;
}

void Circle::draw(ofstream& stream, string color, string stroke) const
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