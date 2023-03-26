#include "mangps.h"

int main()
{
    //MangPS arr1;
    //// nhap mang phan so
    //arr1.Input();
    //// xuat mang
    //arr1.Output();

    MangPS arr2;
    // doc tu file
    arr2.ReadFromFile();
    // xuat mang
    arr2.Output();
    // ghi mang vao file
    arr2.WriteToFile();

    return 0;
}