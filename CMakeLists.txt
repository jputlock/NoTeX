cmake_minimum_required (VERSION 3.0)
project (NoTeX)

# Flags
set(CMAKE_CXX_STANDARD 11)
set(NoTeX_VERSION_MAJOR 1)
set(NoTeX_VERSION_MINOR 0)

# Files
configure_file(
    ${PROJECT_SOURCE_DIR}/CompileConfig.h.in
    ${PROJECT_BINARY_DIR}/CompileConfig.h
)

option(DEBUG "Print debug output and statistics" ON)

if(DEBUG)
	add_definitions(-DDEBUG)
endif(DEBUG)

# Target -- Setup NoTeX executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# Include
add_subdirectory(src)
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_BINARY_DIR}
    PUBLIC ../libs/pdf2svg
)

# External libraries
add_subdirectory(libs/pdf2svg)
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Source
        pdf2svg
)