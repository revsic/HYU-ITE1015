all: sorted_array integer_set

sorted_array: sorted_array.h sorted_array.cc sorted_array_main.cc
	g++ -o sorted_array sorted_array.cc sorted_array_main.cc --std=c++11

integer_set: integer_set.h integer_set.cc integer_set_main.cc
	g++ -o integer_set integer_set.cc integer_set_main.cc --std=c++11

clean:
	rm sorted_array integer_set

