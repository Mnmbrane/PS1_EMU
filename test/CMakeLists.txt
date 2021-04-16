file(GLOB Sources "*.cpp")

add_executable(${PROJECT_NAME}_TEST ${Sources} )

add_test(NAME ${PROJECT_NAME}_TEST COMMAND ${PROJECT_NAME}_TEST)

