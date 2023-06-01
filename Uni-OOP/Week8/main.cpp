#include "moviemanager.h"

int main()
{
	MovieManager mm;

	bool isRunning = true;
	while (isRunning)
	{
		std::cout << "Menu: \n"
				  << "1. Add Movie to List \n"
				  << "2. Write movie list to file ds_phim.dat \n"
				  << "3. Read movie list from file ds_phim.dat \n"
				  << "4. Remove all movie produced by HBO \n"
				  << "5. Input movie list \n"
				  << "6. Output movie list \n"
				  << "0. Exit program \n"
				  << "Which function do you want: ";

		int choice = 0;
		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
		case(1):
		{
			mm.AddMovie();
			break;
		}
		case(2):
		{
			mm.WriteToFile();
			break;
		}
		case(3):
		{
			mm.ReadFromFile();
			break;
		}
		case(4):
		{
			mm.RemoveByProducer("HBO");
			break;
		}
		case(5):
		{
			mm.Input();
			break;
		}
		case(6):
		{
			mm.Output();
			break;
		}
		default:
			isRunning = false;
			break;
		}
	}

	return 0;
}