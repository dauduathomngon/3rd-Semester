#include "qlsinhvien.h"

QL_SinhVien::QL_SinhVien()
: m_Input(IN_PATH + "/in.txt")
, m_Output(OUT_PATH + "/in_out.txt")
{
}

/* Private function */

void QL_SinhVien::Out(int status)
{
    std::string outFile = "";
    std::string ex = m_Input.substr(0, m_Input.find("."));

    // 0: out
    // 1: xeploai
    // 2: duoitb
    switch (status)
    {
    case 0:
        outFile = ex + "_out.txt";
        break;
    case 1:
        outFile = ex + "_xeploai.txt";
        break;
    case 2:
        outFile = ex + "_duoitb.txt";
        break;
    }

    m_Output = outFile;

    if (IsFileExists(OUT_PATH + outFile))
    {
        Update();
    }
    else
    {
        Write();
    }

}

void QL_SinhVien::Update()
{
}

void QL_SinhVien::Write()
{
}

void QL_SinhVien::Read()
{
    std::vector<std::string> lines;

    std::ifstream inputFile(m_Input);

    // read line to vector
    while (!inputFile.eof())
    {
        std::string line;
        inputFile >> line;
        lines.push_back(line);
    }

    // tach string 
    for (int i=0; i < lines.size(); i++)
    {
    }
}

/* Public function */

void QL_SinhVien::ReadFile()
{
    std::vector<std::string> allFiles;
    GetFilesInDirectory(allFiles, IN_PATH);

    for (int i=0; i < allFiles.size(); i++)
    {
        std::cout << i + 1 << ". " << allFiles[i] << "\n";
    }

    int choice = 0;
    std::cout << "Moi ban nhap so de chon file input mac dinh: ";
    std::cin >> choice;

    // m_Input = allFiles[choice];

    std::cout << m_Input << "\n";

    // Read();

    std::cout << "Da doc xong \n";
}

void QL_SinhVien::WriteFile()
{
    // Out(0);
}

void QL_SinhVien::AddSV()
{
    std::string tenSV;
    std::string maSoSV;
    std::string ngaySinhSV;

    std::cout << "Moi ban nhap ten sinh vien: ";
    getline(std::cin, tenSV);
    std::cout << "Moi ban nhap ma so sinh vien: ";
    getline(std::cin, maSoSV);
    std::cout << "Moi ban nhap ngay sinh sinh vien: ";
    getline(std::cin, ngaySinhSV);

    m_DS.AddNode(tenSV.c_str(), maSoSV.c_str(), ngaySinhSV.c_str());

    Out(0);
}

/*-----------------------------------------*/