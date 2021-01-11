set(executables
    1-hello_world
    2-parrot
    3-array
    4-calculator
)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

foreach(executable ${executables})
    add_executable(c1-${executable} ${executable}.cpp)
endforeach()
