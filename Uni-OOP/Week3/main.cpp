#include "qlsinhvien.h"
// #include "sinhvien.h"

int main()
{
    DanhSachSV ll;

    ll.MakeHead("lenguyen", "324123", "fdasda");
    ll.AddNode("lenguyen", "2120141", "134134");
    ll.AddNode("lenguyen", "2120141", "fadhad");
    ll.AddNode("fafdasd", "2120141", "fadhad");
    ll.Print();
    return 0;
}