#pragma once
#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

#include "movie.h"
#include "myvector.h"

#include <fstream>

class MovieManager
{
public:
	void Input();
	void Output();

	void WriteToFile();
	void ReadFromFile();

	void AddMovie();
	void RemoveByProducer(const char* producer);
private:
	MyVector<Movie*> m_MovieList;

	void Enqueue(Movie* mv);
	int FindPos(int rank, int ID);
};

#endif // MOVIE_MANAGER_H
