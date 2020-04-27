
add_lirary(libRules STATIC parse.cpp monitor.cpp)
target_include_directories(libRules PUBLIC .)
target_link_libraries(libRules PUBLIC 
    libActions
    libEvents
)

