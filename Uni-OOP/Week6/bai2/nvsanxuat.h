#pragma once
#ifndef NVSANXUAT_H
#define NVSANXUAT_H

#include "nhanvien.h"

class NVSanXuat : public NhanVien
{
public:
	// constructor
	NVSanXuat();
	NVSanXuat(const NVSanXuat& sx);

	// destructor
	~NVSanXuat() override;

	// clone method
	NVSanXuat* Clone() const override;

	// input/output
	void Input() override;
	void Output() override;
	/*void SetValue(int type, const char* val) override;*/

	// getter
	float GetSalary() const override;
	char* GetType() const override;

private:
	int m_ProductQuantity;
};

#endif // NVSANXUAT_H