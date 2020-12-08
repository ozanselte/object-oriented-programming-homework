#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include "Polygon.h"
#include "PolygonVect.h"
#include "PolygonDyn.h"
#include "functions.h"

using namespace std;
using namespace SELTE_HW5;

int main() {
    try {
        ofstream oCom1, oCom2;
        Rectangle r1(300, 200), r2(250, 250, 500, 500);
        Circle c1(60), c2(50, 60,100);
        Triangle t1(275), t2(500, 250, 30);
        ComposedShape com1(r1, c1), com2(t1, c2);

        testSingleShape("outputRectangle1.svg", r1);
        testSingleShape("outputRectangle2.svg", r2);
        testSingleShape("outputCircle1.svg", c1);
        testSingleShape("outputCircle2.svg", c2);
        testSingleShape("outputTriangle1.svg", t1);
        testSingleShape("outputTriangle2.svg", t2);
        cout << endl;

        cout << "r1 < c2 = " << (r1 < c2)<< endl;
        cout << "r2 <= c1 = " << (r2 <= c1)<< endl;
        cout << "t1 == r1 = " << (t1 == r1)<< endl;
        cout << "t2 != r2 = " << (t2 != r2)<< endl;
        cout << "c1 >= t2 = " << (c1 >= t2)<< endl;
        cout << "c2 > t2 = " << (c2 > t2)<< endl;
        cout << "r1 \t area:" << r1.area() << " \t perimeter: " << r1.perimeter() << endl;
        cout << "r2 \t area:" << r2.area() << " \t perimeter: " << r2.perimeter() << endl;
        cout << "c1 \t area:" << c1.area() << " \t perimeter: " << c1.perimeter() << endl;
        cout << "c2 \t area:" << c2.area() << " \t perimeter: " << c2.perimeter() << endl;
        cout << "t1 \t area:" << t1.area() << " \t perimeter: " << t1.perimeter() << endl;
        cout << "t2 \t area:" << t2.area() << " \t perimeter: " << t2.perimeter() << endl;
        cout << endl;

        oCom1.open("outputComposed1.svg");
        oCom2.open("outputComposed2.svg");
        com1.optimalFit();
        com2.optimalFit();
        oCom1 << com1;
        oCom2 << com2;
        oCom1.close();
        oCom2.close();

        vector<Shape *> shapesV;
        shapesV.push_back(&r1);
        shapesV.push_back(&r2);
        shapesV.push_back(&c1);
        shapesV.push_back(&c2);
        shapesV.push_back(&t1);
        shapesV.push_back(&t2);

        cout << "Shapes Sorting" << endl;
        for(int i = 0; i < shapesV.size(); i++){
            cout << shapesV[i]->area() << " ";
        }
        cout << endl;
        sortShapes(shapesV);
        for(int i = 0; i < shapesV.size(); i++){
            cout << shapesV[i]->area() << " ";
        }
        cout << endl;

        ofstream shapesStream, polygonsStream;
        shapesStream.open("outputShapes.svg");
        polygonsStream.open("outputPolygons.svg");
        printAll(shapesStream, shapesV);
        printPoly(polygonsStream, shapesV);
        cout << endl;

        cout << "Rectangle to PolygonVect and PolygonDyn" << endl;
        cout << PolygonVect(r1) << PolygonDyn(r2);
        cout << "Circle to PolygonVect and PolygonDyn" << endl;
        cout << PolygonVect(c1) << PolygonDyn(c2);
        cout << "Triangle to PolygonVect and PolygonDyn" << endl;
        cout << PolygonVect(t1) << PolygonDyn(t2);
        cout << endl;

        cout << "Convert All, Polygon Areas and Perimeters" << endl;
        vector<Polygon *> polygonV = convertAll(shapesV);
        for(int i = 0; i < polygonV.size(); i++){
            cout << "area:" << polygonV[i]->area() << " \t perimeter: " << polygonV[i]->perimeter() << endl;
        }
    }
    catch (out_of_range e) {
        cerr << "Out of Range Exception" << e.what() << endl;
        return EXIT_FAILURE;
    }
    catch (invalid_argument e) {
        cerr << "Invalid Argument Exception" << e.what() << endl;
        return EXIT_FAILURE;
    }
    catch (exception e) {
        cerr << "Unknown Error" << e.what() << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}