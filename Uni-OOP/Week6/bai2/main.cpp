#include "congty.h"

void AsciiText()
{
	std::cout << R"(
   ___ _                               _        _       _                           
  / __\ |__  _   _  ___  _ __   __ _  | |_ _ __(_)_ __ | |__                        
 / /  | '_ \| | | |/ _ \| '_ \ / _` | | __| '__| | '_ \| '_ \                       
/ /___| | | | |_| | (_) | | | | (_| | | |_| |  | | | | | | | |                      
\____/|_| |_|\__,_|\___/|_| |_|\__, |  \__|_|  |_|_| |_|_| |_|                      
                               |___/                                                
   ____                     _             __ _                         _            
  /___ \_   _  __ _ _ __   | |_   _    /\ \ \ |__   __ _ _ __   /\   /(_) ___ _ __  
 //  / / | | |/ _` | '_ \  | | | | |  /  \/ / '_ \ / _` | '_ \  \ \ / / |/ _ \ '_ \ 
/ \_/ /| |_| | (_| | | | | | | |_| | / /\  /| | | | (_| | | | |  \ V /| |  __/ | | |
\___,_\ \__,_|\__,_|_| |_| |_|\__, | \_\ \/ |_| |_|\__,_|_| |_|   \_/ |_|\___|_| |_|
                              |___/                                                 
)";
}

int main()
{
	AsciiText();
	std::cout << "\n";

	std::cout << "Chao mung ban de voi chuong trinh quan ly nhan vien \n";
	std::cout << "Duoi day la cac chuc nang cua chuong trinh \n \n";

	CongTy ct;
	bool isRunning = true;

	while (isRunning)
	{
		// display features
		std::cout << "\n";
		std::cout << "1. Ghi danh sach nhan vien vao file ds_NhanVien.dat \n";
		std::cout << "2. Doc danh sach nhan vien tu file ds_NhanVien.dat (chua hoan thanh) \n";
		std::cout << "3. Xuat danh sach nhan vien ra man hinh \n";
		std::cout << "4. Tinh tong tien luong cac nhan vien \n";
		std::cout << "5. Tim nhan vien co luong cao nhat \n";
		std::cout << "6. Tinh luong trung binh cua cong ty \n";
		std::cout << "7. Nhap vao ID, tim nhan vien tuong ung \n";
		std::cout << "8. Nhap vao ten, tim nhan vien tuong ung \n";
		std::cout << "9. Tim cac nhan vien sinh trong thang 5 \n";
		std::cout << "10. Them nhan vien \n";
		std::cout << "11. Xoa nhan vien \n";
		std::cout << "12. Ghi cac nhan vien co luong duoi trung binh vao file emp_LowerAvgSalary.dat \n";
		std::cout << "13. Nhap nhan vien tu ban phim \n";

		// user choice
		int choice = 0;
		std::cout << "Moi ban nhap chuc nang (0 de thoat): ";
		std::cin >> choice;

		std::string value;

		switch (choice)
		{
		case(1):
		{
			std::cout << "\n";
			ct.WriteToFile();
			break;
		}
		case(2):
		{
			std::cout << "\n";
			ct.ReadFromFile();
			break;
		}
		case(3):
		{
			std::cout << "\n";
			ct.Output();
			break;
		}
		case(4):
		{
			std::cout << "\n";
			std::cout << "Tong tien luong cua cong ty la: " << ct.GetTotalSalary() << "\n";
			break;
		}
		case(5):
		{
			std::cout << "\n";
			ct.FindHighestSalary();
			break;
		}
		case(6):
		{
			std::cout << "\n";
			std::cout << "Luong trung binh cua cong ty la: " << ct.GetAvgSalary() << "\n";
			break;
		}
		case(7):
		{
			std::cout << "\n";
			std::cout << "Moi ban nhap ID muon tim: ";
			getline(std::cin, value);
			ct.FindID(value.c_str());
			break;
		}
		case(8):
		{
			std::cout << "\n";
			std::cout << "Moi ban nhap ten muon tim: ";
			getline(std::cin, value);
			ct.FindName(value.c_str());
			break;
		}
		case(9):
		{
			std::cout << "\n";
			ct.FindMonth(5);
			break;
		}
		case(10):
		{
			std::cout << "\n";
			ct.AddEmployee();
			break;
		}
		case(11):
		{
			std::cout << "\n";
			ct.RemoveEmployee();
			break;
		}
		case(12):
		{
			std::cout << "\n";
			ct.WriteBelowAvg();
			break;
		}
		case(13):
		{
			std::cout << "\n";
			ct.Input();
			break;
		}
		default:
			isRunning = false;
			break;
		}
	}

	return 0;
}