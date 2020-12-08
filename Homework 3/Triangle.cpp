//
// Created by ozanselte on 10/26/18.
//

#include "Triangle.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

double Triangle::totalPerimeter = 0.0;
double Triangle::totalArea = 0.0;

Triangle::Triangle(void)
{
    setTriangle(0, 0, 0, false);
}

Triangle::Triangle(double sideLength)
{
    setTriangle(sideLength, sideLength / 2.0, 0, false);
}

Triangle::Triangle(double sideLength, double topX, double topY)
{
    setTriangle(sideLength, topX, topY, false);
}

Triangle::Triangle(double sideLength, double topX, double topY, bool isUpsideDown)
{
    setTriangle(sideLength, topX, topY, isUpsideDown);
}

double Triangle::getX(int point) const
{
    switch (point){
        case 0:
            return xa;
        case 1:
            return xb;
        case 2:
            return xc;
        default:
            cerr << "Triangle point must between zero and two." << endl;
            exit(EXIT_FAILURE);
    }
}

double Triangle::getY(int point) const
{
    switch (point){
        case 0:
            return ya;
        case 1:
            return yb;
        case 2:
            return yc;
        default:
            cerr << "Triangle point must between zero and two." << endl;
            exit(EXIT_FAILURE);
    }
}

double Triangle::getPerimeter(void) const
{
    auto sideLength = abs(xc - xb);
    return sideLength * 3.0;
}

double Triangle::getArea(void) const
{
    double sideLength = abs(xc - xb);
    return sideLength * sideLength * sqrt(3) / 4;
}

void Triangle::draw(ostream& stream, string color, string stroke) const
{
    stream <<
    "<polygon points=\"" <<
    xa << "," << ya << " " <<
    xb << "," << yb << " " <<
    xc << "," << yc << "\" " <<
    "fill=\"" << color << "\" " <<
    "stroke=\"" << stroke << "\" />" <<
    endl;
}

void Triangle::setTriangle(double sideLength, double topX, double topY, bool isUpsideDown)
{
    if(0 > sideLength){
        cerr << "Triangle Side Length cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    if(0 > topX){
        cerr << "Triangle Top X-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    if(0 > topY){
        cerr << "Triangle Top Y-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    totalPerimeter -= getPerimeter();
    totalArea -= getArea();
    int h = sideLength * (sqrt(3) / 2.0);
    xa = topX;
    ya = topY;
    xb = topX - sideLength/2;
    yb = topY + (isUpsideDown ? -h : h);
    xc = topX + sideLength/2;
    yc = topY + (isUpsideDown ? -h : h);
    totalPerimeter += getPerimeter();
    totalArea += getArea();
}

Triangle& Triangle::operator ++()
{
    ++xa; ++xb; ++xc;
    ++ya; ++yb; ++yc;
    return *this;
}

const Triangle Triangle::operator ++(int)
{
    auto sideLength = abs(xb - xc);
    bool isUpsideDown = (yb < ya);
    Triangle temp(sideLength, xa, ya, isUpsideDown);
    ++xa; ++xb; ++xc;
    ++ya; ++yb; ++yc;
    return temp;
}

Triangle& Triangle::operator --()
{
    --xa; --xb; --xc;
    --ya; --yb; --yc;
    return *this;
}

const Triangle Triangle::operator --(int)
{
    auto sideLength = abs(xb - xc);
    bool isUpsideDown = (yb < ya);
    Triangle temp(sideLength, xa, ya, isUpsideDown);
    --xa; --xb; --xc;
    --ya; --yb; --yc;
    return temp;
}

const Triangle Triangle::operator +(double d) const
{
    auto sideLength = abs(xb - xc);
    bool isUpsideDown = (yb < ya);
    Triangle temp(sideLength + d, xa, ya, isUpsideDown);
    return temp;
}

const Triangle Triangle::operator -(double d) const
{
    auto sideLength = abs(xb - xc);
    bool isUpsideDown = (yb < ya);
    Triangle temp(sideLength - d, xa, ya, isUpsideDown);
    return temp;
}

double Triangle::getTotalPerimeter(void)
{
    return totalPerimeter;
}

double Triangle::getTotalArea(void)
{
    return totalArea;
}

ostream& operator <<(ostream& stream, const Triangle& obj)
{
    obj.draw(stream, "green", "black");
    return stream;
}