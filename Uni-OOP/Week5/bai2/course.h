#pragma once
#ifndef COURSE_H
#define COURSE_H

#include "roster.h"

class Course
{
public:
	Course();
	~Course();
	Course(const Course& cs);

	friend void swap(Course& cs1, Course& cs2);
	Course& operator=(Course other);

	Roster* GetRoster();
	char* GetName() const;

	void InitRoster();
	void SetValue(const char* var, int type);

	void Print();
private:
	char* m_ID;
	char* m_Name;
	char* m_StartDate;
	Roster* m_Roster;
};

#endif // COURSE_H