#ifndef QLSINHVIEN_H
#define QLSINHVIEN_H

#include <string>
#include <fstream>
#include <time.h>
#include <stdio.h>

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

    void Print();

private:
    Node* m_Head;
    int m_Size;

    // make new node
    Node* MakeNode(const SinhVien& sv);

    // delete linked list
    void Delete();
    
    // print node
    void PrintNode(Node* current);
};

// QL Sinh Vien
class QL_SinhVien
{
public:
    void GhiLenTapTin(std::string fileName);
    void DocTuTapTin(std::string fileName);
    void GhiDS_SV_TB(std::string fileName);
    void ThemSV(const char* ten, const char* maSo, const char* ngaySinh);
    void XepLoaiSV();
    void XuatSV(std::string fileName);
    void TimSV();
    
private:
    DanhSachSV m_DS;

    void Update();

    /* use this to get current time */
    /* function reference: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c */
    std::string GetCurrentTime();
};

#endif // QLSINHVIEN_H