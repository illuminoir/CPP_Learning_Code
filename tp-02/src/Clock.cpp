#include "../include/Clock.h"

void Clock::tick()
{

    //seg fault on "it != _events.end()"
    //if we notify the event and then iterate (it++)
    //we skip _events.end(), '<' necessary?
    for(auto it = _events.begin() ; it < _events.end() ; it++)  
    {
        if(it->notify_time(_minutes.get_minutes(), _seconds.get_seconds()))
        {
            it = _events.erase(it); 
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

    std::vector<Event> events = parse_events(argc, argv);
    for(Event event : events)
    {
        c.add_event(event);
    }

    for(int i = 0 ; i < 620 ; i++)
    {
        c.tick();
    }
    return 0;
}