#pragma once
#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
#include <iostream>

const float NVSX_LUONG = 20000.0f;
const float NVCN_LUONG = 300000.0f;

class NhanVien
{
public:
	// constructor
	NhanVien() = default;
	NhanVien(const NhanVien& nv)
	: m_ID(nv.m_ID)
	, m_Ten(nv.m_Ten)
	, m_NgaySinh(nv.m_NgaySinh)
	, m_DiaChi(nv.m_DiaChi)
	{
	}

	// destructor
	virtual ~NhanVien() {}

	// clone method
	virtual NhanVien* Clone() const { return new NhanVien(*this); }

	// output
	virtual void Input() {}
	virtual void Output() {}

	// getter
	virtual float GetSalary() const { return 0.0f; }

	std::string GetID() const
	{
		return m_ID;
	}
	std::string GetName() const
	{
		return m_Ten;
	}
	std::string GetMonth() const
	{
		return m_NgaySinh.substr(3, 2);
	}

protected:
	std::string m_ID;
	std::string m_Ten;
	std::string m_NgaySinh;
	std::string m_DiaChi;
};

#endif // NHANVIEN_H
