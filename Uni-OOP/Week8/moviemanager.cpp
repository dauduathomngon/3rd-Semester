#include "moviemanager.h"

void MovieManager::Input()
{
	int size = 0;
	std::cout << "Input number of movies: ";
	std::cin >> size;
	std::cin.ignore();

	m_MovieList.Reserve(size);

	if (m_MovieList.Size() != 0)
	{
		m_MovieList.Clear();
	}

	for (int i = 0; i < size; i++)
	{
		Movie* newMovie = new Movie();
		newMovie->Input();

		Enqueue(newMovie);
	}
}

void MovieManager::Output()
{
	if (m_MovieList.Capacity() == 0)
	{
		std::cout << "Movie list is empty, please input movie list \n";
		return;
	}

	for (int i = 0; i < m_MovieList.Size(); i++)
	{
		m_MovieList[i]->Output();
	}
}

void MovieManager::WriteToFile()
{
	std::ofstream writeFile;
	writeFile.open("ds_phim.dat", std::ios_base::trunc | 
	std::ios_base::out);

	int size = m_MovieList.Size();
	writeFile.write((char*)&size, sizeof(size));
	for (int i = 0; i < size; i++)
	{
		writeFile.write((char*)m_MovieList[i], sizeof(*m_MovieList[i]));
	}
}

void MovieManager::ReadFromFile()
{
	std::ifstream readFile;
	readFile.open("ds_phim.dat", std::ios_base::in);
	
	int size = 0;
	readFile.read((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
	{
		readFile.read((char*)m_MovieList[i], sizeof(*m_MovieList[i]));
	}
}

void MovieManager::AddMovie()
{
	if (m_MovieList.Capacity() == 0)
	{
		std::cout << "Movie list is empty, please input movie list \n";
		return;
	}

 	Movie* newMovie = new Movie();
	newMovie->Input();

	// add movie with priority
	Enqueue(newMovie);

	// rewrite file
	WriteToFile();
}

void MovieManager::RemoveByProducer(const char* producer)
{
	if (m_MovieList.Capacity() == 0)
	{
		std::cout << "Movie list is empty, please input movie list \n";
		return;
	}

	for (int i = 0; i < m_MovieList.Size(); i++)
	{
		if (strcmp(m_MovieList[i]->GetProducer(), producer) == 0)
		{
			// Remove Movie and preserve order
			m_MovieList.Remove(i);
		}
	}

	// update file
	WriteToFile();
}

void MovieManager::Enqueue(Movie* mv)
{
	int pos = FindPos(mv->GetRank(), std::atoi(mv->GetID()));

	m_MovieList.Push(mv);
	int size = m_MovieList.Size();

	for (int i = size - 1; i > pos; i--)
	{
		std::swap(m_MovieList[i], m_MovieList[i - 1]);
	}
}

int MovieManager::FindPos(int rank, int ID)
{
	int size = m_MovieList.Size();
	for (int i = 0; i < size; i++)
	{
		int cRank = m_MovieList[i]->GetRank();
		int cID = std::atoi(m_MovieList[i]->GetID());

		if (rank == cRank)
		{
			if (cID < ID)
			{
				return i;
			}
			else
			{
				return i + 1;
			}
		}
		
		if (rank < cRank)
		{
			return i;
		}
	}

	return 0;
}
