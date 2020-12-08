//
// Created by ozanselte on 11/23/18.
//

#ifndef HW4_POLYLINE_H
#define HW4_POLYLINE_H

#include "Polygon.h"
namespace HW4_SELTE {
    class Polyline {
    public:
        Polyline(const Polyline& obj);
        Polyline(const Polygon& obj);
        Polyline(const vector<Polygon::Point2D>& v);
        Polyline(const Polygon::Point2D& point);
        Polyline(const Rectangle& rectangle);
        Polyline(const Triangle& triangle);
        Polyline(const Circle& circle);
        ~Polyline();

        int getSize() const;

        Polyline& operator =(const Polyline& obj);
        Polygon::Point2D& operator [](int i) const;
        const Polyline& operator +(const Polyline& obj) const;

        friend bool operator ==(const Polyline& a, const Polyline& b);
        friend bool operator !=(const Polyline& a, const Polyline& b);

    private:
        Polygon polygon;
    };

    bool operator ==(const Polyline& a, const Polyline& b);
    bool operator !=(const Polyline& a, const Polyline& b);
    ostream& operator <<(ostream& stream, const Polyline& obj);
}

#endif //HW4_POLYLINE_H
