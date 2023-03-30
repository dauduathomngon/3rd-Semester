#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

const int defaultID = 100000000;

class Student : public Person
{
public:
    //Constructors
    Student();
    Student(long identity, double gpa);
    ~Student();
    Student(const Student& student);

    //getter(); setter()
    double getGpa() const;
    void setGpa(double gpa);

    //Other methods
    void print();

    // operator =
    Student& operator=(const Student& other);
private:
    double gpa;
};

#endif // STUDENT_H