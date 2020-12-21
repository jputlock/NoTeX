
# load pdf2svg library from its folder
add_subdirectory(pdf2svg)

# for now, external_libs is just pdf2svg
list(APPEND external_libs
    pdf2svg
)