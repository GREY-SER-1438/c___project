cmake_minimum_required(VERSION 3.20)

project(c___project)

set(CMAKE_CXX_STANDARD 20)

# Добавляем папку include/ в пути для поиска заголовков
include_directories(${CMAKE_SOURCE_DIR}/include)

# Ищем ВСЕ .cpp файлы в проекте
file(GLOB_RECURSE SRC_FILES
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(c___project ${SRC_FILES}
        src/Scenes/CoreLocation-8.cpp
        include/CoreLocation-8.h
        src/Scenes/LocationBase.cpp
        include/Item.h
        include/Item.h
        src/Inventory.cpp
        include/Inventory.h)
