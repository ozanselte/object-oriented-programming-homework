//
// Created by ozanselte on 11/22/18.
//

#include "Polygon.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

using std::vector;
using std::ostream;
using std::cerr;
using std::endl;

namespace HW4_SELTE {
    Polygon::Point2D::Point2D()
    {
        setCoordinates(0, 0);
    }

    Polygon::Point2D::Point2D(const Point2D& point)
    {
        setCoordinates(point.getX(), point.getY());
    }

    Polygon::Point2D::Point2D(double _x, double _y)
    {
        setCoordinates(_x, _y);
    }

    Polygon::Point2D::~Point2D()
    {
        /* EMPTY */
    }

    void Polygon::Point2D::setCoordinates(double _x, double _y)
    {
        setX(_x);
        setY(_y);
    }

    void Polygon::Point2D::setX(double val)
    {
        x = val;
    }

    void Polygon::Point2D::setY(double val)
    {
        y = val;
    }

    double Polygon::Point2D::getX() const
    {
        return x;
    }

    double Polygon::Point2D::getY() const
    {
        return y;
    }

    Polygon::Point2D& Polygon::Point2D::operator =(const Point2D& obj)
    {
        setX(obj.getX());
        setY(obj.getY());
        return *this;
    }

    Polygon::Polygon(const Polygon& obj)
    {
        size = obj.getSize();
        points = new Point2D[size];
        for (int i = 0; i < obj.getSize(); ++i) {
            points[i] = Point2D(obj.points[i].getX(), obj.points[i].getY());
        }
    }

    Polygon::Polygon(const vector<Point2D>& v)
    {
        if(0 == v.size()){
            cerr << "Polygon::Point2D vector size cannot be zero." << endl;
            exit(EXIT_FAILURE);
        }
        size = v.size();
        points = new Point2D[size];
        for (int i = 0; i < size; ++i) {
            points[i] = v[i];
        }
    }

    Polygon::Polygon(const Point2D& point)
    {
        size = 3;
        points = new Point2D[size];
        points[0] = point;
        points[1] = point;
        points[2] = point;
    }

    Polygon::Polygon(const Rectangle& rectangle)
    {
        size = 4;
        points = new Point2D[size];
        points[0] = Point2D(rectangle.getX(), rectangle.getY());
        points[1] = Point2D(rectangle.getX(), rectangle.getY() + rectangle.getWidth());
        points[2] = Point2D(rectangle.getX() + rectangle.getHeight(), rectangle.getY() + rectangle.getWidth());
        points[3] = Point2D(rectangle.getX() + rectangle.getHeight(), rectangle.getY());
    }

    Polygon::Polygon(const Triangle& triangle)
    {
        size = 3;
        points = new Point2D[size];
        for (int i = 0; i < size; ++i) {
            points[i] = Point2D(triangle.getX(i), triangle.getY(i));
        }
    }

    Polygon::Polygon(const Circle& circle)
    {
        size = 100;
        points = new Point2D[size];
        for (int i = 0; i < size; ++i) {
            points[i] = Point2D(cos(2*i*M_PI / size) * circle.getRadius() + circle.getX(),
                                sin(2*i*M_PI / size) * circle.getRadius() + circle.getY());
        }
    }

    Polygon::~Polygon()
    {
        delete[] points;
    }

    int Polygon::getSize() const
    {
        return size;
    }

    Polygon& Polygon::operator =(const Polygon& obj)
    {
        delete[] points;
        size = obj.getSize();
        points = new Point2D[size];
        for (int i = 0; i < size; ++i) {
            points[i] = Point2D(obj.points[i].getX(), obj.points[i].getY());
        }
        return *this;
    }

    Polygon::Point2D& Polygon::operator [](int i) const
    {
        if(0 > i){
            cerr << "Array index cannot be smaller than zero." << endl;
            exit(EXIT_FAILURE);
        }
        return points[i];
    }

    const Polygon& Polygon::operator +(const Polygon& obj) const
    {
        int newSize = size + obj.getSize();
        vector<Point2D> v;
        for (int i = 0; i < size; ++i) {
            v.push_back(points[i]);
        }
        for (int i = size; i < newSize; ++i) {
            v.push_back(points[i-size]);
        }
        return *new Polygon(v);
    }

    bool operator ==(const Polygon& a, const Polygon& b)
    {
        if(a.getSize() != b.getSize()){
            return false;
        }
        else{
            for (int i = 0; i < a.getSize(); ++i) {
                if(a[i].getX() != b[i].getX()
                   || a[i].getY() != b[i].getY()){
                    return false;
                }
            }
        }
        return true;
    }

    bool operator !=(const Polygon& a, const Polygon& b)
    {
        return !(a == b);
    }

    ostream& operator <<(ostream& stream, const Polygon& obj)
    {
        stream << "<polygon points=\"";
        for (int i = 0; i < obj.getSize(); ++i) {
            stream << obj[i].getX() << ",";
            stream << obj[i].getY() << " ";
        }
        stream << "\" fill=\"blue\" stroke=\"black\" />" << endl;
        return stream;
    }
}