cmake_minimum_required(VERSION 3.27)
project(trab1 C)

set(CMAKE_C_STANDARD 11)

find_package(MPI REQUIRED)

add_executable(trab1 mpi_primos.c)

target_link_libraries(trab1 PRIVATE MPI::MPI_C)
