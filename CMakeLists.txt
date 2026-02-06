# 1. Versión mínima de CMake (3.10 es un estándar seguro)
cmake_minimum_required(VERSION 3.10)

# 2. Nombre del proyecto y lenguaje
project(ProyectoMatrices CXX)

# 3. Especificar el estándar de C++ (C++17 es ideal hoy en día)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 4. Crear el ejecutable
# Sintaxis: add_executable(NombreDelEjecutable Archivo1.cpp Archivo2.cpp ...)
add_executable(programa main.cpp Matriz.cpp Matriz.hpp)
