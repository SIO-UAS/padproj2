cmake_minimum_required(VERSION 3.10)
project(libtest)


add_library(csv  csv.c)
add_library(search search.c)
add_executable(mainlib mainlib.c)
target_link_libraries(mainlib csv search)
