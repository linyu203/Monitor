
cmake_minimum_required(VERSION 2.8.9)
project(monitorProj)

add_subdirectory(utils)
add_subdirectory(actions)
add_subdirectory(events)
add_subdirectory(rules)

add_lirary(libMonitor STATIC parse.cpp monitor.cpp)
target_include_directories(libMonitor PUBLIC .)
target_link_libraries(libMonitor PUBLIC 
    libUtils
    libActions
    libEvents
    libRules
)

add_executable(monitorProj main.m.cpp)
target_include_directories(monitorProj PUBLIC .)
target_link_libraries(monitorProj PUBLIC libMonitor)

