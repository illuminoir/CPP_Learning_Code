
# put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(ex1 src/ex1.cpp)
add_executable(histogram src/histogram.cpp include/histogram.h)
add_executable(clock 
	src/Clock.cpp
	include/Clock.h
	src/SecondHand.cpp
	include/SecondHand.h
	src/MinuteHand.cpp
	include/MinuteHand.h	
    src/Event.cpp
    include/Event.h
    src/Parsing.cpp
    include/Parsing.h
)


