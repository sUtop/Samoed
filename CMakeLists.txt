cmake_minimum_required(VERSION 3.0.0)

#  Имя проекта
project(Samoed)

# Текущая версия
set(VERSION "0.0.5")

# Путь до корневой директории
set (ROOT_DIR ${PROJECT_SOURCE_DIR})

set( SRC 
     server/src/tmeslist.cpp
     server/src/databasemessagelist.cpp
     server/src/webmeslist.cpp
     server/src/main.cpp
)


message("   Building  ${PROJECT_SOURCE_DIR}\n      project-name: ${PROJECT_NAME} ")

add_definitions(-std=c++14 -g -DDEBUG)

include_directories(server/include)

# В случае, если буст не будет найден автоматом - предлагается следующая команда :
# rm -rf *; BOOST_ROOT=~/boost_1_64_0/ cmake ../Samoed/ ; make -j10 ; ./samoed_serve
#  ~/boost_1_64_0/ - путь до собранного буста
#  ../Samoed/      - путь до корня проекта
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system)
if(NOT Boost_FOUND)
	message(SEND_ERROR "Failed to find boost.")
	return()
else()
	include_directories(${Boost_INCLUDE_DIRS})
endif()

include_directories(${Boost_INCLUDE_DIR})

add_executable(samoed_server ${SRC})

target_link_libraries(samoed_server ${Boost_LIBRARIES})

