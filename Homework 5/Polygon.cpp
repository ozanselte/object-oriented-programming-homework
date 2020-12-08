//
// Created by ozanselte on 12/20/18.
//

#include "Polygon.h"
#include <cmath>

using std::endl;
/*
double Polygon::area() const
{
    double a = 0.0;
    for(int i = 0; i < getSize()-1; i++){
        a += getX(i) * getY(i + 1);
    }
    a += getX(getSize()-1) * getY(0);
    for(int i = 0; i < getSize()-1; i++){
        a -= getX(i + 1) * getY(i);
    }
    a -= getX(0) * getY(getSize()-1);
    return a;
}

double Polygon::perimeter() const
{
    double p = 0;
    for(int i = 1; i < getSize(); ++i) {
        p += sqrt(pow(getX(i) - getX(i-1), 2) + pow(getY(i) - getY(i-1), 2));
    }
    p += sqrt(pow(getX(1) - getX(getSize()-1), 2) + pow(getY(1) - getY(getSize()-1), 2));
    return p;
}
*/
void Polygon::draw(ostream& stream, string fill, string border) const
{
    stream << "<polygon points=\"";
    for (int i = 0; i < getSize(); ++i) {
        stream << getX(i) << ",";
        stream << getY(i) << " ";
    }
    stream << "\" fill=\"" << fill << "\" stroke=\"" << border << "\" />" << endl;
}

Polygon& Polygon::operator ++()
{
    for(int i = 0; i < getSize(); i++){
        setX(i, getX(i) + 1);
        setY(i, getY(i) + 1);
    }
    return *this;
}

const Polygon& Polygon::operator ++(int)
{
    delete tempShape;
    tempShape = dynamic_cast<Shape *>(this->clone());
    ++(*this);
    return *dynamic_cast<Polygon *>(tempShape);
}

Polygon& Polygon::operator --()
{
    for(int i = 0; i < getSize(); i++){
        setX(i, getX(i) - 1);
        setY(i, getY(i) - 1);
    }
    return *this;
}

const Polygon& Polygon::operator --(int)
{
    delete tempShape;
    tempShape = dynamic_cast<Shape *>(this->clone());
    --(*this);
    return *dynamic_cast<Polygon *>(tempShape);
}