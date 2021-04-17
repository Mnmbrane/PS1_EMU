file(GLOB Sources "*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(Ps1Emu STATIC ${Sources})

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

target_link_libraries(Ps1Emu OpenSSL::Crypto)