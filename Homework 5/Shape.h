//
// Created by ozanselte on 12/19/18.
//

#ifndef HW5_SHAPE_H
#define HW5_SHAPE_H

#include <iostream>
#include <string>

using std::ostream;
using std::string;

enum class ShapeType{
    Rectangle,
    Circle,
    Triangle,
    ComposedShape,
    PolygonVect,
    PolygonDyn
};

class Shape {
public:
    virtual double area() const =0;
    virtual double perimeter() const =0;
    virtual void draw(ostream& stream, string fill, string border) const =0;
    virtual Shape *clone() const =0;
    virtual ShapeType getType() const =0;

    virtual Shape& operator ++() =0;
    virtual const Shape& operator ++(int) =0;
    virtual Shape& operator --() =0;
    virtual const Shape& operator --(int) =0;

    bool operator <(const Shape& right) const;
    bool operator <=(const Shape& right) const;
    bool operator >(const Shape& right) const;
    bool operator >=(const Shape& right) const;
    bool operator ==(const Shape& right) const;
    bool operator !=(const Shape& right) const;
protected:
    /*
     * To make post increments/decrements executable,
     * at least one global or static object is required.
     * When postfix operator function called, tempShape
     * is deleting.
     * */
    static Shape *tempShape;
};

ostream& operator <<(ostream& stream, const Shape& shape);

#endif //HW5_SHAPE_H
