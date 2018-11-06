all: number rectangle

number: number.h number.cc number_main.cc
	g++ -o number number.cc number_main.cc --std=c++11

rectangle: rectangle.h rectangle.cc rectangle_main.cc
	g++ -o rectangle rectangle.cc rectangle_main.cc --std=c++11

clean:
	rm number rectangle

