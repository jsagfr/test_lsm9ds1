cmake_minimum_required (VERSION 2.6)
project (lsm9ds1_app)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_executable(lsm9ds1_app src/main.cpp)
set_property(TARGET lsm9ds1_app PROPERTY CXX_STANDARD 11)
set_property(TARGET lsm9ds1_app PROPERTY CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

target_link_libraries(lsm9ds1_app lsm9ds1)
