cmake_minimum_required(VERSION  3.16.0)
project(PS1_EMU)

#set CMAKE vars
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

#set dir vars
set(EXTERNAL_BIN ${PROJECT_SOURCE_DIR}/external_bin)

# Add the project sub directories
add_subdirectory(app)
add_subdirectory(config)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

# Link libraries and directories
target_link_libraries(${PROJECT_NAME} Ps1Emu)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link Test
target_link_libraries(${PROJECT_NAME}_TEST 
                      gtest 
                      Ps1Emu)
target_include_directories(${PROJECT_NAME}_TEST PUBLIC ${PROJECT_SOURCE_DIR}/include)