cmake_minimum_required(VERSION 3.0)
project(MeuProjeto)



# Definir as opções de compilação para o Clang
set(CMAKE_C_FLAGS "-Wall -Wextra -std=c11")

# Encontrar a biblioteca SDL2
find_package(SDL2 REQUIRED)

# Incluir os diretórios de inclusão da biblioteca SDL2
include_directories(${SDL2_INCLUDE_DIRS})

# Definir os arquivos de origem do seu projeto
set(SOURCES main.c snake.c fruit.c render.c kbdlistener.c)


# Criar o executável
add_executable(main ${SOURCES})

# Vincular as bibliotecas SDL2
target_link_libraries(main ${SDL2_LIBRARIES})
