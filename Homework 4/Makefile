hw4 : Rectangle.o Circle.o Triangle.o ComposedShape.o Comparisons.o Polygon.o Polyline.o 161044061_main.o
	g++ -o exe Rectangle.o Circle.o Triangle.o ComposedShape.o Comparisons.o Polygon.o Polyline.o 161044061_main.o

Rectangle.o : Rectangle.cpp
	g++ -c -std=c++11 -Wall Rectangle.cpp

Circle.o : Circle.cpp
	g++ -c -std=c++11 -Wall Circle.cpp

Triangle.o : Triangle.cpp
	g++ -c -std=c++11 -Wall Triangle.cpp

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++11 -Wall ComposedShape.cpp

Comparisons.o : Comparisons.cpp
	g++ -c -std=c++11 -Wall Comparisons.cpp

Polygon.o : Polygon.cpp
	g++ -c -std=c++11 -Wall Polygon.cpp

Polyline.o : Polyline.cpp
	g++ -c -std=c++11 -Wall Polyline.cpp

161044061_main.o : 161044061_main.cpp
	g++ -c -std=c++11 -Wall 161044061_main.cpp

clean:
	rm *.o exe