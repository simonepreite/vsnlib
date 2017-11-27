cmake_minimum_required(VERSION 2.6)

set(VSN_MOD_HEAD ./include)
include_directories(${VSN_MOD_HEAD})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/modules)

file(GLOB VSN_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

foreach(VSN_MOD ${VSN_MODULES})
    string(REPLACE ".c" "" VSN_MOD_FILE ${VSN_MOD})
    get_filename_component(VSN_MOD_TARGET ${VSN_MOD_FILE} NAME)
    add_library(${VSN_MOD_TARGET} SHARED ${VSN_MOD})
    set_target_properties(${VSN_MOD_TARGET} PROPERTIES PREFIX "")
    install(TARGETS ${VSN_MOD_TARGET} LIBRARY DESTINATION ${MODULES_INSTALL_PATH})
endforeach(VU_MOD)

