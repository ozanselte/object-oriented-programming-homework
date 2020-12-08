//
// Created by ozanselte on 12/19/18.
//

#include "Rectangle.h"

using std::endl;

Rectangle::Rectangle()
{
    setSize(0, 0);
    setLocation(0, 0);
}

Rectangle::Rectangle(double w, double h)
{
    setSize(w, h);
    setLocation(0, 0);
}

Rectangle::Rectangle(double w, double h, double _x, double _y)
{
    setSize(w, h);
    setLocation(_x, _y);
}

void Rectangle::setSize(double w, double h)
{
    setWidth(w);
    setHeight(h);
}

void Rectangle::setLocation(double _x, double _y)
{
    setX(_x);
    setY(_y);
}

void Rectangle::setWidth(double w) throw(out_of_range)
{
    if(0 > w){
        throw out_of_range("Rectangle width cannot be lower than 0!");
    }
    width = w;
}

void Rectangle::setHeight(double h) throw(out_of_range)
{
    if(0 > h){
        throw out_of_range("Rectangle height cannot be lower than 0!");
    }
    height = h;
}

void Rectangle::setX(double _x) throw(out_of_range)
{
    if(0 > _x){
        throw out_of_range("Rectangle X-coordinate cannot be lower than 0!");
    }
    x = _x;
}

void Rectangle::setY(double _y) throw(out_of_range)
{
    if(0 > _y){
        throw out_of_range("Rectangle Y-coordinate cannot be lower than 0!");
    }
    y = _y;
}

double Rectangle::area() const
{
    return width * height;
}

double Rectangle::perimeter() const
{
    return 2 * (width + height);
}

void Rectangle::draw(ostream& stream, string fill, string border) const
{
    stream <<
           "<rect " <<
           "width=\"" << width << "\" " <<
           "height=\"" << height << "\" " <<
           "x=\"" << x << "\" " <<
           "y=\"" << y << "\" " <<
           "fill=\"" << fill << "\" " <<
           "stroke=\"" << border << "\" />" <<
           endl;
}

Rectangle *Rectangle::clone() const
{
    Rectangle *copy = new Rectangle(*this);
    return copy;
}

Rectangle& Rectangle::operator ++()
{
    ++x;
    ++y;
    return *this;
}

Rectangle& Rectangle::operator --()
{
    --x;
    --y;
    return *this;
}

const Rectangle& Rectangle::operator ++(int)
{
    delete tempShape;
    tempShape = dynamic_cast<Shape *>(this->clone());
    ++(*this);
    return *dynamic_cast<Rectangle *>(tempShape);
}

const Rectangle& Rectangle::operator --(int)
{
    delete tempShape;
    tempShape = dynamic_cast<Shape *>(this->clone());
    --(*this);
    return *dynamic_cast<Rectangle *>(tempShape);
}