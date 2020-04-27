
add_library(libRules STATIC 
	rule.cpp 
	ap.cpp 
	io.cpp
	dmn.cpp
	em.cpp
	ode.cpp
	ose.cpp
	sfp.cpp
)

target_include_directories(libRules PUBLIC .)

target_link_libraries(libRules PUBLIC 
    libActions
    libEvents
)

