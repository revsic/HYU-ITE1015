all: world_clock calendar

world_clock: world_clock.h world_clock.cc world_clock_main.cc
	g++ -o world_clock world_clock.cc world_clock_main.cc -std=c++11

calendar: calendar.h calendar.cc calendar_main.cc
	g++ -o calendar calendar.cc calendar_main.cc -std=c++11

clean:
	rm world_clock calendar
