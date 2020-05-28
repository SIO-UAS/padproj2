cmake_minimum_required(VERSION 3.10)
project(libtest)


add_library(csv  csv.c)
add_executable(mainlib main.c)
target_link_libraries(mainlib csv)
