all: classes print_info print_member

classes: classes.h classes.cc classes_main.cc
	g++ -o classes classes.cc classes_main.cc --std=c++11

print_info: print_info.h print_info.cc print_info_main.cc
	g++ -o print_info print_info.cc print_info_main.cc --std=c++11

print_member: print_member.h print_member.cc print_member_main.cc
	g++ -o print_member print_member.cc print_member_main.cc --std=c++11

clean:
	rm classes print_info print_member
