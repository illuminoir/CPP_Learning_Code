#include "MinuteHand.h"

MinuteHand::MinuteHand()
    : _minutes { 0 }
{}

int MinuteHand::get_minutes() const
{
    return _minutes;
}

void MinuteHand::advance()
{
    _minutes = (_minutes + 1) % 60;
}