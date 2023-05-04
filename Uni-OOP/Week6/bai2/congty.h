#pragma once
#ifndef CONGTY_H
#define CONGTY_H

#include <algorithm>
#include <fstream>
#include <vector>

#include "nvcongnhat.h"
#include "nvsanxuat.h"

class CongTy
{
public:
	// constructor
	CongTy();
	CongTy(const CongTy& ct);

	// destructor
	~CongTy();

	// = operator
	friend void swap(CongTy& ct1, CongTy& ct2);
	CongTy& operator=(CongTy other);

	// method
	void WriteToFile();
	void ReadFromFile();
	void WriteBelowAvg();

	void Input();
	void Output();

	void FindHighestSalary();
	void FindID(const char* ID);
	void FindName(const char* name);
	void FindMonth(int month);

	void AddEmployee();
	void RemoveEmployee();

	float GetTotalSalary() const;
	float GetAvgSalary() const;
	float GetHighestSalary() const;

private:
	NhanVien** m_DanhSachNV;
	int m_Size;

	void Delete();
	void Remove(int idx);
};

#endif // CONGTY_H