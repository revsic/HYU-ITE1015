all: simple_shape simple_account

simple_shape: simple_shape.cc simple_shape_main.cc
	g++ -o simple_shape simple_shape.cc simple_shape_main.cc --std=c++11

simple_account: simple_account.cc simple_account_main.cc
	g++ -o simple_account simple_account.cc simple_account_main.cc --std=c++11

clean:
	rm simple_shape simple_account
