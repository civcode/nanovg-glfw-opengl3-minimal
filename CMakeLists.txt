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

include_directories(
    ${OPENGL_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/dep/nanovg/src
    ${PROJECT_SOURCE_DIR}/dep/nanovg/example
    ${PROJECT_SOURCE_DIR}/dep
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

#set_property(TARGET nanovg PROPERTY CXX_STANDARD 17)
add_executable(nanovg src/main.cpp ${SOURCES} )
target_link_libraries(nanovg OpenGL::GL GLEW::GLEW glfw ${CMAKE_DL_LIBS})
target_compile_features(nanovg PUBLIC cxx_std_17)