# OBS:
# Para usar este arquivo, é necessário ter o CMake instalado.
# IDE's como Visual Studio e outras já possuem suporte integrado ao CMake.

cmake_minimum_required(VERSION 3.10)
project(ProjectC C)

# Define o padrão da linguagem C (C11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)


# ---------------------------------------------------------
# COMPILADOR E AVISOS
# ---------------------------------------------------------
# O CMake NÃO é um compilador.
# Ele apenas gera arquivos de build para um compilador real
# como GCC, Clang ou MSVC.


if(MSVC)
    add_compile_options(/W4) # MSVC compilador Visual Studio equivalente ao -Wall -Wextra
else()
    # Para GCC ou Clang (Linux, macOS, etc.)
    add_compile_options(-Wall -Wextra)
endif()

# Explicitamente lista source files
add_executable(main main.c task-manager.c "task-manager.h")
