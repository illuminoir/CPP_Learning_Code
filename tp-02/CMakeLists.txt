set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(tp2-reminders
    Reminders.cpp
    Event.h
    Parsing.cpp
    Parsing.h
)

add_executable(ex1 ex1.cpp)
add_executable(histogram histogram.cpp histogram.h)
add_executable(clock 
	Clock.cpp
	Clock.h
	SecondHand.cpp
	SecondHand.h
	MinuteHand.cpp
	MinuteHand.h	
    Event.h
    Event.cpp
    Parsing.cpp
    Parsing.h
)
