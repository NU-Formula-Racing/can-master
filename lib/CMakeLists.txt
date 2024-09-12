# Define the header-only library
add_library(inja-json INTERFACE)

# Specify the language explicitly as C++
set_target_properties(inja-json PROPERTIES LINKER_LANGUAGE CXX)

# Add include directories so other targets can find the headers
target_include_directories(inja-json INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
