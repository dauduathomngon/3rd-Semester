#ifndef DANHSACHSV_H
#define DANHSACHSV_H

#include "sinhvien.h"

struct Node
{
    SinhVien data;
    Node* next;
};

// linked list
class DanhSachSV
{
public:
    // default constructor
    DanhSachSV();

    // destructor
    ~DanhSachSV();

    void MakeHead(const char* ten, const char* maSo, const char* ngaySinh);

    void AddNode(const char* ten, const char* maSo, const char* ngaySinh);

    // use for debugging
    // void Print();

    friend class QL_SinhVien;

private:
    Node* m_Head;
    int m_Size;

    // make new node
    Node* MakeNode(const SinhVien& sv);

    // delete linked list
    void Delete();
    
    // use for debugging
    // void PrintNode(Node* current);
};

#endif // DANHSACHSV_H