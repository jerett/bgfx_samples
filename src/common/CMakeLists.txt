
add_library(common platform_context.h platform_context.cpp)
target_include_directories(common PUBLIC ${CMAKE_SOURCE_DIR}/src/common)