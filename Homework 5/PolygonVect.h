//
// Created by ozanselte on 12/20/18.
//

#ifndef HW5_POLYGONVECT_H
#define HW5_POLYGONVECT_H

#include "Polygon.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <vector>
#include <stdexcept>

using std::out_of_range;
using std::vector;

class PolygonVect : public Polygon{
public:
    PolygonVect(const Rectangle& obj);
    PolygonVect(const Circle& obj);
    PolygonVect(const Triangle& obj);
    PolygonVect *clone() const;
    size_t getSize() const;

    inline ShapeType getType() const { return ShapeType::PolygonVect; };
    double getX(int i) const throw(out_of_range);
    double getY(int i) const throw(out_of_range);
    void setX(int i, double val) throw(out_of_range);
    void setY(int i, double val) throw(out_of_range);

private:
    vector<Point2D> pointVector;
};

#endif //HW5_POLYGONVECT_H
