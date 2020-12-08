//
// Created by ozanselte on 10/26/18.
//

#ifndef HW3_COMPOSEDSHAPE_H
#define HW3_COMPOSEDSHAPE_H

#include <vector>
#include <string>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

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

    void setColors(string container, string small, string stroke);
    void setContainerColor(string color);
    void setSmallColor(string color);
    void setStrokeColor(string color);

    int getWidth(void) const;
    int getHeight(void) const;
    Shape getContainerShape(void) const;
    Shape getSmallShape(void) const;
    string getContainerColor(void) const;
    string getSmallColor(void) const;
    string getStrokeColor(void) const;

    void optimalFit(void);
    void draw(ostream& stream) const;

    class ShapeElem {
    public:
        ShapeElem(Rectangle& obj);
        ShapeElem(Circle& obj);
        ShapeElem(Triangle& obj);
        double getPerimeter(void) const;
        double getArea(void) const;
        Shape getShapeType(void) const;
        void * getShape(void) const;
        friend ostream& operator <<(ostream& stream, const ComposedShape::ShapeElem& obj);

    private:
        void *shape;
        Shape shapeType;
    };
    const ComposedShape& operator +=(Rectangle& obj);
    const ComposedShape& operator +=(Circle& obj);
    const ComposedShape& operator +=(Triangle& obj);
    const ShapeElem& operator [](int i);

private:
    Shape containerShape, smallShape;
    string containerColor="red", smallColor="green", strokeColor="black";
    int width, height;

    Rectangle rectangleContainer;
    Rectangle rectangleSmall;

    Circle circleContainer;
    Circle circleSmall;

    Triangle triangleContainer;
    Triangle triangleSmall;

    vector<ShapeElem> shapeVector;

    void setContainerRectangle(void);
    void setContainerCircle(void);
    void setContainerTriangle(void);
    void setSmallRectangle(void);
    void setSmallCircle(void);
    void setSmallTriangle(void);

    void writeSvgBegin(ostream& stream) const;
    void writeSvgEnd(ostream& stream) const;

    inline void rectangleOptimalFit(void);
    inline void rectangleFit(int w, int h);
    inline void circleOptimalFit(void);
    inline void triangleOptimalFit(void);
    inline bool triangleFit(int sideLength, int topX, int topY, bool isUpsideDown);

    inline void drawContainer(ostream& stream) const;
    void drawRectangles(ostream& stream) const;
    void drawCircles(ostream& stream) const;
    void drawTriangles(ostream& stream) const;

    bool isPointFitsContainer(int pX, int pY) const;
    inline bool isPointFitsRectangle(int pX, int pY, const Rectangle& obj) const;
    inline bool isPointFitsCircle(int pX, int pY, const Circle& obj) const;
    inline bool isPointFitsTriangle(int pX, int pY, const Triangle& obj) const;

    inline bool isRectangleFitsContainer(const Rectangle& obj) const;
    inline bool isCircleFitsContainer(const Circle& obj) const;
    inline bool isTriangleFitsContainer(const Triangle& obj) const;

    bool isRectanglesCompatible(const Rectangle& a, const Rectangle& b);
    bool isCirclesCompatible(const Circle& a, const Circle& b);
    bool isTrianglesCompatible(const Triangle& a, const Triangle& b);
};

ostream& operator <<(ostream& stream, const ComposedShape& obj);
ostream& operator <<(ostream& stream, const ComposedShape::ShapeElem& obj);

#endif //HW3_COMPOSEDSHAPE_H