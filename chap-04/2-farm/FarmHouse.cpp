// // #include "Animal.h"
// // #include "Cat.h"
// // #include "Chicken.h"
// // #include "Cow.h"
// // #include "Dog.h"

// // #include <vector>
// // #include <iostream>

// // void sing_a_lot(const Animal& animal, unsigned int times)
// // {
// //     while (times-- > 0)
// //     {
// //         animal.sing(' ');
// //     }

// //     animal.sing('\n');
// // }

// // void sing_chorus(const std::vector<Animal*>& animals)
// // {
// //     for(const auto* animal : animals)
// //     {
// //         animal->sing(' ');
// //     }

// //     std::cout << std::endl;
// // }

// // int main()
// // {
// //     Cat cat;
// //     Chicken chicken;
// //     Dog dog;
// //     Cow cow;

// //     sing_a_lot(cat, 2u);
// //     sing_a_lot(dog, 1u);
// //     sing_a_lot(cow, 3u);
// //     sing_a_lot(dog, 1u);
// //     sing_a_lot(chicken, 2u);


// //     std::vector<Animal*> tmp;

// //     tmp.push_back(&cat);
// //     tmp.push_back(&dog);

// //     sing_chorus(tmp);

// //     return 0;
// // }


// #include <iostream>

// class A
// {
// public:
//     virtual int  fcn1(int p1, int p2) const { return p1 * p2; }
//     virtual void fcn2(const char* str) = 0;
//     virtual void fcn3(bool) {}
//     const char*  fcn4() { return "artichaut"; }
// };

// class B : public A
// {
// public:
//     int fcn1(int p1, int p2){ return p1 + p2; }

//     void fcn2(const char*) override {}

//     void fcn3(bool b)
//     {
//         if (b)
//         {
//             A::fcn3(b);
//         }
//     }
    
//     const char* fcn4() { return "sopalin"; }
// };


// int main()
// {
//     A* a = new B();

//     auto c = a->fcn1(1, 3);
//     a->fcn2("la la la");
//     a->fcn3(false);
//     auto b = a->fcn4();

//     std::cout << b << " | " << c << std::endl;

//     return 0;
// }



class SharedStuff {
    protected:
        SharedStuff(int value)
            : _value { value }
        {}

    
        int _value;
};

class MoreStuff : public SharedStuff {
    private:
        int _value2;

    public:
        MoreStuff(int value, int value2)
            : SharedStuff { value }, _value2 { value2 }
        {}
};

#include <iostream>

class Food {
    public:
        virtual void miam_miam() const = 0;
};

class Nutella : public Food {
    public:
        void miam_miam() const override 
        {
            std::cout << "j'ai faim" << std::endl;
        }
};

int main(int argc, char const *argv[])
{
    Nutella n;

    n.miam_miam();
    
    return 0;
}
