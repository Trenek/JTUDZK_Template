cmake_minimum_required(VERSION 3.30)

project(Project VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(dependencies)

add_executable(Example
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)
target_link_libraries(Example ${LINK_LIBRARIES} -lstdc++exp)
target_include_directories(Example PUBLIC
    ${INCLUDE_DIRECTORIES}
)
