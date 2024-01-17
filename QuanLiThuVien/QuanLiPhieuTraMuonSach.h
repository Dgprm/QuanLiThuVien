#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include"QuanLiDocGia.h"
#include "QuanLiSach.h"
struct PhieuMuonSach
{
	int NgayMuon, ThangMuon, NamMuon, NgayTraDuKien, ThangTraDuKien, NamTraDuKien, NgayTraThucTe, NamTraThucTe, ThangTraThucTe,MDG,MS;
};
struct DanhSachPhieuMuonSach
{
	int n=0;
	PhieuMuonSach MangChuaPhieuMuonSach[100];
};
int CheckMaSo(DanhSachDocGia DanhSach);
int CheckMaSoSach(DanhSachSach dss);
void NhapPhieuMuonSach(PhieuMuonSach &pms);
int ThoiGianTraDuKien(PhieuMuonSach &pms);
void LuuVaoTepTin(PhieuMuonSach pms);
void XuatPhieuMuonSach(PhieuMuonSach pms);
int NhapDanhSachPhieuMuonSach(DanhSachPhieuMuonSach &dspms, DanhSachSach dss, DanhSachDocGia DanhSach);
void XuatDanhSachPhieuMuonSach(DanhSachPhieuMuonSach dspms);
void DocDuLieuTiepTin(DanhSachPhieuMuonSach &dspms);
struct PhieuTraSach
{
	int MDGTS, MSTS, NgayTraThucTe, ThangTraThucTe, NamTraThucTe, Tien;
};
struct DanhSachPhieuTS
{
	int n = 0;
	PhieuTraSach DanhSachPhieuTraSach[100];
};
int KiemTraMaDocGiaTraSach(DanhSachPhieuMuonSach dspms);
int KiemtraMaSachTra(DanhSachPhieuMuonSach dspms);
int KiemTraNgayTrongThang(int Thang, int Nam);
int KiemTraNamCoBaoNhieuNgay(int q);
void LuuVaoTepTinTraSach(PhieuTraSach pts);
void DocDuLieu(DanhSachPhieuTS &dspts);
void XuatDanhSachPhieuTraSach(DanhSachPhieuTS dspts);
void HamXuatPts(PhieuTraSach pts);
void NhapPhieuTraSach(PhieuTraSach &pts);
int NhapDanhSachPhieuTraSach(DanhSachPhieuTS &dspts, DanhSachPhieuMuonSach dspms, DanhSachSach dss);
int CheckViTri(DanhSachPhieuMuonSach dspms, int a);
void LuuDanhSachMatSach(PhieuTraSach pts);