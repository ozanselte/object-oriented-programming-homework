#include <iostream>
#include <fstream>
#include <cmath>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include "Comparisons.h"
#include "Polygon.h"
#include "Polyline.h"

using std::cout;
using std::endl;
using std::ofstream;
using std::to_string;
using namespace HW4_SELTE;

int main() {
    Rectangle rectangle[5];
    Circle circle[5];
    Triangle triangle[5];
    ofstream rectangleStream[5], circleStream[5], triangleStream[5];
    ofstream composedStream[5];

    for(int i = 0; i < 5; i++){
        rectangleStream[i].open("outputRectangle" + to_string(i) + ".svg");
        circleStream[i].open("outputCircle" + to_string(i) + ".svg");
        triangleStream[i].open("outputTriangle" + to_string(i) + ".svg");
        composedStream[i].open("outputComposed" + to_string(i) + ".svg");
        circle[i].setRadius(i*15);
        if(circle[i].getRadius() != i*15) return EXIT_FAILURE;
        if(circle[i].getPerimeter() != 2*M_PI*i*15) return EXIT_FAILURE;
        if(abs(circle[i].getArea() - M_PI*i*15.0*i*15.0) > 0.01) return EXIT_FAILURE;
        if(i % 2){
            rectangle[i].setLocation(0, 0);
            if(rectangle[i].getX() != 0) return EXIT_FAILURE;
            if(rectangle[i].getY() != 0) return EXIT_FAILURE;
            rectangle[i].setSize(i*20, i*25);
            if(rectangle[i].getWidth() != i*20) return EXIT_FAILURE;
            if(rectangle[i].getHeight() != i*25) return EXIT_FAILURE;
            if(rectangle[i].getPerimeter() != 2*(i*20+i*25)) return EXIT_FAILURE;
            if(rectangle[i].getArea() != i*20*i*25) return EXIT_FAILURE;
            circle[i].setLocation(i*7, i*8);
            if(circle[i].getX() != i*7) return EXIT_FAILURE;
            if(circle[i].getY() != i*8) return EXIT_FAILURE;
            triangle[i].setTriangle(i*10, i*15, i*20, false);
            if(triangle[i].getX(0) != i*15) return EXIT_FAILURE;
            if(triangle[i].getY(0) != i*20) return EXIT_FAILURE;
            if(triangle[i].getPerimeter() != i*10*3) return EXIT_FAILURE;
            if(abs(triangle[i].getArea() - i*10*i*10*sqrt(3)/4) > 0.01) return EXIT_FAILURE;
        }
        else{
            rectangle[i].setX(0);
            if(rectangle[i].getX() != 0) return EXIT_FAILURE;
            rectangle[i].setY(0);
            if(rectangle[i].getY() != 0) return EXIT_FAILURE;
            rectangle[i].setWidth(i*10);
            if(rectangle[i].getWidth() != i*10) return EXIT_FAILURE;
            rectangle[i].setHeight(i*15);
            if(rectangle[i].getHeight() != i*15) return EXIT_FAILURE;
            if(rectangle[i].getPerimeter() != 2*(i*10+i*15)) return EXIT_FAILURE;
            if(rectangle[i].getArea() != i*10*i*15) return EXIT_FAILURE;
            circle[i].setX(i*7);
            circle[i].setY(i*8);
            if(circle[i].getX() != i*7) return EXIT_FAILURE;
            if(circle[i].getY() != i*8) return EXIT_FAILURE;
            triangle[i].setTriangle(i*10, i*15, i*20, true);
            if(triangle[i].getX(0) != i*15) return EXIT_FAILURE;
            if(triangle[i].getY(0) != i*20) return EXIT_FAILURE;
            if(triangle[i].getPerimeter() != i*10*3) return EXIT_FAILURE;
            if(abs(triangle[i].getArea() - i*10*i*10*sqrt(3)/4) > 0.01) return EXIT_FAILURE;
        }
        rectangleStream[i] << rectangle[i];
        circleStream[i] << circle[i];
        triangleStream[i] << triangle[i];
    }

    rectangleStream[0] << ++rectangle[0] << rectangle[0]-- << rectangle[0];
    rectangleStream[1] << rectangle[1]++ << --rectangle[1] << rectangle[1];
    rectangleStream[2] << rectangle[2] + 2.0;
    rectangleStream[3] << rectangle[3] - 0.5;
    circleStream[0] << ++circle[0] << circle[0]-- << circle[0];
    circleStream[1] << ++circle[1] << --circle[1] << circle[1];
    circleStream[2] << circle[2] + 2.0;
    circleStream[3] << circle[3] - 0.5;
    triangleStream[0] << ++triangle[0] << triangle[0]-- << triangle[0];
    triangleStream[1] << ++triangle[1] << --triangle[1] << triangle[1];
    triangleStream[2] << triangle[2] + 2.0;
    triangleStream[3] << triangle[3] - 0.5;

    cout << "Rectangles total perimeter: " << Rectangle::getTotalPerimeter() << endl;
    cout << "Circles total perimeter: " << Circle::getTotalPerimeter() << endl;
    cout << "Triangles total perimeter: " << Triangle::getTotalPerimeter() << endl;
    cout << "Rectangles total area: " << Rectangle::getTotalArea() << endl;
    cout << "Circles total area: " << Circle::getTotalArea() << endl;
    cout << "Triangles total ares: " << Triangle::getTotalArea() << endl;

    ComposedShape composed1(Rectangle(23,25,0,0), Rectangle(2,7,0,0));
    ComposedShape composed2(Rectangle(100,50,0,0), Circle(7,0,0));
    ComposedShape composed3(Circle(50,50,50), Rectangle(8,8,0,0));
    ComposedShape composed4(Circle(50,50,50), Triangle(50,0,0));
    ComposedShape composed5(Triangle(50,50,50), Circle(6,0,0));

    cout << "Composed-1" << " width: " << composed1.getWidth()
         << " height: " << composed1.getHeight() << endl;
    composed1.optimalFit();
    composedStream[0] << composed1;
    cout << "Composed-2" << " width: " << composed2.getWidth()
         << " height: " << composed2.getHeight() << endl;
    composed2.optimalFit();
    composedStream[1] << composed2;
    cout << "Composed-3" << " width: " << composed3.getWidth()
         << " height: " << composed3.getHeight() << endl;
    composed3.optimalFit();
    composedStream[2] << composed3;
    cout << "Composed-4" << " width: " << composed4.getWidth()
         << " height: " << composed4.getHeight() << endl;
    composed4.optimalFit();
    composedStream[3] << composed4;
    cout << "Composed-5" << " width: " << composed5.getWidth()
         << " height: " << composed5.getHeight() << endl;
    composed5.optimalFit();
    composedStream[4] << composed5;

    cout << (rectangle[0] < rectangle[1])
         << (rectangle[0] <= rectangle[1])
         << (rectangle[0] == rectangle[1])
         << (rectangle[0] != rectangle[1])
         << (rectangle[0] >= rectangle[1])
         << (rectangle[0] > rectangle[1])
         << endl;
    cout << (rectangle[0] < circle[1])
         << (rectangle[0] <= circle[1])
         << (rectangle[0] == circle[1])
         << (rectangle[0] != circle[1])
         << (rectangle[0] >= circle[1])
         << (rectangle[0] > circle[1])
         << endl;
    cout << (rectangle[0] < triangle[1])
         << (rectangle[0] <= triangle[1])
         << (rectangle[0] == triangle[1])
         << (rectangle[0] != triangle[1])
         << (rectangle[0] >= triangle[1])
         << (rectangle[0] > triangle[1])
         << endl;
    cout << (circle[1] < rectangle[1])
         << (circle[1] <= rectangle[1])
         << (circle[1] == rectangle[1])
         << (circle[1] != rectangle[1])
         << (circle[1] >= rectangle[1])
         << (circle[1] > rectangle[1])
         << endl;
    cout << (circle[1] < circle[1])
         << (circle[1] <= circle[1])
         << (circle[1] == circle[1])
         << (circle[1] != circle[1])
         << (circle[1] >= circle[1])
         << (circle[1] > circle[1])
         << endl;
    cout << (circle[1] < triangle[1])
         << (circle[1] <= triangle[1])
         << (circle[1] == triangle[1])
         << (circle[1] != triangle[1])
         << (circle[1] >= triangle[1])
         << (circle[1] > triangle[1])
         << endl;
    cout << (triangle[1] < rectangle[1])
         << (triangle[1] <= rectangle[1])
         << (triangle[1] == rectangle[1])
         << (triangle[1] != rectangle[1])
         << (triangle[1] >= rectangle[1])
         << (triangle[1] > rectangle[1])
         << endl;
    cout << (triangle[1] < circle[1])
         << (triangle[1] <= circle[1])
         << (triangle[1] == circle[1])
         << (triangle[1] != circle[1])
         << (triangle[1] >= circle[1])
         << (triangle[1] > circle[1])
         << endl;
    cout << (triangle[1] < triangle[1])
         << (triangle[1] <= triangle[1])
         << (triangle[1] == triangle[1])
         << (triangle[1] != triangle[1])
         << (triangle[1] >= triangle[1])
         << (triangle[1] > triangle[1])
         << endl;

    Polygon polygon1(rectangle[0]);
    if(polygon1.getSize() != 4) return EXIT_FAILURE;
    Polygon polygon2(circle[0]);
    if(polygon2.getSize() != 100) return EXIT_FAILURE;
    Polygon polygon3(triangle[0]);
    if(polygon3.getSize() != 3) return EXIT_FAILURE;
    if(polygon2 == polygon3) return EXIT_FAILURE;
    vector<Polygon::Point2D> v;
    v.push_back(Polygon::Point2D(5,5));
    v.push_back(Polygon::Point2D(10,10));
    Polygon polygon4(v);
    if(polygon4.getSize() != 2) return EXIT_FAILURE;
    Polygon polygon5 = polygon4;
    if(polygon5.getSize() != 2) return EXIT_FAILURE;
    if(polygon4 != polygon5) return EXIT_FAILURE;
    if((polygon1+polygon3).getSize() != 7) return EXIT_FAILURE;
    if(polygon1[0].getY() != 0) return EXIT_FAILURE;
    polygon1[0].setY(5);
    if(polygon1[0].getY() != 5) return EXIT_FAILURE;

    Polyline polyline1(rectangle[0]);
    if(polyline1.getSize() != 4) return EXIT_FAILURE;
    Polyline polyline2(circle[0]);
    if(polyline2.getSize() != 100) return EXIT_FAILURE;
    Polyline polyline3(triangle[0]);
    if(polyline3.getSize() != 3) return EXIT_FAILURE;
    if(polyline2 == polyline3) return EXIT_FAILURE;
    Polyline polyline4(v);
    if(polyline4.getSize() != 2) return EXIT_FAILURE;
    Polyline polyline5 = polyline4;
    if(polyline5.getSize() != 2) return EXIT_FAILURE;
    if(polyline4 != polyline5) return EXIT_FAILURE;
    if((polyline1+polyline3).getSize() != 7) return EXIT_FAILURE;
    if(polyline1[0].getY() != 0) return EXIT_FAILURE;
    polyline1[0].setY(5);
    if(polyline1[0].getY() != 5) return EXIT_FAILURE;

    for(int i = 0; i < 5; i++){
        rectangleStream[i].close();
        circleStream[i].close();
        triangleStream[i].close();
        composedStream[i].close();
    }
    return 0;
}