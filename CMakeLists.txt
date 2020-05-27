cmake_minimum_required(VERSION 3.17)

project(sdl2_cpp VERSION 0.0.1 DESCRIPTION "A c++ wrapper for SDL2")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_library(sdl2_cpp SHARED
  src/surface.cpp
)

set_target_properties(sdl2_cpp PROPERTIES VERSION ${PROJECT_VERSION})

set_target_properties(sdl2_cpp PROPERTIES SOVERSION 1)

set_target_properties(sdl2_cpp PROPERTIES PUBLIC_HEADER include/sdl2_cpp.h)

target_include_directories(sdl2_cpp PRIVATE include)
target_include_directories(sdl2_cpp PRIVATE src)

target_link_libraries(sdl2_cpp ${SDL2_LIBRARIES})

include(GNUInstallDirs)

install(TARGETS sdl2_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

configure_file(sdl2_cpp.pc.in sdl2_cpp.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/sdl2_cpp.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
