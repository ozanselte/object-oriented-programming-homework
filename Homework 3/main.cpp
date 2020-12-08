#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"
#include "Comparisons.h"

using namespace std;

int main()
{
    ofstream rectangleStream[4], circleStream[4], triangleStream[4];
    ofstream composedStream[4];
    Rectangle rectangle[4];
    Circle circle[4];
    Triangle triangle[4];
    vector<ComposedShape> composed;
    for(int i = 0; i < 4; i++){
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

    ComposedShape composedA(Rectangle(23,25,0,0), Rectangle(2,7,0,0));
    ComposedShape composedB(Rectangle(100,50,0,0), Circle(7,0,0));
    ComposedShape composedC(Circle(50,50,50), Rectangle(8,8,0,0));
    ComposedShape composedD(Circle(50,50,50), Triangle(50,0,0));
    composed.push_back(composedA);
    composed.push_back(composedB);
    composed.push_back(composedC);
    composed.push_back(composedD);
    for(int i = 0; i < 4; i++){
        if(i % 2){
            composed[i].setColors("red", "green", "black");
            if(composed[i].getContainerColor() != "red") return EXIT_FAILURE;
            if(composed[i].getSmallColor() != "green") return EXIT_FAILURE;
            if(composed[i].getStrokeColor() != "black") return EXIT_FAILURE;
        }
        else{
            composed[i].setContainerColor("red");
            if(composed[i].getContainerColor() != "red") return EXIT_FAILURE;
            composed[i].setSmallColor("green");
            if(composed[i].getSmallColor() != "green") return EXIT_FAILURE;
            composed[i].setStrokeColor("black");
            if(composed[i].getStrokeColor() != "black") return EXIT_FAILURE;
        }
        cout << "Composed-" << i << " width: " << composed[i].getWidth()
        << " height: " << composed[i].getHeight() << endl;
        composed[i].getContainerShape();
        composed[i].optimalFit();
        composedStream[i] << composed[i];
    }

    ComposedShape freshComposed(rectangle[0], rectangle[0]);
    freshComposed += rectangle[1];
    freshComposed += circle[0];
    freshComposed += triangle[0];
    cout << freshComposed[0].getPerimeter() << endl;
    cout << freshComposed[1].getArea() << endl;
    cout << freshComposed[2] << endl;

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

    for(int i = 0; i < 4; i++){
        rectangleStream[i].close();
        circleStream[i].close();
        triangleStream[i].close();
        composedStream[i].close();
    }
    return EXIT_SUCCESS;
}