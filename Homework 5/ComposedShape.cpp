//
// Created by ozanselte on 12/19/18.
//

#include "ComposedShape.h"
#include <stdexcept>
#include <cmath>

using std::out_of_range;
using std::endl;

ComposedShape::ComposedShape(const Rectangle& c, const Rectangle& s)
: container(new Rectangle(c)), small(new Rectangle(s))
{
    setContainerRectangle();
    setSmallRectangle();
}

ComposedShape::ComposedShape(const Rectangle& c, const Circle& s)
: container(new Rectangle(c)), small(new Circle(s))
{
    setContainerRectangle();
    setSmallCircle();
}

ComposedShape::ComposedShape(const Rectangle& c, const Triangle& s)
: container(new Rectangle(c)), small(new Triangle(s))
{
    setContainerRectangle();
    setSmallTriangle();
}

ComposedShape::ComposedShape(const Circle& c, const Rectangle& s)
: container(new Circle(c)), small(new Rectangle(s))
{
    setContainerCircle();
    setSmallRectangle();
}

ComposedShape::ComposedShape(const Circle& c, const Circle& s)
: container(new Circle(c)), small(new Circle(s))
{
    setContainerCircle();
    setSmallCircle();
}

ComposedShape::ComposedShape(const Circle& c, const Triangle& s)
: container(new Circle(c)), small(new Triangle(s))
{
    setContainerCircle();
    setSmallTriangle();
}

ComposedShape::ComposedShape(const Triangle& c, const Rectangle& s)
: container(new Triangle(c)), small(new Rectangle(s))
{
    setContainerTriangle();
    setSmallRectangle();
}

ComposedShape::ComposedShape(const Triangle& c, const Circle& s)
: container(new Triangle(c)), small(new Circle(s))
{
    setContainerTriangle();
    setSmallCircle();
}

ComposedShape::ComposedShape(const Triangle& c, const Triangle& s)
: container(new Triangle(c)), small(new Triangle(s))
{
    setContainerTriangle();
    setSmallTriangle();
}

ComposedShape::ComposedShape(const ComposedShape& obj)
{
    container = obj.container->clone();
    small = obj.small->clone();
    for(auto shape : obj.shapeVector){
        shapeVector.push_back(shape->clone());
    }
}

ComposedShape& ComposedShape::operator =(const ComposedShape& obj)
{
    delete container;
    delete small;
    for(auto shape : shapeVector){
        delete shape;
    }
    container = obj.container->clone();
    small = obj.small->clone();
    for(auto shape : obj.shapeVector){
        shapeVector.push_back(shape->clone());
    }
    return *this;
}

ComposedShape::~ComposedShape()
{
    delete container;
    delete small;
    for(auto shape : shapeVector){
        delete shape;
    }
}

void ComposedShape::optimalFit()
{
    switch (smallShape){
        case ShapeType::Rectangle:
            rectangleOptimalFit();
            break;
        case ShapeType::Circle:
            circleOptimalFit();
            break;
        case ShapeType::Triangle:
            triangleOptimalFit();
            break;
    }
}

const ComposedShape& ComposedShape::operator +=(const Rectangle& obj)
{
    shapeVector.push_back(new Rectangle(obj));
    return *this;
}

const ComposedShape& ComposedShape::operator +=(const Circle& obj)
{
    shapeVector.push_back(new Circle(obj));
    return *this;
}

const ComposedShape& ComposedShape::operator +=(const Triangle& obj)
{
    shapeVector.push_back(new Triangle(obj));
    return *this;
}

const Shape& ComposedShape::operator [](int i)
{
    if(shapeVector.size() < i){
        throw out_of_range("Vector index cannot be higher than vector size!");
    }
    else if(0 > i){
        throw out_of_range("Vector index cannot be lower than 0!");
    }
    return *shapeVector[i];
}

vector<Shape *> ComposedShape::getShapeVector() const
{
    return shapeVector;
}

double ComposedShape::area() const
{
    return container->area();
}

double ComposedShape::perimeter() const
{
    return container->perimeter();
}

void ComposedShape::draw(ostream& stream, string fill, string border) const
{
    writeSvgBegin(stream);
    container->draw(stream, "red", "black");
    for(auto shape : shapeVector){
        shape->draw(stream, fill, border);
    }
    writeSvgEnd(stream);
}

ComposedShape *ComposedShape::clone() const
{
    ComposedShape *copy = new ComposedShape(*this);
    return copy;
}

ComposedShape& ComposedShape::operator ++()
{
    for(auto shape : shapeVector){
        ++(*shape);
    }
    return *this;
}

ComposedShape& ComposedShape::operator --()
{
    for(auto shape : shapeVector){
        --(*shape);
    }
    return *this;
}

const ComposedShape& ComposedShape::operator ++(int)
{
    delete tempShape;
    tempShape = dynamic_cast<Shape *>(this->clone());
    ++(*this);
    return *dynamic_cast<ComposedShape *>(tempShape);
}

const ComposedShape& ComposedShape::operator --(int)
{
    delete tempShape;
    tempShape = dynamic_cast<Shape *>(this->clone());
    --(*this);
    return *dynamic_cast<ComposedShape *>(tempShape);
}

void ComposedShape::setContainerRectangle()
{
    containerShape = ShapeType::Rectangle;
    width = dynamic_cast<Rectangle *>(container)->getWidth();
    height = dynamic_cast<Rectangle *>(container)->getHeight();
}

void ComposedShape::setContainerCircle()
{
    containerShape = ShapeType::Circle;
    width = dynamic_cast<Circle *>(container)->getRadius() * 2;
    height = dynamic_cast<Circle *>(container)->getRadius() * 2;
}

void ComposedShape::setContainerTriangle()
{
    containerShape = ShapeType::Triangle;
    width = dynamic_cast<Triangle *>(container)->getX(2) - dynamic_cast<Triangle *>(container)->getX(1);
    height = dynamic_cast<Triangle *>(container)->getY(1) - dynamic_cast<Triangle *>(container)->getY(0);
}

void ComposedShape::setSmallRectangle()
{
    smallShape = ShapeType::Rectangle;
}

void ComposedShape::setSmallCircle()
{
    smallShape = ShapeType::Circle;
}

void ComposedShape::setSmallTriangle()
{
    smallShape = ShapeType::Triangle;
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

void ComposedShape::rectangleOptimalFit()
{
    Rectangle *rectangleSmall = dynamic_cast<Rectangle *>(small);
    bool doItHorizontal = (rectangleSmall->getHeight() > rectangleSmall->getWidth());
    if(doItHorizontal){
        rectangleFit(rectangleSmall->getHeight(), rectangleSmall->getWidth());
        rectangleFit(rectangleSmall->getWidth(), rectangleSmall->getHeight());
    }
    else{
        rectangleFit(rectangleSmall->getWidth(), rectangleSmall->getHeight());
        rectangleFit(rectangleSmall->getHeight(), rectangleSmall->getWidth());
    }
}

void ComposedShape::rectangleFit(int w, int h)
{
    for(int i = 0; i < width-w+1; i++){
        for(int j = 0; j < height-h+1; j++){
            Rectangle *temp = new Rectangle(w, h, i, j);
            if(isRectangleFitsContainer(temp)){
                bool compatible = true;
                for(decltype(shapeVector.size()) k = 0; k < shapeVector.size(); k++){
                    if(!isRectanglesCompatible(temp, dynamic_cast<Rectangle *>(shapeVector[k]))){
                        compatible = false;
                    }
                }
                if(compatible){
                    shapeVector.push_back(temp);
                    j += (h-1);
                }
                else{
                    delete temp;
                }
            }
        }
    }
}

void ComposedShape::circleOptimalFit()
{
    Circle *circleSmall = dynamic_cast<Circle *>(small);
    decltype(circleSmall->getRadius()) radius = circleSmall->getRadius();
    for(int i = 0; i < width-radius+1; i++){
        for(int j = 0; j < height-radius+1; j++){
            Circle *temp = new Circle(radius, i, j);
            if(isCircleFitsContainer(temp)){
                bool compatible = true;
                for(decltype(shapeVector.size()) k = 0; k < shapeVector.size(); k++){
                    if(!isCirclesCompatible(temp, dynamic_cast<Circle *>(shapeVector[k]))){
                        compatible = false;
                    }
                }
                if(compatible){
                    shapeVector.push_back(temp);
                    j += (radius-1);
                }
                else{
                    delete temp;
                }
            }
        }
    }
}

void ComposedShape::triangleOptimalFit()
{
    Triangle *triangleSmall = dynamic_cast<Triangle *>(small);
    auto triangleH = abs(triangleSmall->getY(1) - triangleSmall->getY(0));
    auto sideLength = abs(triangleSmall->getX(2) - triangleSmall->getX(1));
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

bool ComposedShape::triangleFit(int sideLength, int topX, int topY, bool isUpsideDown)
{
    Triangle *temp = new Triangle(sideLength, topX, topY, isUpsideDown);
    if(isTriangleFitsContainer(temp)){
        bool compatible = true;
        for(decltype(shapeVector.size()) k = 0; k < shapeVector.size(); k++){
            if(!isTrianglesCompatible(temp, dynamic_cast<Triangle *>(shapeVector[k]))){
                compatible = false;
            }
        }
        if(compatible){
            shapeVector.push_back(temp);
            return true;
        }
        else{
            delete temp;
        }
    }
    return false;
}

bool ComposedShape::isPointFitsContainer(int pX, int pY) const
{
    switch (containerShape){
        case ShapeType::Rectangle:
            if(isPointFitsRectangle(pX, pY, dynamic_cast<Rectangle *>(container))){
                return true;
            }
            break;
        case ShapeType::Circle:
            if(isPointFitsCircle(pX, pY, dynamic_cast<Circle *>(container))){
                return true;
            }
            break;
        case ShapeType::Triangle:
            if(isPointFitsTriangle(pX, pY, dynamic_cast<Triangle *>(container))){
                return true;
            }
            break;
    }
    return false;
}

bool ComposedShape::isPointFitsRectangle(int pX, int pY, const Rectangle *obj) const
{
    auto w = obj->getWidth();
    auto h = obj->getHeight();
    auto x = obj->getX();
    auto y = obj->getY();
    if((x > pX) || (pX >= x + w)
       || (y > pY) || (pY >= y + h)){
        return false;
    }
    return true;
}

bool ComposedShape::isPointFitsCircle(int pX, int pY, const Circle *obj) const
{
    auto x = obj->getX();
    auto y = obj->getY();
    float r = obj->getRadius() - 0.5;
    if((pX-x)*(pX-x) + (pY-y)*(pY-y) <= r*r){
        return true;
    }
    return false;
}

bool ComposedShape::isPointFitsTriangle(int pX, int pY, const Triangle *obj) const
{
    auto a = obj->getX(0);
    auto b = obj->getY(0);
    auto border = obj->getY(1);
    auto isUpsideDown = (obj->getY(1) < obj->getY(0));
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

bool ComposedShape::isRectangleFitsContainer(const Rectangle *obj) const
{
    auto w = obj->getWidth() - 1;
    auto h = obj->getHeight() - 1;
    auto x = obj->getX();
    auto y = obj->getY();
    if(isPointFitsContainer(x, y)
       && isPointFitsContainer(x, y + h)
       && isPointFitsContainer(x + w, h)
       && isPointFitsContainer(x + w, y + h)){
        return true;
    }
    return false;
}

bool ComposedShape::isCircleFitsContainer(const Circle *obj) const
{
    auto r = obj->getRadius();
    auto x = obj->getX();
    auto y = obj->getY();
    if(isPointFitsContainer(x - r, y - r)
       && isPointFitsContainer(x - r, y + r)
       && isPointFitsContainer(x + r, y - r)
       && isPointFitsContainer(x + r, y + r)){
        return true;
    }
    return false;
}

bool ComposedShape::isTriangleFitsContainer(const Triangle *obj) const
{
    double a[] = {obj->getX(0), obj->getY(0)};
    double b[] = {obj->getX(1), obj->getY(1)};
    double c[] = {obj->getX(2), obj->getY(2)};
    if(isPointFitsContainer(a[0], a[1])
       && isPointFitsContainer(b[0], b[1])
       && isPointFitsContainer(c[0], c[1])){
        return true;
    }
    return false;
}

bool ComposedShape::isRectanglesCompatible(const Rectangle *a, const Rectangle *b)
{
    auto aw = a->getWidth();
    auto ah = a->getHeight();
    auto ax = a->getX();
    auto ay = a->getY();
    for(int i = ax; i < ax + aw; i++){
        for(int j = ay; j < ay + ah; j++){
            if(isPointFitsRectangle(i, j, b)){
                return false;
            }
        }
    }
    return true;
}

bool ComposedShape::isCirclesCompatible(const Circle *a, const Circle *b)
{
    auto ar = a->getRadius();
    auto ax = a->getX();
    auto ay = a->getY();
    for(int i = ax - ar; i < ax + ar - 1; i++){
        for(int j = ay - ar; j < ay + ar - 1; j++){
            if(isPointFitsCircle(i, j, b)){
                return false;
            }
        }
    }
    return true;
}

bool ComposedShape::isTrianglesCompatible(const Triangle *a, const Triangle *b)
{
    double xA[] = {a->getX(0), a->getX(1), a->getX(2)};
    double yA[] = {a->getY(0), a->getY(1), a->getY(2)};
    for(int i = 0; i < 3; i++){
        if(isPointFitsTriangle(xA[i], yA[i], b)){
            return false;
        }
    }
    return true;
}