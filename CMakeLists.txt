cmake_minimum_required(VERSION 3.16)

project(nanovg)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmax-errors=5")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors -fmax-errors=5")

add_definitions(-DNANOVG_GL3)
add_definitions(-DNANOVG_USE_GLEW)
#add_definitions(-DDEMO_MSAA)

find_package(glfw3 REQUIRED CONFIG)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

#message(STATUS ${OPENGL_INCLUDE_DIR})

include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/dep/nanovg/src
    ${PROJECT_SOURCE_DIR}/dep/nanovg/example
    ${PROJECT_SOURCE_DIR}/dep
)

file(GLOB nanovg_SRC
    ${PROJECT_SOURCE_DIR}/dep/nanovg/src/*.c
    ${PROJECT_SOURCE_DIR}/dep/nanovg/example/perf.c
    ${PROJECT_SOURCE_DIR}/dep/nanovg/example/demo.c
)

set(SOURCES 
    ${nanovg_SRC}
)

add_executable(nanovg src/main.cpp ${SOURCES} )
target_link_libraries(nanovg OpenGL::GL GLEW::GLEW glfw ${CMAKE_DL_LIBS})
