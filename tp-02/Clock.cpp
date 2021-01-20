#include "Clock.h"

// bool isNotifyTime(Event e, int current_min, int current_sec)
// {
//     return e.notify_time(current_min, current_sec);
// }

void Clock::tick()
{
    /*
    _events.erase(
        std::remove_if(_events.begin(), _events.end(),
                    [](Event e){ return isNotifyTime(e, )}),
            _events.end()  
    );
    */

    for(auto it = _events.begin() ; it != _events.end() ; it++)
    {
        if(it->notify_time(_minutes.get_minutes(), _seconds.get_seconds()))
        {
            //_events.erase(it);
        }
    }

    _seconds.advance();

    if(_seconds.get_seconds() == 0)
    {
        _minutes.advance();
    }
} 

void Clock::print()
{
    std::cout << _minutes.get_minutes() << ":" << _seconds.get_seconds() << std::endl;
}

Clock::Clock()
    : _minutes { MinuteHand() }, _seconds { SecondHand() }
{}


void Clock::add_event(const Event& event)
{
    _events.emplace_back(event);
}


int main(int argc, char const *argv[])
{
    Clock c;

    auto events = parse_events(argc, argv);
    std::cout << "yes" << std::endl;
    for(auto event : events)
    {
        c.add_event(event);
    }

    std::cout << "no" << std::endl;

    for(int i = 0 ; i < 620 ; i++)
    {
        c.tick();
    }
    return 0;
}