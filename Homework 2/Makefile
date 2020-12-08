161044061_CSE241_HW2 : Rectangle.o Circle.o Triangle.o ComposedShape.o 161044061_main.o
	g++ -o 161044061_hw2 Rectangle.o Circle.o Triangle.o ComposedShape.o 161044061_main.o

Rectangle.o : Rectangle.cpp
	g++ -c -std=c++11 -Wall Rectangle.cpp

Circle.o : Circle.cpp
	g++ -c -std=c++11 -Wall Circle.cpp

Triangle.o : Triangle.cpp
	g++ -c -std=c++11 -Wall Triangle.cpp

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++11 -Wall ComposedShape.cpp

161044061_main.o : 161044061_main.cpp
	g++ -c -std=c++11 -Wall 161044061_main.cpp

clean:
	rm *.o 161044061_hw2