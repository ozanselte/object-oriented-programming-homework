//
// Created by ozanselte on 10/26/18.
//

#include "Rectangle.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

Rectangle::Rectangle(void)
{
    Rectangle(0, 0, 0, 0);
}

Rectangle::Rectangle(int w, int h, int _x, int _y)
{
    setSize(w, h);
    setLocation(_x, _y);
}

void Rectangle::setSize(int w, int h)
{
    setWidth(w);
    setHeight(h);
}

void Rectangle::setLocation(int _x, int _y)
{
    setX(_x);
    setY(_y);
}

void Rectangle::setWidth(int w)
{
    if(0 > w){
        cerr << "Rectangle Width cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    width = w;
}

void Rectangle::setHeight(int h)
{
    if(0 > h){
        cerr << "Rectangle Height cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    height = h;
}

void Rectangle::setX(int _x)
{
    if(0 > _x){
        cerr << "Rectangle X-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    x = _x;
}

void Rectangle::setY(int _y)
{
    if(0 > _y){
        cerr << "Rectangle Y-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    y = _y;
}

int Rectangle::getWidth(void) const
{
    return width;
}

int Rectangle::getHeight(void) const
{
    return height;
}

int Rectangle::getX(void) const
{
    return x;
}

int Rectangle::getY(void) const
{
    return y;
}

void Rectangle::draw(ofstream& stream, string color, string stroke) const
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