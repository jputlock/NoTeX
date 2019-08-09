
FIND_PACKAGE(PkgConfig REQUIRED)

# FIND GTK
pkg_check_modules(GTK gtkmm-3.0)

add_subdirectory(Containers)
add_subdirectory(include/pdf2svg)

add_library(Source
		${CMAKE_CURRENT_SOURCE_DIR}/editor.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/editor.h
		${CMAKE_CURRENT_SOURCE_DIR}/editorapp.h
		${CMAKE_CURRENT_SOURCE_DIR}/clickableimage.h
		${CMAKE_CURRENT_SOURCE_DIR}/notexview.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/notexview.h
		${CMAKE_CURRENT_SOURCE_DIR}/debug.h
)

# LINK GTK and Converter
target_link_libraries(Source
	Containers
	Converter
    ${GTK_LIBRARIES}
)

target_include_directories(Source
    PUBLIC
        ${GTK_INCLUDE_DIRS}
		${CMAKE_CURRENT_SOURCE_DIR}/include/pdf2svg
)
