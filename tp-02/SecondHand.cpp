#include "SecondHand.h"


SecondHand::SecondHand(MinuteHand& minutes)
    : _min_hand { minutes }
{
    _seconds = 0;
}

SecondHand::SecondHand()
    : SecondHand { _min_hand }
{
    _seconds = 0;
}

void SecondHand::operator=(SecondHand& other)
{
    _seconds = other._seconds;
    _min_hand = other._min_hand;
}

int SecondHand::get_seconds() const
{
    return _seconds;
}

void SecondHand::advance()
{
    _seconds = (_seconds + 1) % 60;
}