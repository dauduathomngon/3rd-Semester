#include "qlsinhvien.h"

void AsciiText()
{
	std::cout << R"(
   ___ _                               _        _       _                    
  / __\ |__  _   _  ___  _ __   __ _  | |_ _ __(_)_ __ | |__                 
 / /  | '_ \| | | |/ _ \| '_ \ / _` | | __| '__| | '_ \| '_ \                
/ /___| | | | |_| | (_) | | | | (_| | | |_| |  | | | | | | | |               
\____/|_| |_|\__,_|\___/|_| |_|\__, |  \__|_|  |_|_| |_|_| |_|               
                               |___/                                         
   ____                     _             _       _             _            
  /___ \_   _  __ _ _ __   | |_   _   ___(_)_ __ | |__   __   _(_) ___ _ __  
 //  / / | | |/ _` | '_ \  | | | | | / __| | '_ \| '_ \  \ \ / / |/ _ \ '_ \ 
/ \_/ /| |_| | (_| | | | | | | |_| | \__ \ | | | | | | |  \ V /| |  __/ | | |
\___,_\ \__,_|\__,_|_| |_| |_|\__, | |___/_|_| |_|_| |_|   \_/ |_|\___|_| |_|
                              |___/                                          
)";
}

int main()
{
	AsciiText();

	// main menu
	std::cout << "\n"
			  << "Chao mung cac ban da den voi chuong trinh quan ly sinh vien <3 \n";

	std::cout << "\n"
			  << "Duoi day la cac chuc nang chinh cua chuong trinh: \n \n";

	QL_SinhVien ctrinhQL;

	bool isRunning = true;
	while (isRunning)
	{
		// display features
		std::cout << "1. Ghi danh sach sinh vien len output.txt \n";
		std::cout << "2. Doc danh sach sinh vien tu input.txt \n";
		std::cout << "3. Ghi danh sach cac sinh vien co diem duoi trung binh len output.txt \n";
		std::cout << "4. Them mot sinh vien moi vao danh sach va cap nhat lai output.txt \n";
		std::cout << "5. Xep loai cac sinh vien va in ra man hinh \n";
		std::cout << "6. Ghi danh sach sinh xep loai sinh vien len output.txt \n";
		std::cout << "7. Tim tat ca cac sinh vien co cung ngay sinh voi ngay hien tai \n";
		std::cout << "<-- Chon 0 de thoat --> \n";

		// user choice
		int choice = 0;
		std::cout << "Moi ban nhap chuc nang mong muon: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			ctrinhQL.WriteToFile();
			break;
		case 2:
			ctrinhQL.ReadFromFile();
			break;
		case 3:
			ctrinhQL.WriteBelowAvg();
			break;
		case 4:
			ctrinhQL.WriteNewSV();
			break;
		case 5:
			ctrinhQL.RankSV(true, false);
			break;
		case 6:
			ctrinhQL.RankSV(false, true);
			break;
		case 7:
			ctrinhQL.WriteDate();
			break;
		default:
			isRunning = false;
			break;
		}
	}

	return 0;
}
