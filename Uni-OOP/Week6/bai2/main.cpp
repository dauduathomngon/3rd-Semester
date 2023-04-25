#include "nvcongnhat.h"
#include "nvsanxuat.h"

int main()
{
	NhanVien* nv1 = new NVCongNhat();
	nv1->SetValue(0, "212");
	nv1->SetValue(1, "Nguyen");
	nv1->SetValue(2, "0");
	nv1->SetValue(3, "fdfd");
	nv1->SetValue(4, "18/07/2003");
	nv1->SetValue(5, "24");
	nv1->Output();

	NhanVien* nv2 = new NVSanXuat();

	NhanVien* nv3 = nv1->Clone();
	nv3->Output();

	delete nv1;
	delete nv2;
	delete nv3;
	return 0;
}