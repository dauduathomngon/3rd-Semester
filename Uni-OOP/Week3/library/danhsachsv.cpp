#include "danhsachsv.h"

DanhSachSV::DanhSachSV()
: m_Size(0)
, m_Head(nullptr)
{
}

void DanhSachSV::MakeHead(const char* ten, const char* maSo, const char* ngaySinh)
{
    SinhVien sv(ten, maSo, ngaySinh);
    m_Head = MakeNode(sv);
}

void DanhSachSV::Delete()
{
    Node* temp = m_Head->next;
    while (temp != nullptr)
    {
        m_Head->next = temp->next;
        temp->next = nullptr;
        /* std::cout << "Delete Node: " << temp << "\n"; */
        delete temp;
        temp = m_Head->next;
    }
    /* std::cout << "Delete Node: " << m_Head << "\n"; */
    delete m_Head;
}

DanhSachSV::~DanhSachSV()
{
    Delete();
}

Node* DanhSachSV::MakeNode(const SinhVien& sv)
{
    return new Node {sv, nullptr};
}

void DanhSachSV::AddNode(const char* ten, const char* maSo, const char* ngaySinh)
{
    // create new sinh vien
    SinhVien newSV(ten, maSo, ngaySinh);

    // make node from sinh vien
    Node* newNode = MakeNode(newSV);

    // add node to list
    Node* current = m_Head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

// void DanhSachSV::Print()
// {
//     Node* current = m_Head;
//     while (current != nullptr)
//     {
//         PrintNode(current);
//         current = current->next;
//     }
// }

// void DanhSachSV::PrintNode(Node* current)
// {
//     std::cout << "Node: " << current << "\n";
//     std::cout << "Node point to: " << current->next << "\n";
// }