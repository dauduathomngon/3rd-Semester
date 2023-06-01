#pragma once
#ifndef INPUT_EXCEPTION_H
#define INPUT_EXCEPTION_H

#include <exception>
#include <string>
#include <iostream>

class InputException : public std::exception
{
public:
	InputException()
	: m_Msg("Error")
	{}

	InputException(const std::string& msg)
	: m_Msg(msg)
	{}

	virtual const char* what() const noexcept override
	{
		return m_Msg.c_str();
	}
private:
	std::string m_Msg;
};

#endif // INPUT_EXCEPTION_H
