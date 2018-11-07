all: draw_shape

draw_shape: draw_shape.h draw_shape.cc draw_shape_main.cc
	g++ -o draw_shape draw_shape.cc draw_shape_main.cc --std=c++11

clean:
	rm draw_shape
