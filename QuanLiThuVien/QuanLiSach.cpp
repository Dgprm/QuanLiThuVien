#include"QuanLiSach.h"
/*
Them sach vao thu vien
Nhan vao : char TenSach[100][20], char TacGia[100][20], char NSB[100][20], char TheLoai[100][20], int GiaSach[100], int SoQuyenSach[100], int NamXuatBan[100],int &k, int ISBN[100], char ten[100][20]
Xuat ra : Luu vao bo nho
*/
void LuuVaoTepTin(ThongTinSach tt)
{
	FILE*DanhSachQuyenSach = fopen("DANHSACHQUYENSACH.TXT", "a");
	fprintf(DanhSachQuyenSach, "%s\n", tt.TenSach);
	fprintf(DanhSachQuyenSach, "%d\n", tt.ISBN);
	fprintf(DanhSachQuyenSach, "%s\n", tt.TacGia);
	fprintf(DanhSachQuyenSach, "%s\n", tt.NSB);
	fprintf(DanhSachQuyenSach, "%d\n", tt.NamXuatBan);
	fprintf(DanhSachQuyenSach, "%s\n", tt.TheLoai);
	fprintf(DanhSachQuyenSach, "%d\n", tt.SoQuyenSach);
	fprintf(DanhSachQuyenSach, "%d\n", tt.GiaSach);
	fclose(DanhSachQuyenSach);
}
void NhapThongTinSach(ThongTinSach &tt)
{
	char ten[2];
		gets_s(ten);
		printf("Nhap vao ten sach thu  : ");
		gets_s(tt.TenSach);
		printf("Nhap vao tac gia sach : ");
		gets_s(tt.TacGia);
		printf("Nhap vao the loai sach : ");
		gets_s(tt.TheLoai);
		printf("Nhap vao nha xuat ban sach  : ");
		gets_s(tt.NSB);
		fflush(stdin);
		printf("Nhap vao nam xuat ban sach  : ");
		scanf("%d", &tt.NamXuatBan);
		printf("Nhap vao gia sach  : ");
		scanf("%d", &tt.GiaSach);
		printf("Nhap vao so quyen sach  : ");
		scanf("%d", &tt.SoQuyenSach);
		printf("Nhap vao ISBN sach  : ");
		scanf("%d", &tt.ISBN);
		system("cls");
}
void NhapDanhSachSach(DanhSachSach &dss)
{
	int n;
	printf("Nhap vao so luong quyen sach : = \n");
	scanf("%d", &n);
	for (int i = 0; i <n; i++)
	{
		NhapThongTinSach(dss.MangChuaSach[i]);
		LuuVaoTepTin(dss.MangChuaSach[i]);
		dss.n++;
	}
}
/*
Xuat thong tin sach
*/
void XuatThongTinSach(ThongTinSach tt)
{
			printf("Ten sach : %s\n", tt.TenSach);
			printf("Tac gia : %s\n", tt.TacGia);
			printf("The Loai : %s\n", tt.TheLoai);
			printf("Nha xuat ban : %s\n", tt.NSB);
			printf("Nam san xuat : %d\n", tt.NamXuatBan);
			printf("Gia sach  : %d VND\n", tt.GiaSach);
			printf("So quyen sach : %d\n", tt.SoQuyenSach);
			printf("Ma ISBN  : %d\n", tt.ISBN);
}
void XuatDanhSachSach(DanhSachSach dss)
{
	for (int i = 0; i < dss.n; i++)
	{
		printf("-------------Thong tin quyen sach thu %d------------\n", i+1);
		XuatThongTinSach(dss.MangChuaSach[i]);
	}
	getch();
}
/*
Kiem tra ma so sach
*/
int KiemTraMaSoSach(DanhSachSach dss)
{
	int q, Check = -1;
	printf("Nhap vao ma so ISBN : ");
	scanf("%d", &q);
	for (int i = 0; i < dss.n; i++)
	{
		if (dss.MangChuaSach[i].ISBN == q)
		{
			Check = i;
			break;
		}
	}
	return Check;
}
// Tim kiem sach theo ho ten
int TimKiemSachTheoTen(DanhSachSach dss)
{
	int Check = -1;
	char ten[1];
	char HoTen1[100];
	gets_s(ten);
	printf("Nhap ho ten can tim : ");
	gets_s(HoTen1);
	for (int i = 0; i < dss.n; i++)
	{
		if (stricmp(dss.MangChuaSach[i].TenSach, HoTen1) == 0)
		{
			Check = i;
			break;
		}
	}
	return Check;
}
/* Thong ke sach theo the loai
nhan vao : theloai[100][20], k
xuat ra: the loai
*/


void DocNhieuSach(DanhSachSach &dss)
{
	int Check = 1;
	FILE *FileIn = fopen("DANHSACHQUYENSACH.TXT", "r");
	if (!FileIn)
	{
		Check = 0;
	}
	if (Check == 1)
	{
		int i = 0;
		while (feof(FileIn) == NULL)
		{
			fscanf(FileIn, "%[^\n]\n", &dss.MangChuaSach[i].TenSach);
			fscanf(FileIn, "%d\n", &dss.MangChuaSach[i].ISBN);
			fscanf(FileIn, "%[^\n]\n", &dss.MangChuaSach[i].TacGia);
			fscanf(FileIn, "%[^\n]\n", &dss.MangChuaSach[i].NSB);
			fscanf(FileIn, "%d\n", &dss.MangChuaSach[i].NamXuatBan);
			fscanf(FileIn, "%[^\n]\n", &dss.MangChuaSach[i].TheLoai);
			fscanf(FileIn, "%d\n", &dss.MangChuaSach[i].SoQuyenSach);
			fscanf(FileIn, "%d\n", &dss.MangChuaSach[i].GiaSach);
			i++;
		}
		dss.n = i;
		//}
		fclose(FileIn);
	}
}
void LuuChinhSua(DanhSachSach &dss)
{

	FILE*FileOut = fopen("DANHSACHQUYENSACH.TXT", "w");
	fclose(FileOut);
	for (int i = 0; i <dss.n; i++)
	{
		LuuVaoTepTin(dss.MangChuaSach[i]);
	}
	printf("Chinh sua Thanh cong\n");
	getch();
}
void ThongKeSachTheoTheLoai(DanhSachSach dss)
{
	int DemTheLoai[100], Dem = 1, DemSoLan = 0, Check = 0, z = 0, u = 0;
	char BoTenTrung[100][20];
	for (int i = 0; i < dss.n; i++)
	{
		DemSoLan = 0;
		for (int l = 0; l < dss.n; l++)
		{
			Check = 0;
			if (stricmp(dss.MangChuaSach[i].TheLoai, BoTenTrung[l]) == 0)
			{
				Check = 1;
				break;

			}
		}
		if (Check == 0)
		{
			for (int d = 0; d < dss.n; d++)
			{
				if (stricmp(dss.MangChuaSach[i].TheLoai, dss.MangChuaSach[i].TheLoai) == 0)
				{
					DemSoLan++;
					if (DemSoLan == 1)
					{
						strcpy(BoTenTrung[z], dss.MangChuaSach[i].TheLoai);
						z++;
					}
				}
			}
			DemTheLoai[u] = DemSoLan;
			u++;
		}
	}


	system("cls");
	printf("\n====THONG KE TRUYEN THEO THE LOAI====\n");
	for (int i = 0; i < u; i++)
	{
		int q = 0;
		for (int j = 0; j < dss.n; j++)
		{
			if (stricmp(dss.MangChuaSach[j].TheLoai, BoTenTrung[i])== 0)
			{
				q = q + (dss.MangChuaSach[j].SoQuyenSach);
			}
		}
		printf(" The Loai %s : %d quyen sach\n", BoTenTrung[i],q);
	}
	getch();
}