#include "../include/Event.h"


bool Event::notify_time(int current_min, int current_sec)
{
    if (std::get<0>(_notif_time) == current_min
    &&  std::get<1>(_notif_time) == current_sec)
    {
        std::cout << _message << std::endl;
        return true;
    }   

    return false;
}
