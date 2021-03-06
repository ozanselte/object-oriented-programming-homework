//
// Created by ozanselte on 11/24/18.
//

#ifndef HW4_COMPARISONS_H
#define HW4_COMPARISONS_H

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

bool operator <(const Rectangle& a, const Rectangle& b);
bool operator <(const Rectangle& a, const Circle& b);
bool operator <(const Rectangle& a, const Triangle& b);
bool operator <(const Circle& a, const Rectangle& b);
bool operator <(const Circle& a, const Circle& b);
bool operator <(const Circle& a, const Triangle& b);
bool operator <(const Triangle& a, const Rectangle& b);
bool operator <(const Triangle& a, const Circle& b);
bool operator <(const Triangle& a, const Triangle& b);

bool operator <=(const Rectangle& a, const Rectangle& b);
bool operator <=(const Rectangle& a, const Circle& b);
bool operator <=(const Rectangle& a, const Triangle& b);
bool operator <=(const Circle& a, const Rectangle& b);
bool operator <=(const Circle& a, const Circle& b);
bool operator <=(const Circle& a, const Triangle& b);
bool operator <=(const Triangle& a, const Rectangle& b);
bool operator <=(const Triangle& a, const Circle& b);
bool operator <=(const Triangle& a, const Triangle& b);

bool operator >(const Rectangle& a, const Rectangle& b);
bool operator >(const Rectangle& a, const Circle& b);
bool operator >(const Rectangle& a, const Triangle& b);
bool operator >(const Circle& a, const Rectangle& b);
bool operator >(const Circle& a, const Circle& b);
bool operator >(const Circle& a, const Triangle& b);
bool operator >(const Triangle& a, const Rectangle& b);
bool operator >(const Triangle& a, const Circle& b);
bool operator >(const Triangle& a, const Triangle& b);

bool operator >=(const Rectangle& a, const Rectangle& b);
bool operator >=(const Rectangle& a, const Circle& b);
bool operator >=(const Rectangle& a, const Triangle& b);
bool operator >=(const Circle& a, const Rectangle& b);
bool operator >=(const Circle& a, const Circle& b);
bool operator >=(const Circle& a, const Triangle& b);
bool operator >=(const Triangle& a, const Rectangle& b);
bool operator >=(const Triangle& a, const Circle& b);
bool operator >=(const Triangle& a, const Triangle& b);

bool operator ==(const Rectangle& a, const Rectangle& b);
bool operator ==(const Rectangle& a, const Circle& b);
bool operator ==(const Rectangle& a, const Triangle& b);
bool operator ==(const Circle& a, const Rectangle& b);
bool operator ==(const Circle& a, const Circle& b);
bool operator ==(const Circle& a, const Triangle& b);
bool operator ==(const Triangle& a, const Rectangle& b);
bool operator ==(const Triangle& a, const Circle& b);
bool operator ==(const Triangle& a, const Triangle& b);

bool operator !=(const Rectangle& a, const Rectangle& b);
bool operator !=(const Rectangle& a, const Circle& b);
bool operator !=(const Rectangle& a, const Triangle& b);
bool operator !=(const Circle& a, const Rectangle& b);
bool operator !=(const Circle& a, const Circle& b);
bool operator !=(const Circle& a, const Triangle& b);
bool operator !=(const Triangle& a, const Rectangle& b);
bool operator !=(const Triangle& a, const Circle& b);
bool operator !=(const Triangle& a, const Triangle& b);

#endif //HW4_COMPARISONS_H
