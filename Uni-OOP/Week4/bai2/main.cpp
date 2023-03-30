#include "congty.h"

int main()
{
	bool isInMenu = true;
	CongTy ct;
	while (isInMenu)
	{
		int choice = 0;

		std::cout << "Menu: \n";
		std::cout << "1. Nhap danh sach sinh vien \n";
		std::cout << "2. Xuat danh sach sinh vien \n";
		std::cout << "3. Tinh tong tien luong cac nhan vien \n";
		std::cout << "4. Tim nhan vien co luong cao nhat \n";
		std::cout << "5. Tinh luong trung binh cong ty \n";
		std::cout << "6. Tim nhan vien theo ma so \n";
		std::cout << "7. Tim nhan vien theo ten \n";
		std::cout << "8. So nhan vien sinh trong thang 5 \n";
		std::cout << "9. Them mot nhan vien vao danh sach \n";
		std::cout << "10. Xoa mot nhan vien khoi danh sach \n";
		std::cout << "11. Ghi cac nhan vien duoi luong trung binh vao file emp_LowerAvgSalary.dat \n";
		std::cout << "Moi ban chon chuc nang (chon 0 de thoat): ";
		std::cin >> choice;

		switch (choice)
		{
		case(1):
			ct.Input();
			break;

		case(2):
			ct.Output();
			break;

		case(3):
		{
			float salary = ct.GetSalary();
			std::cout << "Tong luong cua nhan vien la: " << salary << "\n";
			break;
		}

		case(4):
			ct.FindHighestSalary();
			break;

		case(5):
		{
			float avg = ct.GetAvgSalary();
			std::cout << "Luong trung binh cua cong ty la: " << avg << "\n";
			break;
		}

		case(6):
		{
			std::string maSo;
			std::cout << "Moi ban nhap ma so sinh vien muon tim: ";
			std::cin.ignore();
			getline(std::cin, maSo);

			ct.FindID(maSo);

			maSo.clear();
			break;
		}

		case(7):
		{
			std::string ten;
			std::cout << "Moi ban nhap ten nhan vien muon tim: ";
			std::cin.ignore();
			getline(std::cin, ten);

			ct.FindName(ten);

			ten.clear();
			break;
		}

		case(8):
			ct.FindMonth("5");
			break;

		case(9):
			ct.AddNV();
			break;

		case(10):
			ct.RemoveNV();
			break;

		case(11):
			ct.WriteBelowAvg();
			break;

		default:
			isInMenu = false;
			break;
		}
	}

	return 0;
}