cmake_minimum_required(VERSION 2.8)
project(bgfx_samples)

add_subdirectory(bgfx.cmake)
add_subdirectory(glfw)
link_libraries(bgfx glfw)

add_subdirectory(src)
