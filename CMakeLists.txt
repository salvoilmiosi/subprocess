cmake_minimum_required(VERSION 3.6.0)
project(subprocess VERSION 0.1.0)

if(WIN32)
    set(subprocess_src src/proc_windows.cpp)
else()
    set(subprocess_src src/proc_linux.cpp)
endif()

add_library(subprocess OBJECT ${subprocess_src})
target_include_directories(subprocess PUBLIC src)
set_property(TARGET subprocess PROPERTY POSITION_INDEPENDENT_CODE ON)