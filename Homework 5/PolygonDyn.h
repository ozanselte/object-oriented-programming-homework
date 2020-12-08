//
// Created by ozanselte on 12/20/18.
//

#ifndef HW5_POLYGONDYN_H
#define HW5_POLYGONDYN_H

#include "Polygon.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <stdexcept>

using std::out_of_range;

class PolygonDyn : public Polygon{
public:
    PolygonDyn(const PolygonDyn& obj);
    PolygonDyn& operator =(const PolygonDyn& obj);
    ~PolygonDyn();
    PolygonDyn(const Rectangle& obj);
    PolygonDyn(const Circle& obj);
    PolygonDyn(const Triangle& obj);

    inline ShapeType getType() const { return ShapeType::PolygonDyn; };
    PolygonDyn *clone() const;
    size_t getSize() const;

    double getX(int i) const throw(out_of_range);
    double getY(int i) const throw(out_of_range);
    void setX(int i, double val) throw(out_of_range);
    void setY(int i, double val) throw(out_of_range);

private:
    Point2D *pointPtr = nullptr;
    size_t size = 0;
};

#endif //HW5_POLYGONDYN_H
