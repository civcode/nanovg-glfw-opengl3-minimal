cmake_minimum_required(VERSION 3.16)

project(nanovg)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmax-errors=5")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors -fmax-errors=5")

add_definitions(-DNANOVG_GL3)
add_definitions(-DNANOVG_USE_GLEW)
#add_definitions(-DDEMO_MSAA)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dep/glfw-3.3.7/lib/cmake)

find_package(glfw3 REQUIRED CONFIG)
find_package(OpenGL REQUIRED)
#find_package(GLEW REQUIRED)

#message(STATUS ${OPENGL_INCLUDE_DIR})

include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/dep/nanovg/src
    ${PROJECT_SOURCE_DIR}/dep/nanovg/example
    ${PROJECT_SOURCE_DIR}/dep
    ${PROJECT_SOURCE_DIR}/dep/glew-2.1.0/include
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB nanovg_SRC
    ${PROJECT_SOURCE_DIR}/dep/nanovg/src/*.c
    ${PROJECT_SOURCE_DIR}/dep/nanovg/example/perf.c
    ${PROJECT_SOURCE_DIR}/dep/nanovg/example/demo.c
)

file(GLOB project_SRC
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

set(SOURCES 
    ${nanovg_SRC}
    ${project_SRC}
)


file(COPY ${CMAKE_SOURCE_DIR}/dep/glew-2.1.0/lib/glew32.dll DESTINATION ${CMAKE_SOURCE_DIR}/build)

add_executable(nanovg src/main.cpp ${SOURCES} )
#target_link_libraries(nanovg OpenGL::GL glfw ${CMAKE_DL_LIBS} glew32)
target_link_libraries(nanovg OpenGL::GL glfw ${CMAKE_DL_LIBS} ${CMAKE_SOURCE_DIR}/dep/glew-2.1.0/lib/libglew32.dll.a)
target_compile_features(nanovg PUBLIC cxx_std_17)