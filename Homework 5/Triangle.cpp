//
// Created by ozanselte on 12/19/18.
//

#include "Triangle.h"
#include <cmath>

using std::endl;

Triangle::Triangle()
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

double Triangle::getX(int point) const throw(out_of_range)
{
    switch (point){
        case 0:
            return xa;
        case 1:
            return xb;
        case 2:
            return xc;
        default:
            throw out_of_range("Triangle point must between zero and two!");
    }
}

double Triangle::getY(int point) const throw(out_of_range)
{
    switch (point){
        case 0:
            return ya;
        case 1:
            return yb;
        case 2:
            return yc;
        default:
            throw out_of_range("Triangle point must between zero and two!");
    }
}

void Triangle::setTriangle(double sideLength, double topX, double topY, bool isUpsideDown) throw(out_of_range)
{
    if(0 > sideLength){
        throw out_of_range("Triangle Side Length cannot be lower than zero!");
    }
    if(0 > topX){
        throw out_of_range("Triangle Top X-coordinate cannot be lower than zero!");
    }
    if(0 > topY){
        throw out_of_range("Triangle Top Y-coordinate cannot be lower than zero!");
    }
    int h = sideLength * (sqrt(3) / 2.0);
    xa = topX;
    ya = topY;
    xb = topX - sideLength/2;
    yb = topY + (isUpsideDown ? -h : h);
    xc = topX + sideLength/2;
    yc = topY + (isUpsideDown ? -h : h);
}

double Triangle::area(void) const
{
    double sideLength = abs(xc - xb);
    return sideLength * sideLength * sqrt(3) / 4;
}

double Triangle::perimeter(void) const
{
    auto sideLength = abs(xc - xb);
    return sideLength * 3.0;
}

void Triangle::draw(ostream& stream, string fill, string border) const
{
    stream <<
           "<polygon points=\"" <<
           xa << "," << ya << " " <<
           xb << "," << yb << " " <<
           xc << "," << yc << "\" " <<
           "fill=\"" << fill << "\" " <<
           "stroke=\"" << border << "\" />" <<
           endl;
}

Triangle *Triangle::clone() const
{
    Triangle *copy = new Triangle(*this);
    return copy;
}

Triangle& Triangle::operator ++()
{
    ++xa; ++xb; ++xc;
    ++ya; ++yb; ++yc;
    return *this;
}

Triangle& Triangle::operator --()
{
    --xa; --xb; --xc;
    --ya; --yb; --yc;
    return *this;
}

const Triangle& Triangle::operator ++(int)
{
    delete tempShape;
    tempShape = dynamic_cast<Shape *>(this->clone());
    ++(*this);
    return *dynamic_cast<Triangle *>(tempShape);
}

const Triangle& Triangle::operator --(int)
{
    delete tempShape;
    tempShape = dynamic_cast<Shape *>(this->clone());
    --(*this);
    return *dynamic_cast<Triangle *>(tempShape);
}