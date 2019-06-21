cmake_minimum_required (VERSION 2.6)
project (NoTeX)

FIND_PACKAGE(PkgConfig REQUIRED)

## Use pkg-config to check for the existence of the cairo libraries
#pkg_check_modules(CAIRO REQUIRED cairo>=1.2.6)
#pkg_check_modules(POPPLERGLIB REQUIRED poppler-glib>=0.5.4)
#pkg_check_modules(GLIB REQUIRED glib-2.0)
#
## Print versions
#message("CAIRO VERSION IS " ${CAIRO_VERSION})
#message("POPPLER GLIB VERSION IS " ${POPPLERGLIB_VERSION})
#
## Set up CONVERTER libraries
#add_library(CONVERTER ${CMAKE_CURRENT_SOURCE_DIR}/src/pdf2svg.c ${CMAKE_CURRENT_SOURCE_DIR}/src/pdf2svg.h)
#
#target_link_libraries(CONVERTER ${GLIB_LIBRARIES} ${POPPERGLIB_LIBRARIES} ${CAIRO_LIBRARIES})
#
#target_include_directories(CONVERTER PUBLIC ${POPPLERGLIB_INCLUDE_DIRS})
#target_include_directories(CONVERTER PUBLIC ${CAIRO_INCLUDE_DIRS})
#target_include_directories(CONVERTER PUBLIC ${GLIB_INCLUDE_DIRS})

# Setup NoTeX
pkg_check_modules(GTK gtkmm-3.0)

add_executable(NoTeX ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp src/Editor.cpp src/Editor.h)

target_link_libraries(NoTeX ${GTK_LIBRARIES})

target_include_directories(NoTeX PRIVATE ${GTK_INCLUDE_DIRS})

#target_include_directories(NoTeX PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pdf2svg)
#
#target_link_libraries(NoTeX CONVERTER)