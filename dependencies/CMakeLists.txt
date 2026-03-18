add_subdirectory(CAPD)
add_subdirectory(raylib)

# find_program(GNUPLOT_EXECUTABLE gnuplot REQUIRED)

set(INCLUDE_DIRECTORIES
)

set(LINK_LIBRARIES
    capd
    raylib
)

set(INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES} PARENT_SCOPE)
set(LINK_LIBRARIES ${LINK_LIBRARIES} PARENT_SCOPE)
