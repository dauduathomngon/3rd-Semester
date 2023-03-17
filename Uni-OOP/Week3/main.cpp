#include "qlsinhvien.h"

void MainMenu();

int main()
{
	QL_SinhVien ctrinhQL;
	ctrinhQL.ReadFromFile();
	ctrinhQL.WriteToFile();
	ctrinhQL.WriteNewSV();
	return 0;
}

void MainMenu()
{

}