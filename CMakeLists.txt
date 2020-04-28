cmake_minimum_required(VERSION 3.15)
project(kraskal C)

set(CMAKE_C_STANDARD 11)

add_executable(kraskal main.c mergeSort.h mergeSort.c algo_kraskal.c algo_kraskal.h)