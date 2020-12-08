//
// Created by ozanselte on 12/19/18.
//

#include "Shape.h"
#include <string>

using std::string;

Shape *Shape::tempShape = nullptr;

bool Shape::operator <(const Shape& right) const
{
    return area() < right.area();
}

bool Shape::operator <=(const Shape& right) const
{
    return area() <= right.area();
}

bool Shape::operator >(const Shape& right) const
{
    return area() > right.area();
}

bool Shape::operator >=(const Shape& right) const
{
    return area() >= right.area();
}

bool Shape::operator ==(const Shape& right) const
{
    return area() == right.area();
}

bool Shape::operator !=(const Shape& right) const
{
    return area() != right.area();
}

ostream& operator <<(ostream& stream, const Shape& shape)
{
    shape.draw(stream, "green", "red");
    return stream;
}