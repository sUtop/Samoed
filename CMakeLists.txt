cmake_minimum_required(VERSION 3.0.0)

#  Имя проекта
project(Samoed)

# Текущая версия
set(VERSION "0.0.5")

# Путь до корневой директории
set (ROOT_DIR ${PROJECT_SOURCE_DIR})

message("~~~Building  ${PROJECT_SOURCE_DIR}\n~~~project-name:${PROJECT_NAME}")

add_definitions(-std=c++14 -g -DDEBUG)

include_directories(server/include)

add_executable(samoed_server
        server/src/telemetrymessagelist.cpp
        server/src/databasemessagelist.cpp
        server/src/webmessagelist.cpp
        server/src/main.cpp
)


