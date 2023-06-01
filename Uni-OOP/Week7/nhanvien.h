#pragma once
#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <time.h>
#include <string.h>
#include <cassert>

#include "InputException.h"

const float NVCN_SALARY = 500.000f;
const float NVSX_SALARY = 50.000f;
const int MAX_LEN = 100;

class NhanVien
{
public:
	// constructor
	NhanVien();
	NhanVien(const NhanVien& nv);

	// destructor
	virtual ~NhanVien();

	// clone method
	virtual NhanVien* Clone() const;

	// input/output
	virtual void Input();
	virtual void Output();
	/*virtual void SetValue(int type, const char* val);*/

	// getter
	virtual float GetSalary() const;
	char* GetID() const;
	char* GetName() const;
	int GetMonthOfBirth() const;
	int GetAge() const;
	virtual char* GetType() const;

protected:
	char* m_ID; // toi da 5 ki tu
	char* m_Name;
	char* m_Birthday;
	char* m_Address;
	char* m_Gender; // tuoi nhan vien la 18-60 cho nam
					// 18-55 cho nu
private:
	void SetString(char*& des, const char* src);
	void InputString(char*& des, int type);
	bool CheckAge();
	int FindAge() const;
};

/*
nguon tham khao:
- https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
- https://stackoverflow.com/questions/35258285/how-to-use-localtime-s-with-a-pointer-in-c
- https://stackoverflow.com/questions/40100507/how-do-i-get-the-current-date-in-c
*/
inline std::string GetCurrentYear()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	char buffer[80];
	strftime(buffer, 80, "%Y", &newtime);

	std::string str(buffer);
	return str;
}

#endif // NHANVIEN_H