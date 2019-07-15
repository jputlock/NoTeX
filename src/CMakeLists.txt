
FIND_PACKAGE(PkgConfig REQUIRED)

# FIND GTK
pkg_check_modules(GTK gtkmm-3.0)

add_subdirectory(include/pdf2svg)
add_subdirectory(GUI)
add_subdirectory(Containers)

add_library(Source
		${CMAKE_CURRENT_SOURCE_DIR}/debug.h
)

# LINK GTK and Converter
target_link_libraries(Source
    Converter
	GUI
	Containers
)

target_link_libraries(Source
    ${GTK_LIBRARIES}
)

target_include_directories(Source
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/pdf2svg
        ${GTK_INCLUDE_DIRS}
)
