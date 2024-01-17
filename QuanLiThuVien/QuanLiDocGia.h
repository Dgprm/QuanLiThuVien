#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct ThongTinDocGia
{
	char HoTen[40], GioiTinh[10], Email[50], DiaChi[50];
	int NgaySinh, ThangSinh, NamSinh, NgayMuon, ThangMuon, NamMuon, MaDocGia, Cmnd, NgayHet, ThangHet, NamHet;
};

void NhapThongTinDocGia(ThongTinDocGia & tt);
int KiemTraNgayThangNam(int &CheckNgay, int &CheckThang, int &CheckNam);
struct DanhSachDocGia
{
	int n=0;
	
	ThongTinDocGia MangChuaDocGia[100];
};
void NhapDanhSachDocGia(DanhSachDocGia & DanhSach);
void XuatDanhSach(DanhSachDocGia DanhSach);
void LuuVaoTepTin(ThongTinDocGia tt);
void DocDocGia(ThongTinDocGia &tt);
void DemLuonngDocGia(DanhSachDocGia &DanhSach);
void DocNhieuDocgia(DanhSachDocGia &DanhSach);
void HamXuat(ThongTinDocGia & tt);
int KiemTraMaSo(DanhSachDocGia DanhSach);
int HamNhapMaSo();
int HamNhapCmnd();
int TimKiemBangCMND(DanhSachDocGia DanhSach);
void XoaDocGia(DanhSachDocGia &DanhSach);
int TimKiemDocGiaTheoHoTen(DanhSachDocGia DanhSach);
void ThongKeDocGiaTheoGioiTinh(DanhSachDocGia DanhSach);