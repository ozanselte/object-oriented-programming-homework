hw3 : Rectangle.o Circle.o Triangle.o ComposedShape.o Comparisons.o main.o
	g++ -o exe Rectangle.o Circle.o Triangle.o ComposedShape.o Comparisons.o main.o

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

main.o : main.cpp
	g++ -c -std=c++11 -Wall main.cpp

clean:
	rm *.o exe