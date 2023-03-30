#pragma once
#ifndef NVSANXUAT_H
#define NVSANXUAT_H

#include "nhanvien.h"

class NVSanXuat : public NhanVien
{
public:
	NVSanXuat();

	NVSanXuat(const NVSanXuat& sv);

	NVSanXuat* Clone() const override;

	float GetSalary() const override;

	void Input() override;

	void Output() override;
private:
	int m_SanPham;
};

#endif // NVSANXUAT_H
