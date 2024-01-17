#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct ThongTinSach
{
	char TenSach[50], TacGia[50], NSB[50], TheLoai[50];
	int GiaSach, SoQuyenSach, NamXuatBan, ISBN;
};
struct DanhSachSach
{
	int n=0;
	ThongTinSach MangChuaSach[100];
};
void LuuVaoTepTin(ThongTinSach tt);
void NhapThongTinSach(ThongTinSach &tt);
void NhapDanhSachSach(DanhSachSach &dss);
void XuatThongTinSach(ThongTinSach tt);
void XuatDanhSachSach(DanhSachSach dss);
int KiemTraMaSoSach(DanhSachSach dss);
int TimKiemSachTheoTen(DanhSachSach dss);
void DocNhieuSach(DanhSachSach &DanhSach);
void ThongKeSachTheoTheLoai(DanhSachSach dss);


