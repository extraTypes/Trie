cmake_minimum_required(VERSION 3.14)
set(LL_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD ${LL_CXX_STANDARD})
set(CMAKE_CXX_STANDARD_REQUIRED 1)


project(TEMPLATE)

add_subdirectory(src)
add_executable(TEMPLATE main.cpp)
target_link_libraries(TEMPLATE PUBLIC Template)