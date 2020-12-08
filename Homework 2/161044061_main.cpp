#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ComposedShape.h"

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
        if(i % 2){
            rectangle[i].setLocation(0, 0);
            if(rectangle[i].getX() != 0) return EXIT_FAILURE;
            if(rectangle[i].getY() != 0) return EXIT_FAILURE;
            rectangle[i].setSize(i*20, i*25);
            if(rectangle[i].getWidth() != i*20) return EXIT_FAILURE;
            if(rectangle[i].getHeight() != i*25) return EXIT_FAILURE;
            circle[i].setLocation(i*7, i*8);
            if(circle[i].getX() != i*7) return EXIT_FAILURE;
            if(circle[i].getY() != i*8) return EXIT_FAILURE;
            triangle[i].setTriangle(i*10, i*15, i*20, false);
            if(triangle[i].getX(0) != i*15) return EXIT_FAILURE;
            if(triangle[i].getY(0) != i*20) return EXIT_FAILURE;
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
            circle[i].setX(i*7);
            circle[i].setY(i*8);
            if(circle[i].getX() != i*7) return EXIT_FAILURE;
            if(circle[i].getY() != i*8) return EXIT_FAILURE;
            triangle[i].setTriangle(i*10, i*15, i*20, true);
            if(triangle[i].getX(0) != i*15) return EXIT_FAILURE;
            if(triangle[i].getY(0) != i*20) return EXIT_FAILURE;
        }
        rectangle[i].draw(rectangleStream[i], "red", "red");
        circle[i].draw(circleStream[i], "red", "red");
        triangle[i].draw(triangleStream[i], "red", "red");
    }
    ComposedShape composedA(Rectangle(23,25,0,0), Rectangle(2,7,0,0));
    ComposedShape composedB(Rectangle(100,50,0,0), Circle(7,0,0));
    ComposedShape composedC(Circle(50,0,0), Rectangle(8,8,0,0));
    ComposedShape composedD(Circle(50,0,0), Triangle(50,0,0));
    composed.push_back(composedA);
    composed.push_back(composedB);
    composed.push_back(composedC);
    composed.push_back(composedD);
    for(int i = 0; i < 4; i++){
        switch(composed[i].getSmallShape()){
            case Shape::Rectangle:
                composed[i].getRectangleVector();
                break;
            case Shape::Circle:
                composed[i].getCircleVector();
                break;
            case Shape::Triangle:
                composed[i].getTriangleVector();
                break;
        }
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
        composed[i].draw(composedStream[i]);
    }
    return EXIT_SUCCESS;
}
