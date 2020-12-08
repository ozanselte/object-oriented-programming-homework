//
// Created by ozanselte on 11/22/18.
//

#ifndef HW4_COMPOSEDSHAPE_H
#define HW4_COMPOSEDSHAPE_H

#include <vector>
#include <string>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"

using std::vector;
using std::ostream;
using namespace HW4_SELTE;

enum class Shape{
    Rectangle,
    Circle,
    Triangle
};

class ComposedShape {
public:
    ComposedShape(Rectangle container, Rectangle small);
    ComposedShape(Rectangle container, Circle small);
    ComposedShape(Rectangle container, Triangle small);
    ComposedShape(Circle container, Rectangle small);
    ComposedShape(Circle container, Circle small);
    ComposedShape(Circle container, Triangle small);
    ComposedShape(Triangle container, Rectangle small);
    ComposedShape(Triangle container, Circle small);
    ComposedShape(Triangle container, Triangle small);
    ~ComposedShape();

    double getWidth() const;
    double getHeight() const;

    void optimalFit();

    int getSize() const;

    const ComposedShape& operator +=(const Rectangle& obj);
    const ComposedShape& operator +=(const Circle& obj);
    const ComposedShape& operator +=(const Triangle& obj);
    const Polygon& operator [](int i) const;

private:
    double width, height;
    Shape containerShape, smallShape;

    Rectangle rectangleContainer, rectangleSmall;
    Circle circleContainer, circleSmall;
    Triangle triangleContainer, triangleSmall;

    vector<Polygon> smallVector;

    inline void setContainerRectangle(void);
    inline void setContainerCircle(void);
    inline void setContainerTriangle(void);

    inline void writeSvgBegin(ostream& stream) const;
    inline void writeSvgEnd(ostream& stream) const;

    inline void rectangleOptimalFit();
    inline void rectangleFit(int w, int h);
    inline void circleOptimalFit();
    inline void triangleOptimalFit();
    inline bool triangleFit(int sideLength, int topX, int topY, bool isUpsideDown);

    inline void drawContainer(ostream& stream) const;

    bool isPointFitsContainer(double pX, double pY) const;
    inline bool isPointFitsRectangle(double pX, double pY, const Rectangle& obj) const;
    inline bool isPointFitsCircle(double pX, double pY, const Circle& obj) const;
    inline bool isPointFitsTriangle(double pX, double pY, const Triangle& obj) const;

    inline bool isRectangleFitsContainer(const Rectangle& obj) const;
    inline bool isCircleFitsContainer(const Circle& obj) const;
    inline bool isTriangleFitsContainer(const Triangle& obj) const;

    bool isRectanglesCompatible(const Rectangle& a, const Rectangle& b) const;
    bool isCirclesCompatible(const Circle& a, const Circle& b) const;
    bool isTrianglesCompatible(const Triangle& a, const Triangle& b) const;

    friend ostream& operator <<(ostream& stream, const ComposedShape& obj);
};

ostream& operator <<(ostream& stream, const ComposedShape& obj);

namespace {
    const Rectangle *polygonToRectangle(const Polygon& obj);
    const Circle *polygonToCircle(const Polygon& obj);
    const Triangle *polygonToTriangle(const Polygon& obj);
}

#endif //HW4_COMPOSEDSHAPE_H
