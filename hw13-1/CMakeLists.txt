set(CMAKE_CXX_STANDARD 11)

add_executable(bad_alloc bad_alloc.cc) #1
add_executable(throw_object throw_object.cc) #2
add_executable(chained_handler chained_handler.cc) #3
add_executable(throw_dtor throw_dtor.cc) #4
add_executable(rethrow rethrow.cc) #5