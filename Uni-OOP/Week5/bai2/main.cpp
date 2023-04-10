#include "manager.h"

void MenuPrompt()
{
	std::cout << "\n";
	std::cout << "Chao mung den voi chuong trinh dang ky khoa hoc cho sinh vien \n";
	std::cout << "Chuong trinh co cac chuc nang duoi day: \n";
	std::cout << "1. Doc danh sach khoa hoc (doc tu file courseInput.txt) \n";
	std::cout << "2. Dang ky khoa hoc cho sinh vien \n";
	std::cout << "3. Ghi danh sach sinh vien len file \n";
	std::cout << "4. Doc danh sach sinh vien tu file \n";
	std::cout << "5. Xuat danh sach sinh vien cua khoa hoc \n";
	std::cout << "6. Xuat danh sach khoa hoc cua sinh vien \n";
	std::cout << "0. Thoat chuong trinh \n";
}

void ContinuePrompt()
{
	std::cout << "Xin moi tiep tuc chon chuc nang \n";
}

int main()
{
	Manager myManager;
	bool isRunning = true;

	while (isRunning)
	{
		int choice = 0;

		MenuPrompt();
		std::cout << "Moi ban nhap so tuong ung de chon chuc nang: ";
		std::cin >> choice;

		switch (choice)
		{
		case(1):
		{
			std::cout << "\n";
			myManager.ReadCourseFromFile();
			std::cout << "Da doc xong danh sach khoa hoc \n";
			ContinuePrompt();
			break;
		}
		case(2):
		{
			std::cout << "\n";
			myManager.Register();
			ContinuePrompt();
			break;
		}
		case(3):
		{
			std::cout << "\n";
			myManager.WriteStudentToFile();
			ContinuePrompt();
			break;
		}
		case(4):
		{
			std::cout << "\n";
			myManager.ReadStudentFromFile();
			std::cout << "Da doc xong danh sach sinh vien \n";
			ContinuePrompt();
			break;
		}
		case(5):
		{
			std::cout << "\n";
			myManager.PrintStudentCourse();
			ContinuePrompt();
			break;
		}
		case(6):
		{
			std::cout << "\n";
			myManager.PrintStudentSchedule();
			ContinuePrompt();
			break;
		}
		default:
			isRunning = false;
			break;
		}
	}

	return 0;
}