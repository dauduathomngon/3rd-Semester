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

    for (int i=0; i < m_Size; i++)
    {
        m_pArr[i].Input();
    }
}

void MangPS::Output()
{
    assert(m_Size > 0);
    for (int i=0; i < m_Size; i++) 
    {
        m_pArr[i].Print();
    }
}

PhanSo MangPS::GetSum() const
{
    PhanSo total;
    for (int i=0; i < m_Size; i++) 
    {
        total += m_pArr[i];
    }
    return total;
}

void MangPS::SortAscending()
{
    // create vector for sorting
    std::vector<PhanSo> temp;
    temp.reserve(temp.size() + m_Size);
    // copy array to vector
    std::copy(&m_pArr[0], &m_pArr[m_Size], std::back_inserter(temp));
    // sort vector
    std::sort(temp.begin(), temp.end());

    // copy from vector to array
    for (int i=0; i < m_Size; i++)
    {
        m_pArr[i] = temp[i];
    }
}

void MangPS::WriteToFile()
{
    std::ofstream writeFile;
    writeFile.open("ouput.txt", std::ios_base::out | std::ios_base::trunc);

    for (int i=0; i < m_Size; i++)
    {
        writeFile << m_pArr[i];
    }
}

void MangPS::ReadFromFile()
{    
    int n = 0;

    std::ifstream readFile("input.txt");

    std::ifstream readFile("input.txt");
    std::string line; std::vector<std::vector<std::string>> lines;

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

    for (int i=0; i < lines.size(); i++)
    {
        for (int j=0; j < lines[i].size(); j++)
        {
            m_pArr[i].SetValue(lines[i][0], lines[i][1]);
        }
    }
}