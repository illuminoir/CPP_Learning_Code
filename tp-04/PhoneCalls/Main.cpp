#include "Person.h"
#include "HomePhone.h"
#include "MobilePhone.h"

int main()
{
    Person paul { "Paul", 3 };

    //Phone normal_phone { paul };

    MobilePhone mobile_phone { paul };

    HomePhone far_phone { paul, -10 };
    far_phone.ring();

    const Phone& normal_phone = mobile_phone;
    normal_phone.ring();

    return 0;
}
