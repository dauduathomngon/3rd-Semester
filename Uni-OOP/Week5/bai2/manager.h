#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "registrar.h"

class Manager
{
public:
	Manager();
	~Manager();

	void Register();

	void ReadCourseFromFile();
	void WriteStudentToFile();
	void ReadStudentFromFile();

	void PrintStudentCourse();
	void PrintStudentSchedule();

	void PrintStudent(); // print available student
	void PrintCourse(); // print available course

	void AddStudent();
	void AddCourse();

private:
	Student* m_StudentList;
	int m_StudentSize;

	Course* m_CourseList;
	int m_CourseSize;

	Registrar m_Registrar;

	int ChooseStudent();
	int ChooseCourse();

	void UpdateStudentList(const Student& st);
	void UpdateCourseList(const Course& cs);

	bool CheckEmptyStudent();
	bool CheckEmptyCourse();
};

#endif // MANAGER_H