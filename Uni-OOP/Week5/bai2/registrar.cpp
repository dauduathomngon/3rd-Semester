#include "registrar.h"

Registrar::Registrar()
{
}

Registrar::~Registrar()
{
}

bool Registrar::Enroll(Student& st, Course& cs)
{
	// vuot qua gioi han khoa hoc cua mot hoc sinh
	if (st.GetSchedule()->GetSize() == MAX_COURSES)
	{
		std::cout << "Ban da vuot qua so luong khoa hoc toi da co the dang ky \n";
		return false;
	}

	// vuot qua gioi han hoc sinh cua mot khoa hoc
	if (cs.GetRoster()->GetSize() == MAX_STUDENTS)
	{
		std::cout << "So luong hoc sinh cua khoa hoc da dat toi da \n";
		return false;
	}

	// them khoa hoc cho sinh vien
	if (st.GetSchedule()->AddCourse(cs.GetName()))
	{
		std::cout << "Sinh vien " << st.GetName() << " da dang ky thanh cong khoa hoc " << cs.GetName() << "\n";
		// them sinh vien vao khoa hoc
		cs.GetRoster()->AddStudent(st.GetName());
	}
	else
	{
		return false;
	}

	return true;
}