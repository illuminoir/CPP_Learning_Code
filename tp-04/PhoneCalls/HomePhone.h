#pragma once

#include "Phone.h"

class HomePhone : public Phone {
    public:
        ~HomePhone() {}
        HomePhone(const Person& owner, int position) 
            : Phone { owner }, _position { position }
        {}

        void ring() const override 
        {
            if(_position != _owner.get_position())
            {
                std::cout << "This is the voicemail of " << _owner.get_name() << ". Please leave a message." << std::endl;
            }

            else
            {
                _owner.answer_phone();
            }
        }

    private:
        int _position;

};