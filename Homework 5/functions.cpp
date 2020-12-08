//
// Created by ozanselte on 12/20/18.
//

#include "functions.h"
#include "ComposedShape.h"
#include "PolygonVect.h"
#include "PolygonDyn.h"
#include <algorithm>
#include <stdexcept>
#include <fstream>

using std::vector;
using std::endl;
using std::sort;
using std::swap;
using std::invalid_argument;
using std::ofstream;

namespace SELTE_HW5 {
    void printAll(ostream& stream, vector<Shape *> v) throw(invalid_argument)
    {
        double w = 0, h = 0;
        for(auto shapePtr : v){
            Polygon *polygonPtr;
            ShapeType type = shapePtr->getType();
            switch(type) {
                case ShapeType::Rectangle:
                    polygonPtr = new PolygonVect(*dynamic_cast<Rectangle *>(shapePtr));
                    break;
                case ShapeType::Circle:
                    polygonPtr = new PolygonVect(*dynamic_cast<Circle *>(shapePtr));
                    break;
                case ShapeType::Triangle:
                    polygonPtr = new PolygonVect(*dynamic_cast<Triangle *>(shapePtr));
                    break;
                case ShapeType::PolygonVect:
                    polygonPtr = new PolygonVect(*dynamic_cast<PolygonVect *>(shapePtr));
                    break;
                case ShapeType::PolygonDyn:
                    polygonPtr = new PolygonDyn(*dynamic_cast<PolygonDyn *>(shapePtr));
                    break;
                default:
                    throw invalid_argument("Invalid Argument!");
            }
            for(int i = 0; i < polygonPtr->getSize(); i++){
                if(polygonPtr->getX(i) > w){
                    w = polygonPtr->getX(i);
                }
                if(polygonPtr->getY(i) > h){
                    h = polygonPtr->getY(i);
                }
            }
            delete polygonPtr;
        }
        stream <<
               "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" " <<
               "width=\"" << w << "\" "
               << "height=\"" << h << "\">" <<
               endl;
        for(auto shapePtr : v){
            stream << *shapePtr;
        }
        stream << "</svg>" << endl;
    }

    void printPoly(ostream& stream, vector<Shape *> v)
    {
        vector<Shape *> newVector;
        for(auto *ptr : convertAll(v)){
            newVector.push_back(dynamic_cast<Shape *>(ptr));
        }
        printAll(stream, newVector);
    }

    vector<Polygon *> convertAll(vector<Shape *> v) throw(invalid_argument)
    {
        vector<Polygon *> pVector;
        for(Shape *shapePtr : v){
            Polygon *polygonPtr;
            ShapeType type = shapePtr->getType();
            switch(type) {
                case ShapeType::Rectangle:
                    polygonPtr = new PolygonVect(*dynamic_cast<Rectangle *>(shapePtr));
                    break;
                case ShapeType::Circle:
                    polygonPtr = new PolygonVect(*dynamic_cast<Circle *>(shapePtr));
                    break;
                case ShapeType::Triangle:
                    polygonPtr = new PolygonVect(*dynamic_cast<Triangle *>(shapePtr));
                    break;
                case ShapeType::PolygonDyn:
                    polygonPtr = new PolygonDyn(*dynamic_cast<PolygonDyn *>(shapePtr));
                    break;
                case ShapeType::PolygonVect:
                    polygonPtr = new PolygonVect(*dynamic_cast<PolygonVect *>(shapePtr));
                    break;
                default:
                    throw invalid_argument("Invalid ShapeType!");
            }
            pVector.push_back(polygonPtr);
        }
        return pVector;
    }

    void sortShapes(vector<Shape *>& v)
    {
        sort(v.begin(), v.end(), cmpShapePtr);
    }

    void testSingleShape(string name, Shape& shape)
    {
        ofstream stream;
        stream.open(name);
        stream << shape++;
        stream << shape--;
        stream << shape;
        stream << ++shape;
        stream << --shape;
        stream.close();
    }
}

namespace {
    bool cmpShapePtr(Shape *a, Shape *b)
    {
        return (*a < *b);
    }
}