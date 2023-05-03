cmake_minimum_required(VERSION 3.25)
project(2023_01_PCC104_UFOP)

set(CMAKE_CXX_STANDARD 23)

add_executable(2023_01_PCC104_UFOP main.cpp 01-exhaustive-search/01-exhaustive-search.cpp 01-exhaustive-search/01-exhaustive-search.h 02-decrease-and-conquer/02-decrease-and-conquer.cpp 02-decrease-and-conquer/02-decrease-and-conquer.h utils.cpp utils.h 03-divide-and-conquer/03-divide-and-conquer.h 03-divide-and-conquer/03-divide-and-conquer.cpp)
