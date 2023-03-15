#include "qlsinhvien.h"

/* Danh sach Sinh vien clas implementation */
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
        std::cout << "Delete Node: " << temp << "\n";
        delete temp;
        temp = m_Head->next;
    }
    std::cout << "Delete Node: " << m_Head << "\n";
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

void DanhSachSV::Print()
{
    Node* current = m_Head;
    while (current != nullptr)
    {
        PrintNode(current);
        current = current->next;
    }
}

void DanhSachSV::PrintNode(Node* current)
{
    std::cout << "Node: " << current << "\n";
    std::cout << "Node point to: " << current->next << "\n";
}

/*------------------------------------------*/
/* Quan ly Sinh vien class implementation */
void QL_SinhVien::GhiLenTapTin(std::string fileName)
{

}

void QL_SinhVien::DocTuTapTin(std::string fileName)
{

}

void QL_SinhVien::GhiDS_SV_TB(std::string fileName)
{

}

void QL_SinhVien::Update()
{

}

void QL_SinhVien::ThemSV(const char* ten, const char* maSo, const char* ngaySinh)
{
    m_DS.AddNode(ten, maSo, ngaySinh);
    Update();
}

void QL_SinhVien::XepLoaiSV()
{

}


void QL_SinhVien::XuatSV(std::string fileName)
{

}

std::string QL_SinhVien::GetCurrentTime()
{
    // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void QL_SinhVien::TimSV()
{
    std::string currentTime = GetCurrentTime();
}