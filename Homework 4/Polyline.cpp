//
// Created by ozanselte on 11/23/18.
//

#include "Polyline.h"
#include <iostream>
#include "Polygon.h"

using std::vector;
using std::ostream;
using std::cerr;
using std::endl;

namespace HW4_SELTE {
    Polyline::Polyline(const Polyline& obj)
    : polygon(obj.polygon)
    { /* EMPTY */ }

    Polyline::Polyline(const Polygon& obj)
    : polygon(obj)
    { /* EMPTY */ }

    Polyline::Polyline(const vector<Polygon::Point2D>& v)
    : polygon(v)
    { /* EMPTY */ }

    Polyline::Polyline(const Polygon::Point2D& point)
    : polygon(point)
    { /* EMPTY */ }

    Polyline::Polyline(const Rectangle& rectangle)
    : polygon(rectangle)
    { /* EMPTY */ }

    Polyline::Polyline(const Triangle& triangle)
    : polygon(triangle)
    { /* EMPTY */ }

    Polyline::Polyline(const Circle& circle)
    : polygon(circle)
    { /* EMPTY */ }

    Polyline::~Polyline()
    { /* EMPTY */ }

    int Polyline::getSize() const
    {
        return polygon.getSize();
    }

    Polyline& Polyline::operator =(const Polyline& obj)
    {
        polygon = obj.polygon;
        return *this;
    }

    Polygon::Point2D& Polyline::operator [](int i) const
    {
        if(0 > i){
            cerr << "Array index cannot be smaller than zero." << endl;
            exit(EXIT_FAILURE);
        }
        return polygon[i];
    }

    const Polyline& Polyline::operator +(const Polyline& obj) const
    {
        return *new Polyline(polygon + obj.polygon);
    }

    bool operator ==(const Polyline& a, const Polyline& b)
    {
        return a.polygon == b.polygon;
    }

    bool operator !=(const Polyline& a, const Polyline& b)
    {
        return a.polygon != b.polygon;
    }

    ostream& operator <<(ostream& stream, const Polyline& obj)
    {
        stream << "<polyline points=\"";
        for (int i = 0; i < obj.getSize(); ++i) {
            stream << obj[i].getX() << ",";
            stream << obj[i].getY() << " ";
        }
        stream << "\" fill=\"blue\" stroke=\"black\" />" << endl;
        return stream;
    }

}