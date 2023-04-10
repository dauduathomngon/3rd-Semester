#include "manager.h"

Manager::Manager()
: m_StudentList(nullptr)
, m_StudentSize(0)
, m_CourseList(nullptr)
, m_CourseSize(0)
, m_Registrar()
{
}

Manager::~Manager()
{
	delete[] m_StudentList;
	delete[] m_CourseList;
}

void Manager::Register()
{
	if (CheckEmptyStudent())
	{
		return;
	}

	if (CheckEmptyCourse())
	{
		return;
	}

	int sIdx = ChooseStudent() - 1;
	if (sIdx == -1)
	{
		AddStudent();
		sIdx = m_StudentSize - 1;
	}

	int cIdx = ChooseCourse() - 1;
	if (cIdx == -1)
	{
		AddCourse();
		cIdx = m_CourseSize - 1;
	}

	bool result = m_Registrar.Enroll(m_StudentList[sIdx], m_CourseList[cIdx]);
	if (!result)
	{
		std::cout << "Khong dang ky khoa hoc thanh cong \n";
	}
}

void Manager::ReadCourseFromFile()
{
	std::ifstream readFile("courseInput.txt");
	std::string line;
	std::vector<std::vector<std::string>> lines;
	int numOfLines = 0;

	// read file
	while (getline(readFile, line))
	{
		std::stringstream readLine(line);
		std::string value;
		std::vector<std::string> vectorLine;
		while (getline(readLine, value, ','))
		{
			vectorLine.push_back(value);
		}
		lines.push_back(vectorLine);
		++numOfLines;
	}

	// update arr
	if (m_CourseSize != 0)
	{
		delete[] m_CourseList;
	}
	m_CourseSize = numOfLines;
	m_CourseList = new Course[m_CourseSize]();

	// set value
	for (int i = 0; i < lines.size(); i++)
	{
		m_CourseList[i].InitRoster();
		for (int j = 0; j < lines[i].size(); j++)
		{
			m_CourseList[i].SetValue(lines[i][j].c_str(), j);
		}
	}
}

void Manager::WriteStudentToFile()
{
	if (CheckEmptyStudent())
	{
		return;
	}

	std::ofstream writeFile;
	writeFile.open("studentOutput.txt", std::ios_base::trunc | std::ios_base::out);

	writeFile << "Ma so | Ten | Dia chi | Ngay Sinh | Cac khoa hoc \n";
	for (int i = 0; i < m_StudentSize; i++)
	{
		writeFile << m_StudentList[i];
	}
}

void Manager::ReadStudentFromFile()
{
	std::ifstream readFile("studentInput.txt");
	std::string line;
	std::vector<std::vector<std::string>> lines;
	int numOfLines = 0;

	// read file
	while (getline(readFile, line))
	{
		std::stringstream readLine(line);
		std::string value;
		std::vector<std::string> vectorLine;
		while (getline(readLine, value, ','))
		{
			vectorLine.push_back(value);
		}
		lines.push_back(vectorLine);
		++numOfLines;
	}

	// update arr
	if (m_StudentSize != 0)
	{
		delete[] m_StudentList;
	}
	m_StudentSize = numOfLines;
	m_StudentList = new Student[m_StudentSize]();

	// set value
	for (int i = 0; i < lines.size(); i++)
	{
		m_StudentList[i].InitSchedule();
		for (int j = 0; j < lines[i].size(); j++)
		{
			m_StudentList[i].SetValue(lines[i][j].c_str(), j);
		}
	}
}

void Manager::PrintStudentCourse()
{
	int idx = ChooseCourse() - 1;

	if (idx == -1)
	{
		AddCourse();
		idx = m_CourseSize - 1;
	}

	m_CourseList[idx].Print();
}

void Manager::PrintStudentSchedule()
{
	int idx = ChooseStudent() - 1;

	if (idx == -1)
	{
		AddStudent();
		idx = m_StudentSize - 1;
	}

	m_StudentList[idx].Print();
}

void Manager::PrintStudent()
{
	std::cout << "Cac hoc sinh hien co: \n";
	for (int i = 0; i < m_StudentSize; i++)
	{
		std::cout << i + 1 << ". " << m_StudentList[i].GetName() << "\n";
	}
}

void Manager::PrintCourse()
{
	std::cout << "Cac khoa hoc hien co: \n";
	for (int i = 0; i < m_CourseSize; i++)
	{
		std::cout << i + 1 << ". " << m_CourseList[i].GetName() << "\n";
	}
}

void Manager::AddStudent()
{
	Student newSt;

	std::string ID;
	std::cout << "Nhap ID cua hoc sinh: ";
	getline(std::cin, ID);

	std::string name;
	std::cout << "Nhap ten cua hoc sinh: ";
	getline(std::cin, name);

	std::string address;
	std::cout << "Nhap dia chi cua hoc sinh: ";
	getline(std::cin, address);

	std::string date;
	std::cout << "Nhap ngay sinh cua hoc sinh (vi du 27/03/2003): ";
	getline(std::cin, date);

	newSt.SetValue(ID.c_str(), 0);
	newSt.SetValue(name.c_str(), 1);
	newSt.SetValue(address.c_str(), 2);
	newSt.SetValue(date.c_str(), 3);
	newSt.InitSchedule();

	// them vao array
	UpdateStudentList(newSt);
}

void Manager::AddCourse()
{
	Course newCs;

	std::string ID;
	std::cout << "Nhap ID cua khoa hoc: ";
	getline(std::cin, ID);

	std::string name;
	std::cout << "Nhap ten cua khoa hoc: ";
	getline(std::cin, name);

	std::string date;
	std::cout << "Nhap ngay bat dau khoa hoc (vi du 14/03/2023): ";
	getline(std::cin, date);

	newCs.SetValue(ID.c_str(), 0);
	newCs.SetValue(name.c_str(), 1);
	newCs.SetValue(date.c_str(), 2);
	newCs.InitRoster();

	// them vao array
	UpdateCourseList(newCs);
}

int Manager::ChooseStudent()
{
	PrintStudent();

	std::cout << "Moi ban chon sinh vien (chon 0 de them sinh vien moi va chon sinh vien do): ";

	int choice = 0;
	std::cin >> choice;

	return choice;
}

int Manager::ChooseCourse()
{
	PrintCourse();

	std::cout << "Moi ban chon khoa hoc (chon 0 de them khoa hoc moi va chon khoa hoc do): ";

	int choice = 0;
	std::cin >> choice;

	return choice;
}

void Manager::UpdateStudentList(const Student& st)
{
	// copy to temp
	Student* temp = new Student[m_StudentSize + 1]();

	for (int i = 0; i < m_StudentSize; i++)
	{
		temp[i] = m_StudentList[i];
	}
	temp[m_StudentSize] = st;

	// delete arr
	delete[] m_StudentList;
	m_StudentSize++;
	m_StudentList = temp;
}

void Manager::UpdateCourseList(const Course& cs)
{
	// copy to temp
	Course* temp = new Course[m_CourseSize + 1]();

	for (int i = 0; i < m_CourseSize; i++)
	{
		temp[i] = m_CourseList[i];
	}
	temp[m_CourseSize] = cs;

	// delete arr
	delete[] m_CourseList;
	m_CourseSize++;
	m_CourseList = temp;
}

bool Manager::CheckEmptyStudent()
{
	if (m_StudentSize == 0)
	{
		std::cout << "Hien tai danh sach sinh vien dang trong \n";
		std::cout << "Moi ban chon doc sinh vien tu file de chay chuc nang nay \n";
		return true;
	}
	return false;
}

bool Manager::CheckEmptyCourse()
{
	if (m_CourseSize == 0)
	{
		std::cout << "Hien tai danh sach khoa hoc dang trong \n";
		std::cout << "Moi ban chon doc khoa hoc tu file de chay chuc nang nay \n";
		return true;
	}
	return false;
}
