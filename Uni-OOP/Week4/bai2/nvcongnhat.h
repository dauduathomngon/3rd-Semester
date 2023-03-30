#pragma once
#ifndef NVCONGNHAT_H
#define NVCONGNHAT_H

#include "nhanvien.h"

class NVCongNhat : public NhanVien
{
public:
	NVCongNhat();

	NVCongNhat(const NVCongNhat& cn);

	NVCongNhat* Clone() const override;

	float GetSalary() const override;

	void Input() override;

	void Output() override;
private:
	int m_SoNgay;
};

#endif // NVCONGNHAT_H
