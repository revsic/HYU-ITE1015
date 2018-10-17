all: minimal_fighter simple_account

minimal_fighter: minimal_fighter.h minimal_fighter.cc minimal_fighter_main.cc
	g++ -o minimal_fighter minimal_fighter.cc minimal_fighter_main.cc --std=c++11

simple_account: simple_account.h simple_account.cc simple_account_main.cc
	g++ -o simple_account simple_account.cc simple_account_main.cc --std=c++11

clean:
	rm minimal_fighter simple_account

