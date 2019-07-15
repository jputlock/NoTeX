
FIND_PACKAGE(PkgConfig REQUIRED)

# FIND GTK
pkg_check_modules(GTK gtkmm-3.0)

add_library(GUI
		${CMAKE_CURRENT_SOURCE_DIR}/editor.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/editor.h
		${CMAKE_CURRENT_SOURCE_DIR}/editorapp.h
		${CMAKE_CURRENT_SOURCE_DIR}/clickableimage.h
)

# LINK GTK
target_link_libraries(GUI
    ${GTK_LIBRARIES}
)

target_include_directories(GUI
    PUBLIC
        ${GTK_INCLUDE_DIRS}
)
