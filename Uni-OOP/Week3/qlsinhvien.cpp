#include "qlsinhvien.h"

QL_SinhVien::QL_SinhVien()
: m_Size(0)
, m_DanhSach(nullptr)
, isWriteAvg(false)
, isWriteRank(false)
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
    // check has read
    if (m_Size == 0)
    {
        std::cout << std::endl;
        std::cout << "<---- Warning ----> \n";
        std::cout << "Ban chua doc bat ki danh sach sinh vien nao \n";
        std::cout << "Hay chon option 2 de doc file roi thuc hien lai ghi file \n";
        std::cout << "<-----------------> \n";
        std::cout << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "<-----------------> \n";
    std::cout << "Dang ghi file ... \n";

    std::ofstream writeFile;

    // delete all contents before write to it
    writeFile.open("output.txt", std::ofstream::out | std::ofstream::trunc);

    writeFile << "Danh sach cac sinh vien: \n";
    writeFile << "Ten | Ma so | Ngay sinh | Diem bai tap | Diem giua ky | Diem cuoi ky\n";
    for (int i=0; i < m_Size; i++)
    {
        writeFile << m_DanhSach[i];
    }

    // if write average before, rewrite it
    if (isWriteAvg)
    {
        WriteBelowAvg();
    }

    // if write rank before, rewrite it
    if (isWriteRank)
    {
        RankSV(false, true);
    }

    std::cout << "Da ghi xong, moi ban check file output.txt \n";
    std::cout << "<-----------------> \n";
    std::cout << std::endl;
}

/*
read data from input.txt and write to array
*/
void QL_SinhVien::ReadFromFile()
{
    std::cout << std::endl;
    std::cout << "<-----------------> \n";
    std::cout << "Dang doc file ...... \n";

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

    std::cout << "Da doc xong <3 \n";
    std::cout << "<-----------------> \n";
    std::cout << std::endl;
}

/*
use for debugging
*/
void QL_SinhVien::Print()
{
    for (int i=0; i < m_Size; i++)
    {
        m_DanhSach[i].Output();
    }
}

void QL_SinhVien::WriteBelowAvg()
{
    if (isWriteAvg)
    {
        std::cout << "Da ghi diem trung binh vao file, ko the ghi lai \n";
        std::cout << "Neu co thay doi nao trong file input thi hay chon Ghi vao file \n";
        std::cout << "Neu muon them sinh vien thi hay chon Them sinh vien \n";
        return;
    }

    std::cout << std::endl;
    std::cout << "<-----------------> \n";
    std::cout << "Dang ghi diem trung binh vao file ...... \n";

    float classAvg = GetAvgMark();

    std::ofstream writeFile;
    writeFile.open("output.txt", std::ios_base::app);

    writeFile << std::endl;
    writeFile << "--------------------- \n";
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
    writeFile << "---------------------"
              << std::endl
              << std::endl;

    isWriteAvg = true;

    std::cout << "Da ghi xong, moi ban check file output.txt \n";
    std::cout << "<-----------------> \n";
    std::cout << std::endl;
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
    
    SinhVien* temp = new SinhVien[m_Size + 1]();
    // copy to temp
    std::copy(m_DanhSach, m_DanhSach + m_Size, temp);
    // delete danh sach
    delete[] m_DanhSach;
    // increase size
    ++m_Size;
    // add new sv to new danh sach
    m_DanhSach = temp;
    m_DanhSach[m_Size - 1] = newSV;

    // rewrite
    WriteToFile();
}

void QL_SinhVien::RankSV(bool output, bool write)
{
    if (isWriteRank)
    {
        std::cout << "Da ghi xep loai sinh vien vao file, khong the ghi lai \n";
        std::cout << "Neu co thay doi nao trong file input thi hay chon Ghi vao file \n";
        std::cout << "Neu muon them sinh vien thi hay chon Them sinh vien \n";
        return;
    }

    // create temp vector to sort
    std::vector<SinhVien> temp;

    // copy danh sach to temp vector
    // ref: https://stackoverflow.com/questions/259297/how-do-you-copy-the-contents-of-an-array-to-a-stdvector-in-c-without-looping
    temp.reserve(temp.size() + m_Size);
    std::copy(&m_DanhSach[0], &m_DanhSach[m_Size], std::back_inserter(temp));

    // sort temp array based on average mark
    std::sort(temp.begin(), temp.end(), SortByMark());

    // print to screen
    if (output)
    {
        std::cout << std::endl;
        std::cout << "<-------------------->\n";
        for (int i=0; i < temp.size(); i++)
        {
            std::cout << "Hang " << i + 1 << " : " << temp[i];
        }
        std::cout << "<-------------------->\n";
        std::cout << std::endl;
    }

    // or write to file
    if (write)
    {
        std::cout << std::endl;
        std::cout << "<-----------------> \n";
        std::cout << "Dang ghi xep loai vao file ...... \n";

        std::ofstream writeFile;
        writeFile.open("output.txt", std::ios_base::app);

        writeFile << "--------------------- \n";
        writeFile << "Xep loai sinh vien: \n";
        writeFile << "Thu hang | Ten | Ma so | Ngay sinh | Diem bai tap | Diem giua ky | Diem cuoi ky\n";
        for (int i=0; i < temp.size(); i++)
        {
            writeFile << i + 1 << " | " << temp[i];
        }
        writeFile << "---------------------"
                  << std::endl 
                  << std::endl;

        isWriteRank = true;

        std::cout << "Da ghi xong <3 \n";
        std::cout << "<-----------------> \n";
        std::cout << std::endl;
    }
}

void QL_SinhVien::WriteDate()
{
    std::string today = GetCurrentDate();

    std::cout << std::endl;
    std::cout << "<-------------------->\n";
    std::cout << "Ngay hien tai la: " << today << "\n";
    std::cout << "Tat ca cac sinh vien co ngay sinh la hom nay: \n";
    for (int i=0; i < m_Size; i++)
    {
        if (m_DanhSach[i].GetDate() == today)
        {
            std::cout << m_DanhSach[i];
        }
    }
    std::cout << "<--------------------->"
              << std::endl
              << std::endl;
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