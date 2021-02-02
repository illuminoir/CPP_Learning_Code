#include "Parsing.h"
#include "Clock.h"
#include <chrono>
#include <thread>

// You can call the program with the following command in order to queue 3 events at 2s, 1m3s and 10m :
// tp2-reminders.exe "0:2 2 event1" "1:3 1 min event2" "10:0 10 min event3"

int main(int argc, const char** argv)
{
    const auto events = parse_events(argc, argv);
    const auto program_duration = 15; 
    for (int i = 0; i < program_duration; ++i)
    {
        //c.tick();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
