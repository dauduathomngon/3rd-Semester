#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <string.h>
#include <algorithm>
#include <iostream>

const int MAX_STUDENTS = 40;

class Roster
{
public:
	Roster();
	~Roster();
	Roster(const Roster& rt);

	Roster* Clone() const;

	void AddStudent(const char* name);

	int GetSize() const;

	void Print();
private:
	char** m_StudentsName;
	int m_Size;
	
	void Delete();
};

#endif // ROSTER_H