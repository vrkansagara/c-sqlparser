cmake_minimum_required(VERSION 3.10)
project(sqlparserflex C)

cmake_minimum_required(VERSION 3.0)
project(sqlparserflexC)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

foreach(FLAG ${LIBMYSQLCLIENT_CFLAGS_OTHER})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAG}")
endforeach()

link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})

add_executable(sqlparserflex  main.c)
target_include_directories(sqlparserflex PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(sqlparserflex PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})