cmake_minimum_required(VERSION 3.10)
project(libtest)


add_library(csv  csv.c)
add_library(search search.c)
add_library(sort sort.c)
add_library(del del.c)
add_library(disp disp.c)
add_library(dist distance.c)
add_library(route route.c)

add_executable(demo main.c)
target_link_libraries(demo csv search sort del disp dist route)
