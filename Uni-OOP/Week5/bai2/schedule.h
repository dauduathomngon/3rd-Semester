#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string.h>
#include <algorithm>
#include <iostream>

const int MAX_COURSES = 5;

class Schedule
{
public:
	Schedule();
	~Schedule();
	Schedule(const Schedule& sc);

	Schedule* Clone() const;

	bool AddCourse(const char* name);

	int GetSize() const;

	void Print();

	char* GetStudentName(int idx) const;
private:
	char** m_CoursesName;
	int m_Size;

	void Delete();
};

#endif // SCHEDULE_H