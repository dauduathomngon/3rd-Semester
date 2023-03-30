#include "person.h"

Person::Person()
: identity(100000000)
{
}

Person::Person(long id)
: identity(id)
{
    assert(identity >= 100000000 && identity <= 999999999);
}

Person::~Person()
{
}

Person::Person(const Person& person)
{
    identity = person.identity;
}

long Person::getId() const
{
    return identity;    
}

void Person::setId(long id)
{
    assert(id >= 100000000 && id <= 999999999);
    identity = id; 
}

void Person::print()
{
    std::cout << "Id: " << identity << "\n";
}

Person& Person::operator=(const Person& other)
{
    identity = other.identity;
    return *this;
}
