//
// Created by ozanselte on 10/26/18.
//

#ifndef HW2_COMPOSEDSHAPE_H
#define HW2_COMPOSEDSHAPE_H

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
    vector<Rectangle> getRectangleVector(void) const;
    vector<Circle> getCircleVector(void) const;
    vector<Triangle> getTriangleVector(void) const;

    void optimalFit(void);
    void draw(ofstream& stream) const;
private:
    Shape containerShape, smallShape;
    string containerColor="red", smallColor="green", strokeColor="black";
    int width, height;

    Rectangle rectangleContainer;
    Rectangle rectangleSmall;
    vector<Rectangle> rectangleVector;

    Circle circleContainer;
    Circle circleSmall;
    vector<Circle> circleVector;

    Triangle triangleContainer;
    Triangle triangleSmall;
    vector<Triangle> triangleVector;

    void setContainerRectangle(void);
    void setContainerCircle(void);
    void setContainerTriangle(void);
    void setSmallRectangle(void);
    void setSmallCircle(void);
    void setSmallTriangle(void);

    void writeSvgBegin(ofstream& stream) const;
    void writeSvgEnd(ofstream& stream) const;

    inline void rectangleOptimalFit(void);
    inline void rectangleFit(int w, int h);
    inline void circleOptimalFit(void);
    inline void triangleOptimalFit(void);
    inline bool triangleFit(int sideLength, int topX, int topY, bool isUpsideDown);

    inline void drawContainer(ofstream& stream) const;
    void drawRectangles(ofstream& stream) const;
    void drawCircles(ofstream& stream) const;
    void drawTriangles(ofstream& stream) const;

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

#endif //HW2_COMPOSEDSHAPE_H