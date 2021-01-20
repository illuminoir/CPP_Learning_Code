#pragma once

class MinuteHand {
    public:
        MinuteHand();
        int get_minutes() const;
        void advance();

    private:
        int _minutes;
};