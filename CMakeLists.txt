cmake_minimum_required(VERSION 3.5)

project(PushBox LANGUAGES C)

add_executable(PushBox main.c)

install(TARGETS PushBox
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
