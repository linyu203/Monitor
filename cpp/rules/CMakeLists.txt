
add_library(libRules STATIC abnormalprice.cpp invalidexecution.cpp)
target_include_directories(libRules PUBLIC .)
target_link_libraries(libRules PUBLIC 
    libActions
    libEvents
)

