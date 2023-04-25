#pragma once
#ifndef NVCONGNHAT_H
#define NVCONGNHAT_H

#include "nhanvien.h"

class NVCongNhat : public NhanVien
{
public:
	// constructor
	NVCongNhat();
	NVCongNhat(const NVCongNhat& cn);

	// destructor
	~NVCongNhat() override;

	// clone method
	NVCongNhat* Clone() const override;

	// input/output
	void Input() override;
	void Output() override;
	void SetValue(int type, const char* val) override;

	// getter
	float GetSalary() const override;

private:
	int m_NumberOfDays;
};

#endif // NVCONGNHAT_H