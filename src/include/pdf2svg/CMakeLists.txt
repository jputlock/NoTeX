
FIND_PACKAGE(PkgConfig REQUIRED)

# Use pkg-config to check for the existence of the needed libraries
pkg_check_modules(CAIRO REQUIRED cairo>=1.2.6)
pkg_check_modules(POPPLERGLIB REQUIRED poppler-glib>=0.5.4)
pkg_check_modules(GLIB REQUIRED glib-2.0)

list(APPEND DEP_LIBS
    ${GLIB_LIBRARIES}
    ${POPPLERGLIB_LIBRARIES}
    ${GLIB_LIBRARIES}
)

# Print versions
message("Building Converter (pdf2svg)")

add_library(Converter
    ${CMAKE_CURRENT_SOURCE_DIR}/pdf2svg.c
)

target_link_libraries(Converter ${DEP_LIBS})

target_include_directories(Converter
    PUBLIC
        ${POPPLERGLIB_INCLUDE_DIRS}
        ${CAIRO_INCLUDE_DIRS}
        ${GLIB_INCLUDE_DIRS}
)
