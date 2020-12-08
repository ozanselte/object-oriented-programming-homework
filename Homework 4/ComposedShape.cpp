//
// Created by ozanselte on 11/22/18.
//

#include "ComposedShape.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"

using std::cerr;
using std::endl;
using std::vector;
using std::ostream;
using namespace HW4_SELTE;

ComposedShape::ComposedShape(Rectangle container, Rectangle small)
: rectangleContainer(container), rectangleSmall(small), smallShape(Shape::Rectangle)
{
    setContainerRectangle();
}

ComposedShape::ComposedShape(Rectangle container, Circle small)
: rectangleContainer(container), circleSmall(small), smallShape(Shape::Circle)
{
    setContainerRectangle();
}

ComposedShape::ComposedShape(Rectangle container, Triangle small)
: rectangleContainer(container), triangleSmall(small), smallShape(Shape::Triangle)
{
    setContainerRectangle();
}

ComposedShape::ComposedShape(Circle container, Rectangle small)
: circleContainer(container), rectangleSmall(small), smallShape(Shape::Rectangle)
{
    setContainerCircle();
}

ComposedShape::ComposedShape(Circle container, Circle small)
: circleContainer(container), circleSmall(small), smallShape(Shape::Circle)
{
    setContainerCircle();
}

ComposedShape::ComposedShape(Circle container, Triangle small)
: circleContainer(container), triangleSmall(small), smallShape(Shape::Triangle)
{
    setContainerCircle();
}

ComposedShape::ComposedShape(Triangle container, Rectangle small)
: triangleContainer(container), rectangleSmall(small), smallShape(Shape::Rectangle)
{
    setContainerTriangle();
}

ComposedShape::ComposedShape(Triangle container, Circle small)
: triangleContainer(container), circleSmall(small), smallShape(Shape::Circle)
{
    setContainerTriangle();
}

ComposedShape::ComposedShape(Triangle container, Triangle small)
: triangleContainer(container), triangleSmall(small), smallShape(Shape::Triangle)
{
    setContainerTriangle();
}

ComposedShape::~ComposedShape()
{ /* EMPTY */}

double ComposedShape::getWidth() const
{
    return width;
}

double ComposedShape::getHeight() const
{
    return height;
}

void ComposedShape::optimalFit()
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

int ComposedShape::getSize() const
{
    return smallVector.size();
}

const ComposedShape& ComposedShape::operator +=(const Rectangle& obj)
{
    smallVector.push_back(obj);
    return *this;
}

const ComposedShape& ComposedShape::operator +=(const Circle& obj)
{
    smallVector.push_back(obj);
    return *this;
}

const ComposedShape& ComposedShape::operator +=(const Triangle& obj)
{
    smallVector.push_back(obj);
    return *this;
}

const Polygon& ComposedShape::operator [](int i) const
{
    if(0 > i){
        cerr << "Array index cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    return smallVector[i];
}

inline void ComposedShape::setContainerRectangle(void)
{
    containerShape = Shape::Rectangle;
    width = rectangleContainer.getWidth();
    height = rectangleContainer.getHeight();
}

inline void ComposedShape::setContainerCircle(void)
{
    containerShape = Shape::Circle;
    width = circleContainer.getRadius() * 2;
    height = circleContainer.getRadius() * 2;
}

inline void ComposedShape::setContainerTriangle(void)
{
    containerShape = Shape::Triangle;
    width = triangleContainer.getX(2) - triangleContainer.getX(1);
    height = triangleContainer.getY(1) - triangleContainer.getY(0);
}

inline void ComposedShape::writeSvgBegin(ostream& stream) const
{
    stream <<
           "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" " <<
           "width=\"" << width << "\" " << "height=\"" << height << "\">" <<
           endl;
}

inline void ComposedShape::writeSvgEnd(ostream& stream) const
{
    stream << "</svg>" << endl;
}

inline void ComposedShape::rectangleOptimalFit()
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
                for(decltype(smallVector.size()) k = 0; k < smallVector.size(); k++){
                    const Rectangle *ptr = polygonToRectangle(smallVector[k]);
                    if(!isRectanglesCompatible(temp, *ptr)){
                        compatible = false;
                    }
                    delete ptr;
                }
                if(compatible){
                    smallVector.push_back(Polygon(temp));
                    j += (h-1);
                }
            }
        }
    }
}

inline void ComposedShape::circleOptimalFit()
{
    decltype(circleSmall.getRadius()) radius = circleSmall.getRadius();
    for(int i = 0; i < width-radius+1; i++){
        for(int j = 0; j < height-radius+1; j++){
            Circle temp(radius, i, j);
            if(isCircleFitsContainer(temp)){
                bool compatible = true;
                for(decltype(smallVector.size()) k = 0; k < smallVector.size(); k++){
                    const Circle *ptr = polygonToCircle(smallVector[k]);
                    if(!isCirclesCompatible(temp, *ptr)){
                        compatible = false;
                    }
                    delete ptr;
                }
                if(compatible){
                    smallVector.push_back(temp);
                    j += (radius-1);
                }
            }
        }
    }
}

inline void ComposedShape::triangleOptimalFit()
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
        for(decltype(smallVector.size()) k = 0; k < smallVector.size(); k++){
            const Triangle *ptr = polygonToTriangle(smallVector[k]);
            if(!isTrianglesCompatible(temp, *ptr)){
                compatible = false;
            }
            delete ptr;
        }
        if(compatible){
            smallVector.push_back(temp);
            return true;
        }
    }
    return false;
}

inline void ComposedShape::drawContainer(ostream& stream) const
{
    switch (containerShape){
        case Shape::Rectangle:
            rectangleContainer.draw(stream, "red", "red");
            break;
        case Shape::Circle:
            circleContainer.draw(stream, "red", "red");
            break;
        case Shape::Triangle:
            triangleContainer.draw(stream, "red", "red");
            break;
    }
}

bool ComposedShape::isPointFitsContainer(double pX, double pY) const
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

inline bool ComposedShape::isPointFitsRectangle(double pX, double pY, const Rectangle& obj) const
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

inline bool ComposedShape::isPointFitsCircle(double pX, double pY, const Circle &obj) const
{
    auto x = obj.getX();
    auto y = obj.getY();
    float r = obj.getRadius() - 0.5;
    if((pX-x)*(pX-x) + (pY-y)*(pY-y) <= r*r){
        return true;
    }
    return false;
}

inline bool ComposedShape::isPointFitsTriangle(double pX, double pY, const Triangle &obj) const
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

inline bool ComposedShape::isRectangleFitsContainer(const Rectangle& obj) const
{
    auto w = obj.getWidth() - 1;
    auto h = obj.getHeight() - 1;
    auto x = obj.getX();
    auto y = obj.getY();
    if(isPointFitsContainer(x, y)
       && isPointFitsContainer(x, y + h)
       && isPointFitsContainer(x + w, h)
       && isPointFitsContainer(x + w, y + h)){
        return true;
    }
    return false;
}

inline bool ComposedShape::isCircleFitsContainer(const Circle& obj) const
{
    auto r = obj.getRadius();
    auto x = obj.getX();
    auto y = obj.getY();
    if(isPointFitsContainer(x - r, y - r)
       && isPointFitsContainer(x - r, y + r)
       && isPointFitsContainer(x + r, y - r)
       && isPointFitsContainer(x + r, y + r)){
        return true;
    }
    return false;
}

inline bool ComposedShape::isTriangleFitsContainer(const Triangle& obj) const
{
    double a[] = {obj.getX(0), obj.getY(0)};
    double b[] = {obj.getX(1), obj.getY(1)};
    double c[] = {obj.getX(2), obj.getY(2)};
    if(isPointFitsContainer(a[0], a[1])
       && isPointFitsContainer(b[0], b[1])
       && isPointFitsContainer(c[0], c[1])){
        return true;
    }
    return false;
}

bool ComposedShape::isRectanglesCompatible(const Rectangle& a, const Rectangle& b) const
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

bool ComposedShape::isCirclesCompatible(const Circle& a, const Circle& b) const
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

bool ComposedShape::isTrianglesCompatible(const Triangle& a, const Triangle& b) const
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

ostream& operator <<(ostream& stream, const ComposedShape& obj)
{
    obj.writeSvgBegin(stream);
    obj.drawContainer(stream);
    for (int i = 0; i < obj.getSize(); ++i) {
        stream << obj[i];
    }
    obj.writeSvgEnd(stream);
    return stream;
}

namespace {
    const Rectangle *polygonToRectangle(const Polygon& obj)
    {
        double leftX, leftY, rightX, rightY;
        leftX = obj[0].getX();
        leftY = obj[0].getY();
        rightX = leftX;
        rightY = leftY;
        for (int i = 1; i < obj.getSize(); ++i) {
            double tX = obj[i].getX();
            double tY = obj[i].getY();
            if(tX < leftX) leftX = tX;
            if(tY < leftY) leftY = tY;
            if(tX > rightX) rightX = tX;
            if(tY > rightY) rightY = tY;
        }
        return new Rectangle(abs(rightX-leftX), abs(rightY-leftY), leftX, leftY);
    }

    const Circle *polygonToCircle(const Polygon& obj)
    {
        double topX, topY, bottomX, bottomY;
        topX = obj[0].getX();
        topY = obj[0].getY();
        bottomX = topX;
        bottomY = topY;
        for (int i = 1; i < obj.getSize(); ++i) {
            double tX = obj[i].getX();
            double tY = obj[i].getY();
            if(tX < topX) topX = tX;
            if(tY < topY) topY = tY;
            if(tX > bottomX) bottomX = tX;
            if(tY > bottomY) bottomY = tY;
        }
        return new Circle(abs(topX-bottomX) / 2, (topX+bottomX) / 2, (topY+bottomY) / 2);
    }

    const Triangle *polygonToTriangle(const Polygon& obj)
    {
        double a[] = {obj[0].getX(), obj[0].getY()};
        double b[] = {obj[1].getX(), obj[1].getY()};
        double c[] = {obj[2].getX(), obj[2].getY()};
        double sideLength = c[0] - b[0];
        bool isUpsideDown = b[1] > a[1];
        return new Triangle(sideLength, a[0], a[1], isUpsideDown);
    }
}