#include "QuanLiPhieuTraMuonSach.h"
int CheckMaSo(DanhSachDocGia DanhSach)
{
	int d, Check = -1;
	printf("Nhap ma doc gia can muon : ");
	scanf("%d", &d);
	for (int i = 0; i < DanhSach.n; i++)
	{
		if (d == DanhSach.MangChuaDocGia[i].MaDocGia)
		{
		Check = DanhSach.MangChuaDocGia[i].MaDocGia;
			break;
		}
	}
	return Check;
}
int CheckMaSoSach(DanhSachSach dss)
{
	int n,Check=-1;
	printf("Nhap vao ma ISBN con muon : ");
	scanf("%d", &n);
	for (int i = 0; i < dss.n; i++)
	{
		if (n == dss.MangChuaSach[i].ISBN)
		{
			
			Check = dss.MangChuaSach[i].ISBN;
			break;
		}
	}
	return Check;
}
void NhapPhieuMuonSach(PhieuMuonSach &pms)
{
		int q = KiemTraNgayThangNam(pms.NgayMuon, pms.ThangMuon, pms.NamMuon);
		q = ThoiGianTraDuKien(pms);

}
int ThoiGianTraDuKien(PhieuMuonSach &pms)
{
	// Thang muon la thang le -12;
	if ((pms.ThangMuon == 1 || pms.ThangMuon == 3 || pms.ThangMuon == 5 || pms.ThangMuon == 7 || pms.ThangMuon == 8 || pms.ThangMuon == 10))
	{
		if (pms.NgayMuon < 25)
		{ 
			pms.NgayTraDuKien = pms.NgayMuon + 7;
			pms.ThangTraDuKien = pms.ThangMuon;
			pms.NamTraDuKien = pms.NamMuon;

		}
		else {
			pms.NgayTraDuKien = (pms.NgayMuon + 7) - 31;
			pms.ThangTraDuKien = pms.ThangMuon + 1;
			pms.NamTraDuKien = pms.NamMuon;

		}
	}
	// thang muon la thang chan tru thang 2
	else if ((pms.ThangMuon == 4 || pms.ThangMuon == 3 || pms.ThangMuon == 6 || pms.ThangMuon == 9 || pms.ThangMuon == 11))
	{
		if (pms.NgayMuon < 24)
		{
			pms.NgayTraDuKien = pms.NgayMuon + 7;
			pms.ThangTraDuKien = pms.ThangMuon;
			pms.NamTraDuKien = pms.NamMuon;
		}
		else {
			pms.NgayTraDuKien = (pms.NgayMuon + 7) - 30;
			pms.ThangTraDuKien = pms.ThangMuon + 1;
			pms.NamTraDuKien = pms.NamMuon;
		}
	}
	// Thang muon la thang 12
	else if (pms.ThangMuon == 12)
	{
		if (pms.NgayMuon < 25)
		{
			pms.NgayTraDuKien = pms.NgayMuon + 7;
			pms.ThangTraDuKien = pms.ThangMuon;
			pms.NamTraDuKien = pms.NamMuon;
		}
		else
		{
			pms.NgayTraDuKien = (pms.NgayMuon + 7) - 31;
			pms.ThangTraDuKien = 1;
			pms.NamTraDuKien = pms.NamMuon + 1;
		}
	}
	// thang muon la thang 2
	else if (pms.ThangMuon == 2)
	{
		if (pms.NamMuon % 4 == 0)
		{
			if (pms.NgayMuon < 23)
			{
				pms.NgayTraDuKien = pms.NgayMuon + 7;
				pms.ThangTraDuKien = pms.ThangMuon;
				pms.NamTraDuKien = pms.NamMuon;
			}
			else
			{
				pms.NgayTraDuKien = (pms.NgayMuon + 7) - 29;
				pms.ThangTraDuKien = pms.ThangMuon + 1;
				pms.NamTraDuKien = pms.NamMuon;
			}
		}
		else
		{
			if (pms.NgayMuon < 22)
			{
				pms.NgayTraDuKien = pms.NgayMuon + 7;
				pms.ThangTraDuKien = pms.ThangMuon;
				pms.NamTraDuKien = pms.NamMuon;
			}
			else
			{
				pms.NgayTraDuKien = (pms.NgayMuon + 7) - 28;
				pms.ThangTraDuKien = pms.ThangMuon + 1;
				pms.NamTraDuKien = pms.NamMuon;
			}
		}
	}
	return -1;
}
void LuuVaoTepTin(PhieuMuonSach pms)
{
	FILE *FileIn = fopen("PHIEUMUONSACH.TXT", "a");
	fprintf(FileIn, "%d\n", pms.MDG);
	fprintf(FileIn, "%d\n", pms.MS);
	fprintf(FileIn, "%d/%d/%d\n", pms.NgayMuon, pms.ThangMuon, pms.NamMuon);
	fprintf(FileIn, "%d/%d/%d\n", pms.NgayTraDuKien, pms.ThangTraDuKien, pms.NamTraDuKien);
	fclose(FileIn);
}
void XuatPhieuMuonSach(PhieuMuonSach pms)
{
	printf("\nMa doc gia muon sach : %d\n", pms.MDG);
	printf("Ma ISBN muon sach : %d\n", pms.MS);
	printf("Thoi gian muon sach : %d/%d/%d\n", pms.NgayMuon, pms.ThangMuon, pms.NamMuon);
	printf("Thoi gian tra du kien : %d/%d/%d\n", pms.NgayTraDuKien, pms.ThangTraDuKien, pms.NamTraDuKien);
}
int NhapDanhSachPhieuMuonSach(DanhSachPhieuMuonSach &dspms,DanhSachSach dss,DanhSachDocGia DanhSach)
{
	int n,Check=0;
	printf("Nhap vao so luong phieu muon sach : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int q0 = CheckMaSo(DanhSach);
		int q = CheckMaSoSach(dss);
			if (q0!=-1 && q!=-1)
			{
				dspms.MangChuaPhieuMuonSach[i].MDG = q0;
				dspms.MangChuaPhieuMuonSach[i].MS = q;
				NhapPhieuMuonSach(dspms.MangChuaPhieuMuonSach[i]);
				LuuVaoTepTin(dspms.MangChuaPhieuMuonSach[i]);
				dspms.n++;
			}
			else
			{
				Check = 1;
				break;
			}
		}
	if (Check == 1)
	{
		return 1;
	}
	else if (Check==0)
	{
		return 0;
	}
	}
void XuatDanhSachPhieuMuonSach(DanhSachPhieuMuonSach dspms)
{
	for (int i = 0; i < dspms.n; i++)
	{
		printf("---------THONG TIN PHIEU MUON SACH THU %d------------", i + 1);
		XuatPhieuMuonSach(dspms.MangChuaPhieuMuonSach[i]);
	}
	getch();
}
void  DocDuLieuTiepTin(DanhSachPhieuMuonSach &dspms)
{
	int Check = 1;
	FILE *FileIn = fopen("PHIEUMUONSACH.TXT", "r");
	if (!FileIn)
	{
		Check = 0;
	}
	if (Check==1)
	{
		int i = 0;
		while (feof(FileIn)==NULL)
		{

			fscanf(FileIn, "%d\n", &dspms.MangChuaPhieuMuonSach[i].MDG);
			fscanf(FileIn, "%d\n", &dspms.MangChuaPhieuMuonSach[i].MS);
			fscanf(FileIn, "%d/%d/%d\n", &dspms.MangChuaPhieuMuonSach[i].NgayMuon, &dspms.MangChuaPhieuMuonSach[i].ThangMuon, &dspms.MangChuaPhieuMuonSach[i].NamMuon);
			fscanf(FileIn, "%d/%d/%d\n", &dspms.MangChuaPhieuMuonSach[i].NgayTraDuKien, &dspms.MangChuaPhieuMuonSach[i].ThangTraDuKien, &dspms.MangChuaPhieuMuonSach[i].NamTraDuKien);
			i++;
		}
		dspms.n = i;
		
		fclose(FileIn);
	}
}

/*
Kiem tra ma so tra sach
Nhan vao : MaSoTraSachDuocChon,MaSoTraSachDuocTra,DemSachTra,DemSach
XuatRa : Dung luu vao , Sai nhap lai*/
int KiemTraMaDocGiaTraSach(DanhSachPhieuMuonSach dspms)
{
	int w, Check = -1;
	printf("Nhap ma doc gia tra sach :");
	scanf("%d", &w);
	for (int i = 0; i < dspms.n; i++)
	{
		if (dspms.MangChuaPhieuMuonSach[i].MDG == w)
		{
			Check = dspms.MangChuaPhieuMuonSach[i].MDG;
			break;
		}
	}
	return Check;
}
/*
Tinh so tien phai tra no
nhan vao : Ngay,Thang,Nam tra du kien va Ngay,Thang,Nam tra thuc te
Xuat ra: So tien phai tra
*/
int KiemtraMaSachTra(DanhSachPhieuMuonSach dspms)
{
	int k;
	printf("Nhap vao ma tra sach ISBN : ");
	scanf("%d", &k);
	int Check = -1;
	for (int i = 0; i < dspms.n; i++)
	{
		if (dspms.MangChuaPhieuMuonSach[i].MS==k )
		{
			Check = dspms.MangChuaPhieuMuonSach[i].MS;
			break;
		}
	}
	return Check;
}
int TinhTien(PhieuMuonSach pms,PhieuTraSach &pts)
{
	int q4 = 0;
	int qi=KiemTraNgayThangNam(pts.NgayTraThucTe, pts.ThangTraThucTe, pts.NamTraThucTe);
	int q = KiemTraNgayTrongThang(pms.ThangTraDuKien, pms.NamTraDuKien);
	// So sanh ngay tra du kien voi ngay muon va ngay tra thuc te
	int q1 = pms.NgayTraDuKien + pms.ThangTraDuKien * 100 + pms.NamTraDuKien * 10000;
	int q2 = pts.NgayTraThucTe + pts.ThangTraThucTe* 100 + pts.NamTraThucTe * 10000;
	int q3 = pms.NgayMuon+ pms.ThangMuon * 100 + pms.NamMuon * 10000;
	int Hieu1 = q2 - q1;
	int Hieu2 = q2 - q3;
	// Nam Tra thuc te = nam tra du kien
	if (Hieu1 > 0 && pts.NamTraThucTe == pms.NamTraDuKien)
	{
		// thang tra thuc te > thang tra du kien
		if (pts.ThangTraThucTe > pms.ThangTraDuKien)
		{
			q4 = q - pms.NgayTraDuKien;
			int ThangTiep = pms.ThangTraDuKien + 1;
			for (int i = 0;; i++)
			{
				if (ThangTiep < pts.ThangTraThucTe)
				{
					int q = KiemTraNgayTrongThang(ThangTiep, pms.NamTraDuKien);
					q4 = q4 + q;
					ThangTiep++;
				}
				else if (ThangTiep >= pts.ThangTraThucTe)
				{
					q4 = q4 + pts.NgayTraThucTe;
					break;
				}
			}
		}
		// thang tra thuc te == thang tra du kien
		else if (pts.ThangTraThucTe == pms.ThangTraDuKien)
		{
			q4 = pts.NgayTraThucTe - pms.NgayTraDuKien;
		}
	}
	// Tra dung ngay
	else if (Hieu1 < 0 && Hieu2>0)
	{
		q4 = 0;
	}
	// Ngay thang nam tra lon hon du kien Nhung khac nam
	else if (Hieu1 > 0 && (pms.NamTraDuKien != pts.NamTraThucTe))
	{
		int TongTam = 0;
		for (int i = pms.NamTraDuKien; i < pts.NamTraThucTe; i++)
		{
			int z = KiemTraNamCoBaoNhieuNgay(pms.NamTraDuKien);
			TongTam = TongTam + z;
		}

		if (pts.ThangTraThucTe > pms.ThangTraDuKien)
		{
			q4 = TongTam;
			int q1 = KiemTraNgayTrongThang(pms.ThangTraDuKien, pts.NamTraThucTe);
			q4 = q4 + (q - pms.NgayTraDuKien);
			int ThangTiep = pms.ThangTraDuKien + 1;
			for (int i = 0;; i++)
			{
				if (ThangTiep < pts.ThangTraThucTe)
				{
					int q = KiemTraNgayTrongThang(ThangTiep, pts.NamTraThucTe);
					q4 = q4 + q;
					ThangTiep++;
				}
				else if (ThangTiep >= pts.ThangTraThucTe)
				{
					q4 = q4 + pts.NgayTraThucTe;
					break;
				}
			}
		}
		else  if (pts.ThangTraThucTe == pms.ThangTraDuKien)
		{
			q4 = TongTam;
			q4 = q4 + (pts.NgayTraThucTe - pms.NgayTraDuKien);
		}
		else if (pts.ThangTraThucTe < pms.ThangTraDuKien)
		{
			int DemNgay1 = KiemTraNgayTrongThang(pms.ThangTraDuKien, pms.NamTraDuKien);
			q4 = DemNgay1 - pms.NgayTraDuKien;
			int ThangTiep = pms.ThangTraDuKien + 1;
			for (int i = 0;; i++)
			{
				int CheckNgay = -1;
				int z5 = KiemTraNgayTrongThang(ThangTiep, pms.NamTraDuKien);
				q4 = q4 + z5;

				if (ThangTiep == 12)
				{
					ThangTiep = 1;
					for (int k = 0;; k++)
					{
						int z6 = KiemTraNgayTrongThang(ThangTiep, pts.NamTraThucTe);
						q4 = q4 + z6;
						if (ThangTiep == pts.ThangTraThucTe)
						{
							q4 = q4 + pts.NgayTraThucTe;
							CheckNgay = 0;
							break;
						}
						ThangTiep++;
					}
				}
				ThangTiep++;
				if (CheckNgay == 0)
				{
					break;
				}
			}
		}

	}
	// Tra thuc te < Ngay muon : Loi
	else if (Hieu2 <= 0)
	{
		q4 = 0;
	}
	int z = q4 * 5000;
	pts.Tien = z;
	system("cls");
	return z;
}
// Kiem tra trong 1 thang co bao nhieu ngay 
// nhan vao : Thang , nam 
int KiemTraNgayTrongThang(int Thang, int Nam)
{
	int SoNgayTrongThang = -1;
	switch (Thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		SoNgayTrongThang = 31;
		break;
	}
	case 2:
	{
		if (Nam % 4 == 0)
		{
			SoNgayTrongThang = 29;
			break;
		}
		else {
			SoNgayTrongThang = 28;
			break;
		}
	}
	case 4: case 6: case 9: case 11:
	{
		SoNgayTrongThang = 30;
		break;
	}
	}
	return SoNgayTrongThang;
}
// Kiem Tra nam co bao nhieu ngay
// Nhan vao : Nam
int KiemTraNamCoBaoNhieuNgay(int q)
{
	int SoNgay;
	if ((q % 4 == 0 && q % 100 != 0) || q % 400 == 0)
	{
		SoNgay = 366;
	}
	else 
	{
		SoNgay = 365;
	}
	return SoNgay;
}

void LuuVaoTepTinTraSach(PhieuTraSach pts)
{
	FILE *FileIn = fopen("PHIEUTRASACH.TXT", "a");
	fprintf(FileIn, "%d\n", pts.MDGTS);
	fprintf(FileIn, "%d\n", pts.MSTS);
	fprintf(FileIn, "%d/%d/%d\n", pts.NgayTraThucTe,pts.ThangTraThucTe,pts.NamTraThucTe);
	fprintf(FileIn, "%d\n", pts.Tien);
	fclose(FileIn);
}
void DocDuLieu(DanhSachPhieuTS &dspts)
{
	FILE *FileOut = fopen("PHIEUTRASACH.TXT", "r");
	int i = 0,Check=0;
	if (!FileOut)
	{
		Check=-1;
	}
	
	if (Check==0)
	{
		while (feof(FileOut)==NULL)
		{
			fscanf(FileOut, "%d\n", &dspts.DanhSachPhieuTraSach[i].MDGTS);
			fscanf(FileOut, "%d\n", &dspts.DanhSachPhieuTraSach[i].MSTS);
			fscanf(FileOut, "%d/%d/%d\n", &dspts.DanhSachPhieuTraSach[i].NgayTraThucTe, &dspts.DanhSachPhieuTraSach[i].ThangTraThucTe, &dspts.DanhSachPhieuTraSach[i].NamTraThucTe);
			fscanf(FileOut, "%d\n", &dspts.DanhSachPhieuTraSach[i].Tien);
			i++;
		}
		dspts.n = i;
		fclose(FileOut);
	}

}
void HamXuatPts(PhieuTraSach pts)
{
	printf("Ma doc gia tra sach : %d\n", pts.MDGTS);
	printf("Ma ISBN tra sach : %d\n", pts.MSTS);
	printf("Thoi gian tra thuc te : %d/%d/%d\n", pts.NgayTraThucTe,pts.ThangTraThucTe,pts.NamTraThucTe);
	printf("So tien phai tra : %d VND\n", pts.Tien);
}
void XuatDanhSachPhieuTraSach(DanhSachPhieuTS dspts)
{
	int Check = 0;
	FILE *FileIn = fopen("PHIEUTRASACH.txt", "r");
	for (int i = 0; i < dspts.n; i++)
	{
		printf("----------Thong tin doc gia thu %d-------------\n", i + 1);
		HamXuatPts(dspts.DanhSachPhieuTraSach[i]);
	}
	fclose(FileIn);
}
void NhapPhieuTraSach(PhieuTraSach &pts)
{
	int q = KiemTraNgayThangNam(pts.NgayTraThucTe, pts.ThangTraThucTe, pts.NamTraThucTe);
		
}
int NhapDanhSachPhieuTraSach(DanhSachPhieuTS &dspts, DanhSachPhieuMuonSach dspms,DanhSachSach dss)
{
	int n;
	printf("Nhap vao so luong phieu tra sach : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("------THONG TIN PHIEU TRA SACH %d------\n", i + 1);
		int q0 = KiemTraMaDocGiaTraSach(dspms);
		int q = KiemtraMaSachTra(dspms);
		int q1 = CheckViTri(dspms, q0);
		if (q0 != -1 && q != -1)
		{
			dspts.DanhSachPhieuTraSach[i].MDGTS = q0;
			dspts.DanhSachPhieuTraSach[i].MSTS = q;
			printf("[1] : Bao mat sach\n");
			printf("[2] : Nhap ngay tra sach\n");
			printf("Chon chuc nang : ");
			int k;
			scanf("%d", &k);
			if (k == 2)
			{
				int q2 = TinhTien(dspms.MangChuaPhieuMuonSach[q1], dspts.DanhSachPhieuTraSach[i]);
				LuuVaoTepTinTraSach(dspts.DanhSachPhieuTraSach[i]);
			}
			else
			{
				int Check;
				for (int j = 0; j < dss.n; j++)
				{
					if (dspts.DanhSachPhieuTraSach[i].MSTS == dss.MangChuaSach[j].ISBN)
					{
						Check = j;
						break;
					}
				}
				int q4 = KiemTraNgayThangNam(dspts.DanhSachPhieuTraSach[i].NgayTraThucTe, dspts.DanhSachPhieuTraSach[i].ThangTraThucTe, dspts.DanhSachPhieuTraSach[i].NamTraThucTe);
				int q2 = dss.MangChuaSach[Check].GiaSach * 2;
				dspts.DanhSachPhieuTraSach[i].Tien = q2;
				LuuVaoTepTinTraSach(dspts.DanhSachPhieuTraSach[i]);
			}
			
			dspts.n++;
			system("cls");
		}
		else
		{
			printf("KHONG THE THUC HIEN THAO TAC \n");
			return 0;
		}
	}
	return 1;
}
int CheckViTri(DanhSachPhieuMuonSach dspms,int a)
{
	for (int i = 0; i < dspms.n; i++)
	{
		if (a == dspms.MangChuaPhieuMuonSach[i].MDG)
		{
			a = i;
		}
	}
	return a;
}
