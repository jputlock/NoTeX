
FIND_PACKAGE(PkgConfig REQUIRED)

# FIND GTK
pkg_check_modules(GTK REQUIRED gtkmm-3.0)

add_subdirectory(Containers)

set(SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/editor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/notexview.cpp
)

add_library(Source STATIC ${SOURCES})

target_include_directories(Source
	PUBLIC
		${GTK_INCLUDE_DIRS}
		../
		../libs/pdf2svg
)

# Link libraries
target_link_libraries(Source
	Containers
	${GTK_LIBRARIES}
	pdf2svg
)