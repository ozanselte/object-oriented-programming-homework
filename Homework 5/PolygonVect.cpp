//
// Created by ozanselte on 12/20/18.
//

#include "PolygonVect.h"
#include <cmath>

PolygonVect::PolygonVect(const Rectangle& obj)
{
    a = obj.area();
    p = obj.perimeter();
    pointVector.push_back(Point2D(obj.getX(), obj.getY()));
    pointVector.push_back(Point2D(obj.getX(), obj.getY() + obj.getWidth()));
    pointVector.push_back(Point2D(obj.getX() + obj.getHeight(), obj.getY() + obj.getWidth()));
    pointVector.push_back(Point2D(obj.getX() + obj.getHeight(), obj.getY()));
}

PolygonVect::PolygonVect(const Circle& obj)
{
    a = obj.area();
    p = obj.perimeter();
    for (int i = 0; i < 100; ++i) {
        pointVector.push_back(Point2D(cos(2*i*M_PI / 100) * obj.getRadius() + obj.getX(),
                            sin(2*i*M_PI / 100) * obj.getRadius() + obj.getY()));
    }
}

PolygonVect::PolygonVect(const Triangle& obj)
{
    a = obj.area();
    p = obj.perimeter();
    for (int i = 0; i < 3; ++i) {
        pointVector.push_back(Point2D(obj.getX(i), obj.getY(i)));
    }
}

PolygonVect *PolygonVect::clone() const
{
    PolygonVect *copy = new PolygonVect(*this);
    for(int i = 0; i < getSize(); i++){
        copy->pointVector[i] = Point2D(pointVector[i]);
    }
    return copy;
}

size_t PolygonVect::getSize() const
{
    return pointVector.size();
}

double PolygonVect::getX(int i) const throw(out_of_range)
{
    if(pointVector.size() < i){
        throw out_of_range("Vector index cannot be higher than vector size!");
    }
    else if(0 > i){
        throw out_of_range("Vector index cannot be lower than 0!");
    }
    return pointVector[i].getX();
}

double PolygonVect::getY(int i) const throw(out_of_range)
{
    if(pointVector.size() < i){
        throw out_of_range("Vector index cannot be higher than vector size!");
    }
    else if(0 > i){
        throw out_of_range("Vector index cannot be lower than 0!");
    }
    return pointVector[i].getY();
}

void PolygonVect::setX(int i, double val) throw(out_of_range)
{
    if(pointVector.size() < i){
        throw out_of_range("Vector index cannot be higher than vector size!");
    }
    else if(0 > i){
        throw out_of_range("Vector index cannot be lower than 0!");
    }
    pointVector[i].setX(val);
}

void PolygonVect::setY(int i, double val) throw(out_of_range)
{
    if(pointVector.size() < i){
        throw out_of_range("Vector index cannot be higher than vector size!");
    }
    else if(0 > i){
        throw out_of_range("Vector index cannot be lower than 0!");
    }
    pointVector[i].setY(val);
}