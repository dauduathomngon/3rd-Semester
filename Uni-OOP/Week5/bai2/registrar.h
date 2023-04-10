#pragma once
#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "student.h"
#include "course.h"

class Registrar
{
public:
	Registrar();
	~Registrar();

	bool Enroll(Student& st, Course& cs);
};

#endif // REGISTRAR_H