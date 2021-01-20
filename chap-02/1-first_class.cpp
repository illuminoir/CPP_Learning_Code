#include <iostream>
/*
class Person
{
private:
    unsigned int         _age = 0u; //primitive type, must be initialized
    std::string _name;

public:
    void set_name(const std::string& name){ _name = name; }
    void set_age(int age){ _age = age; }
    const std::string& get_name() const { return _name; }
    unsigned int get_age() const { return _age; }
};

int main()
{
    Person p;

    p.set_name("Batman");
    p.set_age(23);

    std::cout << "Person named '" << p.get_name() << "' is " << p.get_age() << " years old." << std::endl;

    return 0;
}*/



class Toto
{
public:
    Toto() : Toto(3), _value2(5)
    {}

    Toto(int v1) : _value1(v1)
    {}

private:
    int _value1;
    int _value2;
};

