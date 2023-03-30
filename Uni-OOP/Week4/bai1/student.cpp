#include "student.h"
Student::Student()
: gpa(0) // use default person constructor
{
}

Student::Student(long identity, double gpa)
: gpa(gpa)
, Person(identity)
{
}

Student::~Student()
{
}

Student::Student(const Student& student)
: gpa(student.gpa)
, Person(student.getId())
{
}

double Student::getGpa() const
{
    return gpa;    
}

void Student::setGpa(double gpa)
{
    this->gpa = gpa; 
}

void Student::print()
{
    std::cout << "Id: "  << this->getId() << "\n";
    std::cout << "Gpa: " << gpa << "\n";
}

Student& Student::operator=(const Student& other)
{
    gpa = other.gpa;
    this->setId(other.getId());
    return *this;
}