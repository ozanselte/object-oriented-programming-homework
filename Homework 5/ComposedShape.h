//
// Created by ozanselte on 12/19/18.
//

#ifndef HW5_COMPOSEDSHAPE_H
#define HW5_COMPOSEDSHAPE_H

#include <vector>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

using std::vector;

class ComposedShape : public Shape{
public:
    ComposedShape(const Rectangle& c, const Rectangle& s);
    ComposedShape(const Rectangle& c, const Circle& s);
    ComposedShape(const Rectangle& c, const Triangle& s);
    ComposedShape(const Circle& c, const Rectangle& s);
    ComposedShape(const Circle& c, const Circle& s);
    ComposedShape(const Circle& c, const Triangle& s);
    ComposedShape(const Triangle& c, const Rectangle& s);
    ComposedShape(const Triangle& c, const Circle& s);
    ComposedShape(const Triangle& c, const Triangle& s);
    ComposedShape(const ComposedShape& obj);
    ComposedShape& operator =(const ComposedShape& obj);
    ~ComposedShape();

    inline ShapeType getType() const { return ShapeType::ComposedShape; };
    inline double getWidth(void) const { return width; };
    inline double getHeight(void) const { return height; };
    inline ShapeType getContainerShape(void) const{ return containerShape; };
    inline ShapeType getSmallShape(void) const{ return smallShape; };

    void optimalFit();

    const ComposedShape& operator +=(const Rectangle& obj);
    const ComposedShape& operator +=(const Circle& obj);
    const ComposedShape& operator +=(const Triangle& obj);
    const Shape& operator [](int i);
    vector<Shape *> getShapeVector() const;

    double area() const;
    double perimeter() const;
    void draw(ostream& stream, string fill, string border) const;
    ComposedShape *clone() const;
    ComposedShape& operator ++();
    ComposedShape& operator --();
    const ComposedShape& operator ++(int);
    const ComposedShape& operator --(int);

private:
    Shape *container, *small;
    ShapeType containerShape, smallShape;
    double width, height;

    vector<Shape *> shapeVector;

    void setContainerRectangle();
    void setContainerCircle();
    void setContainerTriangle();
    void setSmallRectangle();
    void setSmallCircle();
    void setSmallTriangle();

    void writeSvgBegin(ostream& stream) const;
    void writeSvgEnd(ostream& stream) const;

    void rectangleOptimalFit();
    void rectangleFit(int w, int h);
    void circleOptimalFit();
    void triangleOptimalFit();
    bool triangleFit(int sideLength, int topX, int topY, bool isUpsideDown);

    bool isPointFitsContainer(int pX, int pY) const;
    bool isPointFitsRectangle(int pX, int pY, const Rectangle *obj) const;
    bool isPointFitsCircle(int pX, int pY, const Circle *obj) const;
    bool isPointFitsTriangle(int pX, int pY, const Triangle *obj) const;

    bool isRectangleFitsContainer(const Rectangle *obj) const;
    bool isCircleFitsContainer(const Circle *obj) const;
    bool isTriangleFitsContainer(const Triangle *obj) const;

    bool isRectanglesCompatible(const Rectangle *a, const Rectangle *b);
    bool isCirclesCompatible(const Circle *a, const Circle *b);
    bool isTrianglesCompatible(const Triangle *a, const Triangle *b);
};


#endif //HW5_COMPOSEDSHAPE_H
