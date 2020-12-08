//
// Created by ozanselte on 12/20/18.
//

#ifndef HW5_FUNCTIONS_H
#define HW5_FUNCTIONS_H

#include <vector>
#include <stdexcept>
#include "Shape.h"
#include "Polygon.h"

using std::vector;
using std::invalid_argument;

namespace SELTE_HW5 {
    void printAll(ostream& stream, vector<Shape *> v) throw(invalid_argument);
    void printPoly(ostream& stream, vector<Shape *> v);
    vector<Polygon *> convertAll(vector<Shape *> v) throw(invalid_argument);
    void sortShapes(vector<Shape *>& v);

    void testSingleShape(string name, Shape& shape);
}

namespace {
    bool cmpShapePtr(Shape *a, Shape *b);
}

#endif //HW5_FUNCTIONS_H
