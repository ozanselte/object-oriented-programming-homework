//
// Created by ozanselte on 11/24/18.
//

#include "Comparisons.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

bool operator <(const Rectangle& a, const Rectangle& b)
{
    return a.getArea() < b.getArea();
}

bool operator <(const Rectangle& a, const Circle& b)
{
    return a.getArea() < b.getArea();
}

bool operator <(const Rectangle& a, const Triangle& b)
{
    return a.getArea() < b.getArea();
}

bool operator <(const Circle& a, const Rectangle& b)
{
    return a.getArea() < b.getArea();
}

bool operator <(const Circle& a, const Circle& b)
{
    return a.getArea() < b.getArea();
}

bool operator <(const Circle& a, const Triangle& b)
{
    return a.getArea() < b.getArea();
}

bool operator <(const Triangle& a, const Rectangle& b)
{
    return a.getArea() < b.getArea();
}

bool operator <(const Triangle& a, const Circle& b)
{
    return a.getArea() < b.getArea();
}

bool operator <(const Triangle& a, const Triangle& b)
{
    return a.getArea() < b.getArea();
}

bool operator <=(const Rectangle& a, const Rectangle& b)
{
    return a.getArea() <= b.getArea();
}

bool operator <=(const Rectangle& a, const Circle& b)
{
    return a.getArea() <= b.getArea();
}

bool operator <=(const Rectangle& a, const Triangle& b)
{
    return a.getArea() <= b.getArea();
}

bool operator <=(const Circle& a, const Rectangle& b)
{
    return a.getArea() <= b.getArea();
}

bool operator <=(const Circle& a, const Circle& b)
{
    return a.getArea() <= b.getArea();
}

bool operator <=(const Circle& a, const Triangle& b)
{
    return a.getArea() <= b.getArea();
}

bool operator <=(const Triangle& a, const Rectangle& b)
{
    return a.getArea() <= b.getArea();
}

bool operator <=(const Triangle& a, const Circle& b)
{
    return a.getArea() <= b.getArea();
}

bool operator <=(const Triangle& a, const Triangle& b)
{
    return a.getArea() <= b.getArea();
}

bool operator >(const Rectangle& a, const Rectangle& b)
{
    return a.getArea() > b.getArea();
}

bool operator >(const Rectangle& a, const Circle& b)
{
    return a.getArea() > b.getArea();
}

bool operator >(const Rectangle& a, const Triangle& b)
{
    return a.getArea() > b.getArea();
}

bool operator >(const Circle& a, const Rectangle& b)
{
    return a.getArea() > b.getArea();
}

bool operator >(const Circle& a, const Circle& b)
{
    return a.getArea() > b.getArea();
}

bool operator >(const Circle& a, const Triangle& b)
{
    return a.getArea() > b.getArea();
}

bool operator >(const Triangle& a, const Rectangle& b)
{
    return a.getArea() > b.getArea();
}

bool operator >(const Triangle& a, const Circle& b)
{
    return a.getArea() > b.getArea();
}

bool operator >(const Triangle& a, const Triangle& b)
{
    return a.getArea() > b.getArea();
}

bool operator >=(const Rectangle& a, const Rectangle& b)
{
    return a.getArea() >= b.getArea();
}

bool operator >=(const Rectangle& a, const Circle& b)
{
    return a.getArea() >= b.getArea();
}

bool operator >=(const Rectangle& a, const Triangle& b)
{
    return a.getArea() >= b.getArea();
}

bool operator >=(const Circle& a, const Rectangle& b)
{
    return a.getArea() >= b.getArea();
}

bool operator >=(const Circle& a, const Circle& b)
{
    return a.getArea() >= b.getArea();
}

bool operator >=(const Circle& a, const Triangle& b)
{
    return a.getArea() >= b.getArea();
}

bool operator >=(const Triangle& a, const Rectangle& b)
{
    return a.getArea() >= b.getArea();
}

bool operator >=(const Triangle& a, const Circle& b)
{
    return a.getArea() >= b.getArea();
}

bool operator >=(const Triangle& a, const Triangle& b)
{
    return a.getArea() >= b.getArea();
}

bool operator ==(const Rectangle& a, const Rectangle& b)
{
    return a.getArea() == b.getArea();
}

bool operator ==(const Rectangle& a, const Circle& b)
{
    return a.getArea() == b.getArea();
}

bool operator ==(const Rectangle& a, const Triangle& b)
{
    return a.getArea() == b.getArea();
}

bool operator ==(const Circle& a, const Rectangle& b)
{
    return a.getArea() == b.getArea();
}

bool operator ==(const Circle& a, const Circle& b)
{
    return a.getArea() == b.getArea();
}

bool operator ==(const Circle& a, const Triangle& b)
{
    return a.getArea() == b.getArea();
}

bool operator ==(const Triangle& a, const Rectangle& b)
{
    return a.getArea() == b.getArea();
}

bool operator ==(const Triangle& a, const Circle& b)
{
    return a.getArea() == b.getArea();
}

bool operator ==(const Triangle& a, const Triangle& b)
{
    return a.getArea() == b.getArea();
}

bool operator !=(const Rectangle& a, const Rectangle& b)
{
    return a.getArea() != b.getArea();
}

bool operator !=(const Rectangle& a, const Circle& b)
{
    return a.getArea() != b.getArea();
}

bool operator !=(const Rectangle& a, const Triangle& b)
{
    return a.getArea() != b.getArea();
}

bool operator !=(const Circle& a, const Rectangle& b)
{
    return a.getArea() != b.getArea();
}

bool operator !=(const Circle& a, const Circle& b)
{
    return a.getArea() != b.getArea();
}

bool operator !=(const Circle& a, const Triangle& b)
{
    return a.getArea() != b.getArea();
}

bool operator !=(const Triangle& a, const Rectangle& b)
{
    return a.getArea() != b.getArea();
}

bool operator !=(const Triangle& a, const Circle& b)
{
    return a.getArea() != b.getArea();
}

bool operator !=(const Triangle& a, const Triangle& b)
{
    return a.getArea() != b.getArea();
}