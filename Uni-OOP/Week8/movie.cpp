#include "movie.h"

Movie::Movie()
: m_ID(nullptr)
, m_Name(nullptr)
, m_Genre(nullptr)
, m_Producer(nullptr)
, m_Year(0)
, m_Rank(0)
{
}

Movie::~Movie()
{
	delete[] m_ID;
	delete[] m_Name;
	delete[] m_Genre;
	delete[] m_Producer;
}

void Movie::Input()
{
	m_ID = new char[MAX_LEN]();
	std::cout << "Input movie ID (5 character or less): ";
	std::cin.getline(m_ID, MAX_LEN);

	m_Name = new char[MAX_LEN]();
	std::cout << "Input movie name: ";
	std::cin.getline(m_Name, MAX_LEN);

	m_Genre = new char[MAX_LEN]();
	std::cout << "Input movie genre: ";
	std::cin.getline(m_Genre, MAX_LEN);

	m_Producer = new char[MAX_LEN]();
	std::cout << "Input movie producer: ";
	std::cin.getline(m_Producer, MAX_LEN);

	std::cout << "Input movie release year: ";
	std::cin >> m_Year;

	std::cout << "Input movie rank: ";
	std::cin >> m_Rank;
	std::cin.ignore();
}

void Movie::Output()
{
	std::cout << "ID: " << m_ID << "\n";
	std::cout << "Name: " << m_Name << "\n";
	std::cout << "Genre: " << m_Genre << "\n";
	std::cout << "Producer: " << m_Producer << "\n";
	std::cout << "Year: " << m_Year << "\n";
	std::cout << "Rank: " << m_Rank << "\n";
}

char* Movie::GetProducer() const
{
	return m_Producer;
}

int Movie::GetRank() const
{
	return m_Rank;
}

char* Movie::GetID() const
{
	return m_ID;
}
