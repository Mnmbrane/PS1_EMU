cmake_minimum_required(VERSION  3.16.3)

project(PS1_EMU)

add_executable(${PROJECT_NAME} PS1_EMU.cpp CPU.cpp Memory.cpp)
