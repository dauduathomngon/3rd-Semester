#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include <cassert>

class Person
{
public:
    //Constructors
    Person();
    Person(long id);
    ~Person();
    Person(const Person& person);

    //getter, setter
    long getId() const;
    void setId(long id);

    //other methods
    void print();
    
    // operator =
    Person& operator=(const Person& other);
private:
    long identity;
};

#endif // PERSON_H