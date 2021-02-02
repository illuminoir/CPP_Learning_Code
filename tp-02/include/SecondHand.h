#pragma once

#include "MinuteHand.h"

class SecondHand {
    public:
        SecondHand(MinuteHand&);
        SecondHand();
        int get_seconds() const;
        void advance();
        void operator=(SecondHand&);

    private:
        int _seconds;
        MinuteHand& _min_hand;
};