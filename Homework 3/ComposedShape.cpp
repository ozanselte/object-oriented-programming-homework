//
// Created by ozanselte on 10/26/18.
//

#include "ComposedShape.h"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

ComposedShape::ComposedShape(Rectangle container, Rectangle small)
: rectangleContainer(container), rectangleSmall(small)
{
    setContainerRectangle();
    setSmallRectangle();
}

ComposedShape::ComposedShape(Rectangle container, Circle small)
: rectangleContainer(container), circleSmall(small)
{
    setContainerRectangle();
    setSmallCircle();
}

ComposedShape::ComposedShape(Rectangle container, Triangle small)
: rectangleContainer(container), triangleSmall(small)
{
    setContainerRectangle();
    setSmallTriangle();
}

ComposedShape::ComposedShape(Circle container, Rectangle small)
: circleContainer(container), rectangleSmall(small)
{
    setContainerCircle();
    setSmallRectangle();
}

ComposedShape::ComposedShape(Circle container, Circle small)
: circleContainer(container), circleSmall(small)
{
    setContainerCircle();
    setSmallCircle();
}

ComposedShape::ComposedShape(Circle container, Triangle small)
: circleContainer(container), triangleSmall(small)
{
    setContainerCircle();
    setSmallTriangle();
}

ComposedShape::ComposedShape(Triangle container, Rectangle small)
: triangleContainer(container), rectangleSmall(small)
{
    setContainerTriangle();
    setSmallRectangle();
}

ComposedShape::ComposedShape(Triangle container, Circle small)
: triangleContainer(container), circleSmall(small)
{
    setContainerTriangle();
    setSmallCircle();
}

ComposedShape::ComposedShape(Triangle container, Triangle small)
: triangleContainer(container), triangleSmall(small)
{
    setContainerTriangle();
    setSmallTriangle();
}

void ComposedShape::setColors(string container, string small, string stroke)
{
    setContainerColor(container);
    setSmallColor(small);
    setStrokeColor(stroke);
}

void ComposedShape::setContainerColor(string color)
{
    containerColor = color;
}

void ComposedShape::setSmallColor(string color)
{
    smallColor = color;
}

void ComposedShape::setStrokeColor(string color)
{
    strokeColor = color;
}

int ComposedShape::getWidth(void) const
{
    return width;
}

int ComposedShape::getHeight(void) const
{
    return height;
}

Shape ComposedShape::getContainerShape(void) const
{
    return containerShape;
}

Shape ComposedShape::getSmallShape(void) const
{
    return smallShape;
}

string ComposedShape::getContainerColor(void) const
{
    return containerColor;
}

string ComposedShape::getSmallColor(void) const
{
    return smallColor;
}

string ComposedShape::getStrokeColor(void) const
{
    return strokeColor;
}

void ComposedShape::optimalFit(void)
{
    switch (smallShape){
        case Shape::Rectangle:
            rectangleOptimalFit();
            break;
        case Shape::Circle:
            circleOptimalFit();
            break;
        case Shape::Triangle:
            triangleOptimalFit();
            break;
    }
}

void ComposedShape::draw(ostream& stream) const
{
    writeSvgBegin(stream);
    drawContainer(stream);
    switch (smallShape){
        case Shape::Rectangle:
            drawRectangles(stream);
            break;
        case Shape::Circle:
            drawCircles(stream);
            break;
        case Shape::Triangle:
            drawTriangles(stream);
            break;
    }
    writeSvgEnd(stream);
}

void ComposedShape::setContainerRectangle(void)
{
    containerShape = Shape::Rectangle;
    width = rectangleContainer.getWidth();
    height = rectangleContainer.getHeight();

}

void ComposedShape::setContainerCircle(void)
{
    containerShape = Shape::Circle;
    width = circleContainer.getRadius() * 2;
    height = circleContainer.getRadius() * 2;
}

void ComposedShape::setContainerTriangle(void)
{
    containerShape = Shape::Triangle;
    width = triangleContainer.getX(2) - triangleContainer.getX(1);
    height = triangleContainer.getY(1) - triangleContainer.getY(0);
}

void ComposedShape::setSmallRectangle(void)
{
    smallShape = Shape::Rectangle;
}

void ComposedShape::setSmallCircle(void)
{
    smallShape = Shape::Circle;
}

void ComposedShape::setSmallTriangle(void)
{
    smallShape = Shape::Triangle;
}

void ComposedShape::writeSvgBegin(ostream& stream) const
{
    stream <<
    "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" " <<
    "width=\"" << width << "\" "
    << "height=\"" << height << "\">" <<
    endl;
}

void ComposedShape::writeSvgEnd(ostream& stream) const
{
    stream <<
    "</svg>" <<
    endl;
}

inline void ComposedShape::rectangleOptimalFit(void)
{
    bool doItHorizontal = (rectangleSmall.getHeight() > rectangleSmall.getWidth());
    if(doItHorizontal){
        rectangleFit(rectangleSmall.getHeight(), rectangleSmall.getWidth());
        rectangleFit(rectangleSmall.getWidth(), rectangleSmall.getHeight());
    }
    else{
        rectangleFit(rectangleSmall.getWidth(), rectangleSmall.getHeight());
        rectangleFit(rectangleSmall.getHeight(), rectangleSmall.getWidth());
    }
}

inline void ComposedShape::rectangleFit(int w, int h)
{
    for(int i = 0; i < width-w+1; i++){
        for(int j = 0; j < height-h+1; j++){
            Rectangle temp(w, h, i, j);
            if(isRectangleFitsContainer(temp)){
                bool compatible = true;
                for(decltype(shapeVector.size()) k = 0; k < shapeVector.size(); k++){
                    if(!isRectanglesCompatible(temp, *static_cast<Rectangle *>(shapeVector[k].getShape()))){
                        compatible = false;
                    }
                }
                if(compatible){
                    shapeVector.push_back(ShapeElem(temp));
                    j += (h-1);
                }
            }
        }
    }
}

inline void ComposedShape::circleOptimalFit(void)
{
    decltype(circleSmall.getRadius()) radius = circleSmall.getRadius();
    for(int i = 0; i < width-radius+1; i++){
        for(int j = 0; j < height-radius+1; j++){
            Circle temp(radius, i, j);
            if(isCircleFitsContainer(temp)){
                bool compatible = true;
                for(decltype(shapeVector.size()) k = 0; k < shapeVector.size(); k++){
                    if(!isCirclesCompatible(temp, *static_cast<Circle *>(shapeVector[k].getShape()))){
                        compatible = false;
                    }
                }
                if(compatible){
                    shapeVector.push_back(ShapeElem(temp));
                    j += (radius-1);
                }
            }
        }
    }
}

inline void ComposedShape::triangleOptimalFit(void)
{
    auto triangleH = abs(triangleSmall.getY(1) - triangleSmall.getY(0));
    auto sideLength = abs(triangleSmall.getX(2) - triangleSmall.getX(1));
    decltype(sideLength) halfSide = sideLength / 2.0;
    for(int j = 0; j < height-triangleH+1; j++){
        for(int i = halfSide; i < width-halfSide+1; i++){
            auto fit = triangleFit(sideLength, i, j, false);
            if(fit){
                j += (triangleH - 1);
            }
        }
    }
    for(int i = 0; i < width-halfSide+1; i++){
        for(int j = 0; j < height+1; j++){
            auto fit = triangleFit(sideLength, i, j, true);
            if(fit){
                j += (triangleH - 1);
            }
        }
    }
}

inline bool ComposedShape::triangleFit(int sideLength, int topX, int topY, bool isUpsideDown)
{
    Triangle temp(sideLength, topX, topY, isUpsideDown);
    if(isTriangleFitsContainer(temp)){
        bool compatible = true;
        for(decltype(shapeVector.size()) k = 0; k < shapeVector.size(); k++){
            if(!isTrianglesCompatible(temp, *static_cast<Triangle *>(shapeVector[k].getShape()))){
                compatible = false;
            }
        }
        if(compatible){
            shapeVector.push_back(ShapeElem(temp));
            return true;
        }
    }
    return false;
}

inline void ComposedShape::drawContainer(ostream& stream) const
{
    switch (containerShape){
        case Shape::Rectangle:
            rectangleContainer.draw(stream, containerColor, containerColor);
            break;
        case Shape::Circle:
            circleContainer.draw(stream, containerColor, containerColor);
            break;
        case Shape::Triangle:
            triangleContainer.draw(stream, containerColor, containerColor);
            break;
    }
}

void ComposedShape::drawRectangles(ostream& stream) const
{
    for(decltype(shapeVector.size()) i = 0; i < shapeVector.size(); i++){
        stream << *static_cast<Rectangle *>(shapeVector[i].getShape());
    }
}

void ComposedShape::drawCircles(ostream& stream) const
{
    for(decltype(shapeVector.size()) i = 0; i < shapeVector.size(); i++){
        stream << *static_cast<Rectangle *>(shapeVector[i].getShape());
    }
}

void ComposedShape::drawTriangles(ostream& stream) const
{
    for(decltype(shapeVector.size()) i = 0; i < shapeVector.size(); i++){
        stream << *static_cast<Rectangle *>(shapeVector[i].getShape());
    }
}

bool ComposedShape::isPointFitsContainer(int pX, int pY) const
{
    switch (containerShape){
        case Shape::Rectangle:
            if(isPointFitsRectangle(pX, pY, rectangleContainer)){
                return true;
            }
            break;
        case Shape::Circle:
            if(isPointFitsCircle(pX, pY, circleContainer)){
                return true;
            }
            break;
        case Shape::Triangle:
            if(isPointFitsTriangle(pX, pY, triangleContainer)){
                return true;
            }
            break;
    }
    return false;
}

inline bool ComposedShape::isPointFitsRectangle(int pX, int pY, const Rectangle& obj) const
{
    auto w = obj.getWidth();
    auto h = obj.getHeight();
    auto x = obj.getX();
    auto y = obj.getY();
    if((x > pX) || (pX >= x + w)
    || (y > pY) || (pY >= y + h)){
        return false;
    }
    return true;
}

inline bool ComposedShape::isPointFitsCircle(int pX, int pY, const Circle& obj) const
{
    auto x = obj.getX();
    auto y = obj.getY();
    float r = obj.getRadius() - 0.5;
    if((pX-x)*(pX-x) + (pY-y)*(pY-y) <= r*r){
        return true;
    }
    return false;
}

inline bool ComposedShape::isPointFitsTriangle(int pX, int pY, const Triangle& obj) const
{
    auto a = obj.getX(0);
    auto b = obj.getY(0);
    auto border = obj.getY(1);
    auto isUpsideDown = (obj.getY(1) < obj.getY(0));
    if(isUpsideDown){
        if((pY - b) < (tan(120.0 * (180.0 / M_PI)) * (pX - a))
           && (pY - b) < (tan(60.0 * (180.0 / M_PI)) * (pX - a))){
            if(pY > border) {
                return true;
            }
        }
    }
    else{
        if((pY - b) >= (tan(120.0 * (180.0 / M_PI)) * (pX - a))
           && (pY - b) >= (tan(60.0 * (180.0 / M_PI)) * (pX - a))){
            if(pY < border){
                return true;
            }
        }
    }
    return false;
}

inline bool ComposedShape::isRectangleFitsContainer(const Rectangle& temp) const
{
    auto w = temp.getWidth() - 1;
    auto h = temp.getHeight() - 1;
    auto x = temp.getX();
    auto y = temp.getY();
    if(isPointFitsContainer(x, y)
    && isPointFitsContainer(x, y + h)
    && isPointFitsContainer(x + w, h)
    && isPointFitsContainer(x + w, y + h)){
        return true;
    }
    return false;
}

inline bool ComposedShape::isCircleFitsContainer(const Circle& temp) const
{
    auto r = temp.getRadius();
    auto x = temp.getX();
    auto y = temp.getY();
    if(isPointFitsContainer(x - r, y - r)
    && isPointFitsContainer(x - r, y + r)
    && isPointFitsContainer(x + r, y - r)
    && isPointFitsContainer(x + r, y + r)){
        return true;
    }
    return false;
}

inline bool ComposedShape::isTriangleFitsContainer(const Triangle& temp) const
{
    double a[] = {temp.getX(0), temp.getY(0)};
    double b[] = {temp.getX(1), temp.getY(1)};
    double c[] = {temp.getX(2), temp.getY(2)};
    if(isPointFitsContainer(a[0], a[1])
    && isPointFitsContainer(b[0], b[1])
    && isPointFitsContainer(c[0], c[1])){
        return true;
    }
    return false;
}

bool ComposedShape::isRectanglesCompatible(const Rectangle& a, const Rectangle& b)
{
    auto aw = a.getWidth();
    auto ah = a.getHeight();
    auto ax = a.getX();
    auto ay = a.getY();
    for(int i = ax; i < ax + aw; i++){
        for(int j = ay; j < ay + ah; j++){
            if(isPointFitsRectangle(i, j, b)){
                return false;
            }
        }
    }
    return true;
}

bool ComposedShape::isCirclesCompatible(const Circle& a, const Circle& b)
{
    auto ar = a.getRadius();
    auto ax = a.getX();
    auto ay = a.getY();
    for(int i = ax - ar; i < ax + ar - 1; i++){
        for(int j = ay - ar; j < ay + ar - 1; j++){
            if(isPointFitsCircle(i, j, b)){
                return false;
            }
        }
    }
    return true;
}

bool ComposedShape::isTrianglesCompatible(const Triangle& a, const Triangle& b)
{
    double xA[] = {a.getX(0), a.getX(1), a.getX(2)};
    double yA[] = {a.getY(0), a.getY(1), a.getY(2)};
    for(int i = 0; i < 3; i++){
        if(isPointFitsTriangle(xA[i], yA[i], b)){
            return false;
        }
    }
    return true;
}

const ComposedShape& ComposedShape::operator +=(Rectangle& obj)
{
    shapeVector.push_back(ShapeElem(obj));
    return *this;
}

const ComposedShape& ComposedShape::operator +=(Circle& obj)
{
    shapeVector.push_back(ShapeElem(obj));
    return *this;
}

const ComposedShape& ComposedShape::operator +=(Triangle& obj)
{
    shapeVector.push_back(ShapeElem(obj));
    return *this;
}

const ComposedShape::ShapeElem& ComposedShape::operator [](int i)
{
    if(shapeVector.size() < i){
        cerr << "Vector index cannot be larger than vector size." << endl;
        exit(EXIT_FAILURE);
    }
    return shapeVector[i];
}

ComposedShape::ShapeElem::ShapeElem(Rectangle& obj)
{
    shape = new Rectangle(obj);
    shapeType = Shape::Rectangle;
}

ComposedShape::ShapeElem::ShapeElem(Circle& obj)
{
    shape = new Circle(obj);
    shapeType = Shape::Circle;
}

ComposedShape::ShapeElem::ShapeElem(Triangle& obj)
{
    shape = new Triangle(obj);
    shapeType = Shape::Triangle;
}

double ComposedShape::ShapeElem::getPerimeter(void) const
{
    switch (shapeType){
        case Shape::Rectangle:
            return static_cast<Rectangle *>(shape)->getPerimeter();
        case Shape::Circle:
            return static_cast<Circle *>(shape)->getPerimeter();
        case Shape::Triangle:
            return static_cast<Triangle *>(shape)->getPerimeter();
    }
    return 0.0;
}

double ComposedShape::ShapeElem::getArea(void) const
{
    switch (shapeType){
        case Shape::Rectangle:
            return static_cast<Rectangle *>(shape)->getArea();
        case Shape::Circle:
            return static_cast<Circle *>(shape)->getArea();
        case Shape::Triangle:
            return static_cast<Triangle *>(shape)->getArea();
    }
    return 0.0;
}

Shape ComposedShape::ShapeElem::getShapeType(void) const
{
    return shapeType;
}

void * ComposedShape::ShapeElem::getShape(void) const
{
    return shape;
}

ostream& operator <<(ostream& stream, const ComposedShape& obj)
{
    obj.draw(stream);
    return stream;
}

ostream& operator <<(ostream& stream, const ComposedShape::ShapeElem& obj)
{
    switch (obj.shapeType){
        case Shape::Rectangle:
            stream << *static_cast<Rectangle *>(obj.shape);
            break;
        case Shape::Circle:
            stream << *static_cast<Circle *>(obj.shape);
            break;
        case Shape::Triangle:
            stream << *static_cast<Triangle *>(obj.shape);
            break;
    }
    return stream;
}