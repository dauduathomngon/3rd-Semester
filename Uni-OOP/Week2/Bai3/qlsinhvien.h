#pragma once
#ifndef QL_SINHVIEN_H
#define QL_SINHVIEN_H

#include <fstream>
#include <time.h>
#include <vector>
#include <sstream>
#include <algorithm>

#include "sinhvien.h"

const int SV_DATA_SIZE = 6;

class QL_SinhVien
{
public:
    QL_SinhVien();

    ~QL_SinhVien();

    // DONE
    void WriteToFile();

    // DONE
    void ReadFromFile();

    // DONE
    void Print();

    // DONE
    void WriteBelowAvg();

    // DONE
    void WriteNewSV();

    // DONE
    void RankSV(bool output, bool write);

    // DONE
    void WriteDate();

private:
    SinhVien* m_DanhSach;
    int m_Size;

    bool isWriteAvg;
    bool isWriteRank;

    void UpdateArr();

    float GetAvgMark() const;

    // use for input data for sinh vien
    void AddData(int input, SinhVien& sv);
};

/*
ref:
- https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
- https://stackoverflow.com/questions/35258285/how-to-use-localtime-s-with-a-pointer-in-c
- https://stackoverflow.com/questions/40100507/how-do-i-get-the-current-date-in-c
*/
inline std::string GetCurrentDate()
{
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime,&now);

    char buffer[80];
    strftime(buffer, 80, "%d/%m", &newtime);

    std::string str(buffer);
    return str;
}

/* ref: https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects */
struct SortByMark
{
    inline bool operator() (const SinhVien& sv1, const SinhVien& sv2)
    {
        return (sv1.AvgMark() > sv2.AvgMark());
    }
};

#endif // QL_SINHVIEN_H