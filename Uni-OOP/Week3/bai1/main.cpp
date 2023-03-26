#include "myintarray.h"

int main()
{
    MyIntArray arr1;
    // goi ham nhap
    arr1.Input();

    // goi copy constructor, copy tu arr1 sang arr2;
    MyIntArray arr2 (arr1); // MyIntArray arr2 = arr1 van goi copy constructor chu ko goi ham =

    MyIntArray arr3;
    // goi ham gan bang, gan arr3 sang arr2
    arr3 = arr2;

    arr1.Print();
    arr2.Print();
    arr3.Print();
    return 0;
}