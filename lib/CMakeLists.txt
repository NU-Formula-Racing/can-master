# Inja w/ JSON dependency Library
add_library(inja-json INTERFACE)
set_target_properties(inja-json PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(inja-json INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inja)

# httplib Library
add_library(httplib INTERFACE)
set_target_properties(httplib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(httplib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/httplib)