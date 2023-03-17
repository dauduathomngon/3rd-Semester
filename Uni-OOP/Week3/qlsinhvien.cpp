#include "qlsinhvien.h"

QL_SinhVien::QL_SinhVien()
: m_Size(0)
, m_DanhSach(nullptr)
{
}

QL_SinhVien::~QL_SinhVien()
{
    delete[] m_DanhSach;
}

/*
write data from array to output.txt
*/
void QL_SinhVien::WriteToFile()
{
    // delete all contents before write to it
    DeleteOutput();

    std::ofstream writeFile("output.txt");
    writeFile << "---------------------\n";
    writeFile << "Danh sach cac sinh vien: \n";
    writeFile << "Ten | Ma so | Ngay sinh | Diem bai tap | Diem giua ky | Diem cuoi ky\n";
    for (int i=0; i < m_Size; i++)
    {
        writeFile << m_DanhSach[i];
    }
}

/*
read data from input.txt and write to array
*/
void QL_SinhVien::ReadFromFile()
{
    // update array before read and write data to array
    UpdateArr();

    // read file
    std::ifstream readFile("input.txt");
    std::string line;
    std::vector<std::vector<std::string>> lines;

    // write data to vector
    while (getline(readFile, line))
    {
        std::stringstream lineStream(line);
        std::string value;
        std::vector<std::string> lineValue;
        while (getline(lineStream, value, ','))
        {
            lineValue.push_back(value);
        }
        lines.push_back(lineValue);
    }

    // write data from vector to array
    for (int i=0; i < lines.size(); i++)
    {
        for (int j=0; j < lines[i].size(); j++)
        {
            m_DanhSach[i].SetValue(lines[i][j], j);
        }
    }
}

void QL_SinhVien::Print()
{
    for (int i=0; i < m_Size; i++)
    {
        m_DanhSach[i].Output();
    }
}

void QL_SinhVien::WriteBelowAvg()
{
    float classAvg = GetAvgMark();

    std::ofstream writeFile;
    writeFile.open("output.txt", std::ios_base::app);

    writeFile << "---------------------\n";
    writeFile << "Diem tb cua lop la: " << classAvg << "\n";
    writeFile << "Tat ca cac sinh vien co diem duoi trung binh: \n";
    for (int i=0; i < m_Size; i++)
    {
        float svAvgMark = m_DanhSach[i].AvgMark();
        if (svAvgMark < classAvg)
        {
            writeFile << m_DanhSach[i];
        }
    }
    writeFile << "--------------------- \n";
}

void QL_SinhVien::WriteNewSV()
{
    // create new sv
    SinhVien newSV;

    // add data to new sv
    for (int i=0; i < SV_DATA_SIZE; i++)
    {
        AddData(i, newSV);
    }

    // rewrite before append
    WriteToFile();

    // append new sv to ouput
    std::ofstream writeFile;
    writeFile.open("output.txt", std::ios_base::app);
    writeFile << newSV;

    // if write average before, rewrite it
    if (isWriteAvg)
    {
        WriteBelowAvg();
    }

    // if write rank before, rewrite it
    if (isWriteRank)
    {
        WriteRankSV();
    }
}

void QL_SinhVien::WriteRankSV()
{
    std::vector<float> markSV; 
    std::vector<float> posSV;

    // create mark SV
    for (int i=0; i < m_Size; i++)
    {
        markSV.push_back(m_DanhSach[i].AvgMark());
    }

    // create position of sinh vien
    for (int i=0; i < m_Size; i++)
    {
        posSV.push_back(i);
    }
}

void QL_SinhVien::UpdateArr()
{
    std::ifstream file("input.txt");
    int numOfLines = 0;
    std::string line;

    while (getline(file, line))
    {
        ++numOfLines;
    }

    if (m_Size != 0) 
    { 
        delete[] m_DanhSach; 
    }

    m_Size = numOfLines;
    m_DanhSach = new SinhVien[m_Size]();
}

float QL_SinhVien::GetAvgMark() const
{
    float total = 0;
    for (int i=0; i < m_Size; i++)
    {
        total += m_DanhSach[i].AvgMark();
    }
    return (total / static_cast<float>(m_Size)); 
}

void QL_SinhVien::AddData(int input, SinhVien& sv)
{
    std::string data;

    switch (input)
    {
    case 0:
        data = "ten";
        break;
    case 1:
        data = "ma so";
        break;
    case 2:
        data = "ngay sinh";
        break;
    case 3:
        data = "diem bai tap";
        break;
    case 4:
        data = "diem giua ky";
        break;
    case 5:
        data = "diem cuoi ky";
        break;
    default:
        break;
    }

    std::string val;
    std::cout << "Moi ban nhap " << data << " cua sinh vien: ";
    getline(std::cin, val);
    sv.SetValue(val, input);
}