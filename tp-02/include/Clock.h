#pragma once

#include "MinuteHand.h"
#include "SecondHand.h"
#include "Event.h"
#include "Parsing.h"
#include <iostream>
#include <vector>
#include <algorithm>


class Clock {
    private:
        SecondHand _seconds;
        MinuteHand _minutes;
        std::vector<Event> _events;

    public:
        Clock();
        void tick();
        void print();
        void add_event(const Event&);
};