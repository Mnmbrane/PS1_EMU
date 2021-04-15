file(GLOB Sources "*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(Ps1Emu STATIC ${Sources})
