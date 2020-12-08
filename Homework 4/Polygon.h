//
// Created by ozanselte on 11/22/18.
//

#ifndef HW4_POLYGON_H
#define HW4_POLYGON_H

#include <vector>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

using std::vector;
using std::ostream;

namespace HW4_SELTE {
    class Polygon {
    public:
        class Point2D {
        public:
            Point2D();
            Point2D(const Point2D& point);
            Point2D(double _x, double _y);
            ~Point2D();

            inline void setCoordinates(double _x, double _y);
            inline void setX(double val);
            inline void setY(double val);
            double getX() const;
            double getY() const;
            Point2D& operator =(const Point2D& obj);

        private:
            double x, y;
        };
        Polygon(const Polygon& obj);
        Polygon(const vector<Point2D>& v);
        Polygon(const Point2D& point);
        Polygon(const Rectangle& rectangle);
        Polygon(const Triangle& triangle);
        Polygon(const Circle& circle);
        ~Polygon();

        int getSize() const;

        Polygon& operator =(const Polygon& obj);
        Point2D& operator [](int i) const;
        const Polygon& operator +(const Polygon& obj) const;

    private:
        Point2D *points;
        int size;
    };

    bool operator ==(const Polygon& a, const Polygon& b);
    bool operator !=(const Polygon& a, const Polygon& b);
    ostream& operator <<(ostream& stream, const Polygon& obj);
}

#endif //HW4_POLYGON_H
