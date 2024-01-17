#include "QuanLiDocGia.h"
/*
Nhap thong tin cua 1 doc gia
*/
void NhapThongTinDocGia(ThongTinDocGia & tt)
{
	char get[4];
	gets_s(get);
	printf("nhap ho ten doc gia la : ");
	gets_s(tt.HoTen);
	printf("Nhap gioi tinh doc gia la :  ");
	gets_s(tt.GioiTinh);
	printf("Nhap email  doc gia  la :  ");
	gets_s(tt.Email);
	printf("Nhap dia chi doc gia  la :  ");
	gets_s(tt.DiaChi);
	fflush(stdin);
	printf("-----NHAP THOI GIAN MUON THE-----\n");
	int q = KiemTraNgayThangNam(tt.NgaySinh, tt.ThangSinh, tt.NamSinh);
	printf("Nhap so CMND cua doc gia : ");
	scanf("%d", &tt.Cmnd);
	printf("Nhap so MSDG cua doc gia : ");
	scanf("%d", &tt.MaDocGia);
	printf("-----NHAP NGAY THANG NAM MUON THE-----\n");
	int q2 = KiemTraNgayThangNam(tt.NgayMuon, tt.ThangMuon, tt.NamMuon);
	// Xac dinh ngay het cua the sau 4 nam
	tt.NgayHet = tt.NgayMuon;
	tt.ThangHet = tt.ThangMuon;
	tt.NamHet = tt.NamMuon + 4;
}
int KiemTraNgayThangNam(int &CheckNgay, int &CheckThang, int &CheckNam)
{
	int Ngay, Thang, Nam, Check = 0;
	do {
		Check = 0;
		printf("Nhap ngay  : ");
		scanf("%d", &Ngay);
		printf("Nhap thang  : ");
		scanf("%d", &Thang);
		printf("Nhap nam  : ");
		scanf("%d", &Nam);
		if (Ngay > 31 || Ngay< 0 || Thang < 0 || Thang >12 || Nam<0)
		{
			Check = -1;
		}
		else
		{// 1 3 5 7 8 10 12
			if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)
			{
				CheckNam = Nam;
				if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
				{
					CheckNgay = Ngay;
					CheckThang = Thang;
				}
				else if ((Thang == 4 || Thang == 6 || Thang == 5 || Thang == 7 || Thang == 9 || Thang == 11))
				{
					if (Ngay < 31)
					{
						CheckNgay = Ngay;
						CheckThang = Thang;
					}
					else
					{
						Check = -1;
					}
				}
				else if (Thang == 2)
				{
					if (Ngay < 30)
					{
						CheckNgay = Ngay;
						CheckThang = Thang;
					}
					else {
						Check = -1;
					}
				}

			}
			else
			{
				CheckNam = Nam;
				if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
				{
					CheckNgay = Ngay;
					CheckThang = Thang;
				}
				else if ((Thang == 4 || Thang == 6 || Thang == 5 || Thang == 7 || Thang == 9 || Thang == 11))
				{
					if (Ngay < 31)
					{
						CheckNgay = Ngay;
						CheckThang = Thang;
					}
					else {
						Check = -1;
					}
				}
				else if (Thang == 2 && Ngay < 29)
				{
					if (Ngay < 29)
					{
						CheckNgay = Ngay;
						CheckThang = Thang;
					}
					else {
						Check = -1;
					}
				}

			}
		}
		if (Check == -1)
		{
			printf("Kiem tra lai ! Xin moi nhap lai !!!\n");
			getch();
			system("cls");
		}
	} while (Check == -1);
	return 0;
}
void NhapDanhSachDocGia(DanhSachDocGia & DanhSach)
{
	int n;
	printf("Nhap so luong doc gia can them vao = ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		DanhSach.n++;
		printf("Thong tin doc gia thu %d\n", i + 1);
		NhapThongTinDocGia(DanhSach.MangChuaDocGia[i]);
		LuuVaoTepTin(DanhSach.MangChuaDocGia[i]);
	
	}
}
void HamXuat(ThongTinDocGia & tt)
{
		
		printf("Ma so doc gia : %d\n", tt.MaDocGia);
		printf("So CMND : %d\n", tt.Cmnd);
		printf("Ho ten : %s\n", tt.HoTen);
		printf("Gioi tinh : %s\n", tt.GioiTinh);
		printf("Email : %s\n", tt.Email);
		printf("Dia chi : %s\n", tt.DiaChi);
		printf("Ngay thang nam sinh : %d - %d - %d\n", tt.NgaySinh, tt.ThangSinh, tt.NamSinh);
		printf("Ngay thang nam sinh lap the : %d - %d - %d\n", tt.NgayMuon, tt.ThangMuon, tt.NamMuon);
		printf("Ngay thang nam sinh het han : %d - %d - %d\n", tt.NgayHet, tt.ThangHet, tt.NamHet);
		
}
void XuatDanhSach(DanhSachDocGia DanhSach)
{
	int Check = 0;
	FILE *FileIn = fopen("DANHSACHDOCGIA.txt", "r");
		for (int i = 0; i < DanhSach.n; i++)
		{
			printf("----------Thong tin doc gia thu %d-------------\n", i + 1);
			HamXuat(DanhSach.MangChuaDocGia[i]);
		}
		fclose(FileIn);
	}
void LuuVaoTepTin(ThongTinDocGia tt)
{
	FILE*DanhSachDocGia = fopen("DANHSACHDOCGIA.TXT", "a");
	fprintf(DanhSachDocGia,"%d\n", tt.MaDocGia);
	fprintf(DanhSachDocGia,"%s\n", tt.HoTen);
	fprintf(DanhSachDocGia,"%s\n", tt.GioiTinh);
	fprintf(DanhSachDocGia,"%s\n", tt.Email);
	fprintf(DanhSachDocGia,"%s\n", tt.DiaChi);
	fprintf(DanhSachDocGia,"%d\n", tt.Cmnd);
	fprintf(DanhSachDocGia,"%d-%d-%d\n", tt.NgaySinh, tt.ThangSinh, tt.NamSinh);
	fprintf(DanhSachDocGia,"%d-%d-%d\n", tt.NgayMuon, tt.ThangMuon, tt.NamMuon);
	fprintf(DanhSachDocGia,"%d-%d-%d\n", tt.NgayHet, tt.ThangHet, tt.NamHet);
	fclose(DanhSachDocGia);
}
void DemLuonngDocGia(DanhSachDocGia &DanhSach)
{
	int Check = 0;
	char s[] = "Ho ten :";
	char b[9];
	DanhSach.n = 0;
	FILE *FileIn = fopen("DANHSACHDOCGIA.TXT", "r");
	if (!FileIn)
	{
		Check = 1;
	}
	if (Check == 0)
	{
		while (!feof(FileIn))
		{
			fgets(b, 9, FileIn);
			if (strcmp(s, b) == 0)
			{
				DanhSach.n++;
			}
		}
		fclose(FileIn);
	}

}
void DocNhieuDocgia(DanhSachDocGia &DanhSach)
{
	 DemLuonngDocGia(DanhSach);

	 int Check = 1;
		FILE *FileIn = fopen("DANHSACHDOCGIA.TXT", "r");
		if (!FileIn)
		{
			Check = 0;
		}
		if (Check==1)
		{
			//while (!feof(FileIn))
		//for (int i = 0; i < DanhSach.n; i++)
		//{
			int i = 0;
			while (feof(FileIn)== NULL)
			{
				fscanf(FileIn, "%d\n", &DanhSach.MangChuaDocGia[i].MaDocGia);
				fscanf(FileIn, "%[^\n]\n", &DanhSach.MangChuaDocGia[i].HoTen);
				fscanf(FileIn, "%[^\n]\n", &DanhSach.MangChuaDocGia[i].GioiTinh);
				fscanf(FileIn, "%[^\n]\n", &DanhSach.MangChuaDocGia[i].Email);
				fscanf(FileIn, "%[^\n]\n", &DanhSach.MangChuaDocGia[i].DiaChi);
				fscanf(FileIn, "%d\n", &DanhSach.MangChuaDocGia[i].Cmnd);
				fscanf(FileIn, "%d-%d-%d\n", &DanhSach.MangChuaDocGia[i].NgaySinh, &DanhSach.MangChuaDocGia[i].ThangSinh, &DanhSach.MangChuaDocGia[i].NamSinh);
				fscanf(FileIn, "%d-%d-%d\n", &DanhSach.MangChuaDocGia[i].NgayMuon, &DanhSach.MangChuaDocGia[i].ThangMuon, &DanhSach.MangChuaDocGia[i].NamMuon);
				fscanf(FileIn, "%d-%d-%d\n", &DanhSach.MangChuaDocGia[i].NgayHet, &DanhSach.MangChuaDocGia[i].ThangHet, &DanhSach.MangChuaDocGia[i].NamHet);
				i++;
			}
			DanhSach.n = i;
			//}
		fclose(FileIn);
	}
	

}
int KiemTraMaSo(DanhSachDocGia DanhSach)
{
	int Check = -1;
	int q = HamNhapMaSo();
	for (int i = 0; i < DanhSach.n; i++)
	{
		if (DanhSach.MangChuaDocGia[i].MaDocGia == q)
		{
			Check = i;
			break;
		}
	}
	return Check;
}
int HamNhapMaSo()
{
	int q;
	printf("Nhap Ma so can sua : ");
	scanf("%d", &q);
	return q;
}
int HamNhapCmnd()
{
	int q = -1;
	printf("Nhap so CMND can tim : ");
	scanf("%d", &q);
	return q;
}
int TimKiemBangCMND ( DanhSachDocGia DanhSach)
{
	system("cls");
	int Check = -1;
	int q = HamNhapCmnd();
	for (int i = 0; i < DanhSach.n; i++)
	{
		if (DanhSach.MangChuaDocGia[i].Cmnd == q)
		{
			Check = i;
			break;
		}
	}
	return Check;
}

void XoaDocGia(DanhSachDocGia &DanhSach)
{
	DanhSach.n = DanhSach.n - 1;
}
/*
Tim kiem doc gia theo ho ten
nhan vao: Ho ten doc gia can tim
xuat ra : Thong tin cua doc gia
*/
int TimKiemDocGiaTheoHoTen(DanhSachDocGia DanhSach)
{
	system("cls");
	int Check = -1;

	char HoTen1[100];
	char get[2];
	gets_s(get);
	printf("Nhap ho ten can tim : ");
	gets_s(HoTen1);
	for (int i = 0; i < DanhSach.n; i++)
	{
		if (stricmp(DanhSach.MangChuaDocGia[i].HoTen, HoTen1) == 0)
		{
			Check = i;
			break;
		}
	}
	return Check;
}
void ThongKeDocGiaTheoGioiTinh(DanhSachDocGia DanhSach)
{
	int DemTheLoai[100], Dem = 1, DemSoLan = 0, Check = 0, z = 0, u = 0;
	char BoTenTrung[100][20];
	for (int i = 0; i < DanhSach.n; i++)
	{
		DemSoLan = 0;
		for (int l = 0; l < DanhSach.n; l++)
		{
			Check = 0;
			if (stricmp(DanhSach.MangChuaDocGia[i].GioiTinh, BoTenTrung[l]) == 0)
			{
				Check = 1;
				break;

			}
		}
		if (Check == 0)
		{
			for (int d = 0; d < DanhSach.n; d++)
			{
				if (stricmp(DanhSach.MangChuaDocGia[i].GioiTinh, DanhSach.MangChuaDocGia[d].GioiTinh) == 0)
				{
					DemSoLan++;
					if (DemSoLan == 1)
					{
						strcpy(BoTenTrung[z], DanhSach.MangChuaDocGia[i].GioiTinh);
						z++;
					}
				}
			}
			DemTheLoai[u] = DemSoLan;
			u++;
		}
	}


	system("cls");
	printf("\n==== THONG KE DOC GIA THEO GIOI TINH ====\n");
	for (int i = 0; i < u; i++)
	{
		printf(" Gioi Tinh %s : %d doc gia\n", BoTenTrung[i], DemTheLoai[i]);
	}
	getch();
}