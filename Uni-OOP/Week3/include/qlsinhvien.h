#ifndef QLSINHVIEN_H
#define QLSINHVIEN_H

#include "danhsachsv.h"
#include "helper.h"

using namespace helper;

const std::string OUT_PATH = "../output";
const std::string IN_PATH = "../input";

// QL Sinh Vien
class QL_SinhVien
{
public:
    QL_SinhVien();

    void ReadFile();
    void WriteFile();
    void AddSV();
    
private:
    DanhSachSV m_DS;
    std::string m_Input;
    std::string m_Output;

    // update existing file
    void Update();

    // read from input file
    void Read();

    // create new file and write on it
    void Write();

    void Out(int status);

    // list all file in folders

    // use this to get current time
};

#endif // QLSINHVIEN_H