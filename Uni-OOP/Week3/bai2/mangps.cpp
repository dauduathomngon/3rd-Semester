#include "mangps.h"

MangPS::MangPS()
    : m_Size(0)
    , m_pArr(nullptr)
{
}

MangPS::~MangPS()
{
    delete[] m_pArr;
}

MangPS::MangPS(const MangPS& arr)
    : m_Size(arr.m_Size)
    , m_pArr(new PhanSo[m_Size]())
{
    std::copy(arr.m_pArr, arr.m_pArr + m_Size, m_pArr);
}

void MangPS::Input()
{
    int n = 0;
    std::cout << "Moi ban nhap so luong phan so: ";
    std::cin >> n;

    if (m_Size != 0) { delete[] m_pArr; }

    m_Size = n;
    m_pArr = new PhanSo[m_Size]();

    for (int i = 0; i < m_Size; i++)
    {
        m_pArr[i].Input();
    }
}

void MangPS::Output()
{
    assert(m_Size > 0);
    for (int i = 0; i < m_Size; i++)
    {
        m_pArr[i].Print();
    }
}

PhanSo MangPS::GetSum() const
{
    PhanSo total;
    for (int i = 0; i < m_Size; i++)
    {
        total += m_pArr[i];
    }
    return total;
}

void MangPS::SortAscending()
{
    for (int i = 1; i < m_Size; i++)
    {
        int j = i - 1;
        while (j >= 0 && m_pArr[j] > m_pArr[j+1])
        {
            swap(m_pArr[j], m_pArr[j + 1]);
            --j;
        }
    }
}

void MangPS::WriteToFile()
{
    std::ofstream writeFile;
    writeFile.open("output.txt", std::ios_base::out | std::ios_base::trunc);

    for (int i = 0; i < m_Size; i++)
    {
        writeFile << m_pArr[i];
    }
}

void MangPS::ReadFromFile()
{
    int n = 0;

    std::ifstream readFile("input.txt");

    std::string line; 
    std::vector<std::vector<std::string>> lines;

    while (getline(readFile, line))
    {
        std::stringstream stream(line);
        std::string value;
        std::vector<std::string> lineValue;
        while (getline(stream, value, ','))
        {
            lineValue.push_back(value);
        }
        lines.push_back(lineValue);

        ++n;
    }

    if (m_Size != 0) { delete[] m_pArr; }

    m_Size = n;
    m_pArr = new PhanSo[m_Size]();

    for (int i = 0; i < lines.size(); i++)
    {
        for (int j = 0; j < lines[i].size(); j++)
        {
            m_pArr[i].SetValue(lines[i][1], lines[i][0]);
        }
    }
}
