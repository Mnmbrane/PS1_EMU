set(BIOS_PATH_DATA "${EXTERNAL_BIN}/bios.bin")

configure_file ("${PROJECT_SOURCE_DIR}/config/Config.h.in"
                "${PROJECT_SOURCE_DIR}/include/Config.h" )