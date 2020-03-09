cmake_minimum_required(VERSION 3.15)
project(sqlparserflex C)

set(CMAKE_C_STANDARD 99)
find_package(PkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

foreach(FLAG ${LIBMYSQLCLIENT_CFLAGS_OTHER})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAG}")
endforeach()

link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})

add_executable(${PROJECT_NAME}   main.c)

target_include_directories(${PROJECT_NAME} PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})