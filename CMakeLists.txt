cmake_minimum_required(VERSION  3.16.3)
project(PS1_EMU)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(app)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

# Link libraries
target_link_libraries(${PROJECT_NAME} Ps1Emu)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Test
target_link_libraries(${PROJECT_NAME}_TEST gtest)
target_link_libraries(${PROJECT_NAME}_TEST Ps1Emu)
target_include_directories(${PROJECT_NAME}_TEST PUBLIC ${PROJECT_SOURCE_DIR}/include)