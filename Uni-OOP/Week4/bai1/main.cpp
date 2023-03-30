#include "student.h"

int main()
{
    Student s;
    s.print();

    Student s1(100200300, 3.5);
    s1.print();

    Student s2 = s1;
    s2.print();

    Student s3;
    s3 = s1;
    s3.print();

    return 0;
}