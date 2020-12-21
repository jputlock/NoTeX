
FIND_PACKAGE(PkgConfig REQUIRED)

# Use pkg-config to check for the existence of the needed libraries
pkg_check_modules(CAIRO REQUIRED cairo>=1.2.6)
pkg_check_modules(POPPLERGLIB REQUIRED poppler-glib>=0.5.4)
pkg_check_modules(GLIB REQUIRED glib-2.0)
message("Building pdf2svg library (pdf2svg)")


# target
add_library(pdf2svg OBJECT
    ${CMAKE_CURRENT_SOURCE_DIR}/pdf2svg.c
)

# include
target_include_directories(pdf2svg
    PUBLIC
        ${POPPLERGLIB_INCLUDE_DIRS}
        ${CAIRO_INCLUDE_DIRS}
        ${GLIB_INCLUDE_DIRS}
)

# external libs
list(APPEND DEP_LIBS
    ${GLIB_LIBRARIES}
    ${POPPLERGLIB_LIBRARIES}
    ${GLIB_LIBRARIES}
)
target_link_libraries(pdf2svg ${DEP_LIBS})