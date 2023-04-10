#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "schedule.h"

class Student
{
public:
	Student();
	~Student();
	Student(const Student& st);

	friend void swap(Student& st1, Student& st2);
	Student& operator=(Student other);
	
	Schedule* GetSchedule();
	char* GetName() const;

	void InitSchedule();
	void SetValue(const char* var, int type);

	friend std::ostream& operator<<(std::ostream& os, const Student& st);

	void Print();
private:
	char* m_ID;
	char* m_Name;
	char* m_Address;
	char* m_Birthday;
	Schedule* m_Schedule;
};

#endif // STUDENT_H