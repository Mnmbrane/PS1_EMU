file(GLOB Sources "*.cpp")

add_executable(${PROJECT_NAME} ${Sources} )

target_link_libraries(${PROJECT_NAME} Ps1Emu)

message(STATUS ${PROJECT_SOURCE_DIR}/include)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
