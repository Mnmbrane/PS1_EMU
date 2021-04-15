cmake_minimum_required(VERSION  3.16.3)
project(PS1_EMU)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(app)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)