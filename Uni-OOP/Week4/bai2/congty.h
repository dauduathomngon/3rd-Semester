#pragma once
#ifndef CONGTY_H
#define CONGTY_H

#include <cassert>
#include <fstream>

#include "nvcongnhat.h"
#include "nvsanxuat.h"

class CongTy
{
public:
	CongTy();

	CongTy(const CongTy& ct);

	~CongTy();

	friend void swap(CongTy& ct1, CongTy& ct2);

	CongTy& operator=(CongTy other);

	void Input();

	void Output();

	float GetSalary() const;

	float GetHighestSalary() const;

	void FindHighestSalary();

	float GetAvgSalary() const;

	void FindID(std::string id);

	void FindName(std::string name);

	void FindMonth(std::string month);

	void AddNV(); // add theo y muon

	void RemoveNV(); // remove theo y muon

	void WriteBelowAvg();

private:
	NhanVien** m_DanhSachNV;
	int m_Size;

	void Delete();
	NhanVien* InputNV();
	void Remove(int pos);
};

#endif // CONGTY_H
