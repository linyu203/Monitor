
add_lirary(libEvents STATIC market.cpp)
target_include_directories(libEvents PUBLIC .)
target_link_libraries(libEvents PUBLIC 
    libUtils
)

