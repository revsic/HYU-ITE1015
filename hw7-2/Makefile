all: simple_int_set

simple_int_set: simple_int_set.h simple_int_set.cc simple_int_set_main.cc
	g++ -o simple_int_set simple_int_set.cc simple_int_set_main.cc --std=c++11

clean:
	rm simple_int_set
