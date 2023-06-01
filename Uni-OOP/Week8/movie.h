#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string.h>

const int MAX_LEN = 100;

class Movie
{
public:
	Movie();
	~Movie();

	void Input();
	void Output();

	char* GetProducer() const;
	int GetRank() const;
	char* GetID() const;

private:
	char* m_ID;
	char* m_Name;
	char* m_Genre;
	char* m_Producer;
	int m_Year;
	int m_Rank;
};

#endif // MOVIE_H
