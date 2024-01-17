#include "QuanLiDocGia.h"
#include "QuanLiSach.h"
#include "QuanLiPhieuTraMuonSach.h"
int main()
{
	ThongTinDocGia tt;
	DanhSachDocGia DanhSach;
	DanhSachSach dss;
	PhieuMuonSach pms;
	DanhSachPhieuMuonSach dspms;
	PhieuTraSach pts;
	DanhSachPhieuTS dspts;
	int a;
	char ten[2];
MenuChinh:
	system("cls");
	printf("------------------------- BANG CHUC NAM THU VIEN -------------------------\n");
	printf(" [1] : Quan li doc gia\n ");
	printf("[2] : Quan li sach \n ");
	printf("[3] : Lap phieu muon sach\n ");
	printf("[4] : Lap phieu tra sach \n ");
	printf("[5] : Cac thong ke co ban \n ");
	printf("[6] : Thoat khoi chuong trinh\n");
	DocNhieuDocgia(DanhSach);
	DocNhieuSach(dss);
	DocDuLieuTiepTin(dspms);
	DocDuLieu(dspts);
	printf("Nhap Chuc nang : ");
	scanf("%d", &a);
	switch (a)
	{
		// quan li thong tin doc gia
	case 1:
	{
	Menu1:
		system("cls");
		printf(" Quan li thong tin doc gia\n");
		printf(" [1] : Xem danh sach doc gia trong thu vien \n ");
		printf("[2] : Them doc gia \n ");
		printf("[3] : Chinh sua thong tin mot doc gia \n ");
		printf("[4] : Xoa thong tin mot doc gia \n ");
		printf("[5] : Tim kiem danh sach doc gia theo CMND \n ");
		printf("[6] : Tim kiem	doc gia theo ho ten \n ");
		DocNhieuDocgia(DanhSach);
		printf("[7] : Quay lai Menu chinh \n ");
		int ChucNang;
		// Cap nhat doc gia tu File .txt
		
		printf("Chon chuc nang : ");
		scanf("%d", &ChucNang);

		{
			switch (ChucNang)
			{
				// Hien danh sach thong tin doc gia
			case 1:

			{
				int Check = 1;

				FILE *FileIn = fopen("DANHSACHDOCGIA.TXT", "r");
				if (!FileIn)
				{
					Check = 0;
					system("cls");
					printf("Khong co doc gia trong danh sach ! Kiem tra lai\n");
					getch();
					goto Menu1;
				}
				if (Check != 0)
				{
					fseek(FileIn, 0, 2);
					if (ftell(FileIn) == 0)
					{
						system("cls");
						printf("Khong co doc gia trong danh sach ! Kiem tra lai\n");
						getch();
					}
					else
					{
						system("cls");
						XuatDanhSach(DanhSach);
						getch();
						goto Menu1;
					}
				}
				fclose(FileIn);
				goto Menu1;
			}
			// Them thong tin cua doc gia
			case 2:
			{
				system("cls");
				NhapDanhSachDocGia(DanhSach);
				getch();
				goto Menu1;
			}
			// Chinh sua thong tin doc gia
			case 3:
			{
				printf("Chuc nang chinh sua thong tin doc gia\n");
				// Kiem tra ma so doc gia
				int q = KiemTraMaSo(DanhSach);
				// khong tim thay ma so doc gia trong thu vien
				if (q == -1)
				{
					system("cls");
					printf("Khong Co so MSDG can tim\n");
					printf("Nhan enter de chon chuc nang\n");
					getch();
					system("cls");
					printf("[1] tro lai Menu\n");
					printf("[2] Thoat Khoi Chung trinh\n");
					printf("Nhap chuc nang : ");
					int ChucNang2;
					scanf("%d", &ChucNang2);
					if (ChucNang2 == 1)
					{
						goto Menu1;
					}
					else {
						exit(0);
					}
				}
				// CO tim thay ma so doc gia trong thu vien
				else
				{
					system("cls");
				Menu3:
					system("cls");
					printf("== Chuc nang chinh sua thong tin doc gia ==\n");
					printf(" [1] : Chinh sua ma so \n ");
					printf("[2] : Chinh sua CMND \n ");
					printf("[3] : Chinh sua ten \n ");
					printf("[4] : Chinh sua gioi tinh\n ");
					printf("[5] : Chinh sua email \n ");
					printf("[6] : Chinh sua ngay : thang : nam sinh\n ");
					printf("[7] : Chinh sua ngay : thang : nam lap the\n ");
					printf("[8] : Quay lai Menu chinh \n ");
					printf("[9] : Luu chinh sua ! Du lieu cu se mat \n");
					printf("Nhap vao chuc nang : ");
					int ChucNang3;
					scanf("%d", &ChucNang3);
					switch (ChucNang3)
					{
						/* chuc nang chinh sua ma so doc gia
						nhan vao : ma so doc gia moi*/
					case 1:
					{
						system("cls");
						fflush(stdin);
						printf("Nhap vao so MSDG moi : ");
						scanf("%d", &DanhSach.MangChuaDocGia[q].MaDocGia);
						////LuuChinhSua(dss);
						printf("Chinh sua Thanh cong ! ");
						getch();
						system("cls");
						{
							printf("[1] tro lai Menu\n");
							printf("[2] Thoat Khoi Chung trinh\n");
							printf("Nhap chuc nang : ");
							int ChucNang2;
							scanf("%d", &ChucNang2);
							if (ChucNang2 == 1)
							{
								goto Menu3;
							}
							else {
								exit(0);
							}
						}
					}
					/*
					Chuc nang chin sua chung minh dan dan
					nhan vao: chuc minh nhan dan moi
					*/
					case 2:
					{
						system("cls");
						fflush(stdin);
						printf("Nhap vao so CMND moi : ");
						scanf("%d", &DanhSach.MangChuaDocGia[q].Cmnd);
						printf("Chinh sua Thanh cong ! ");
						getch();
						system("cls");
						{
							printf("[1] tro lai Menu\n");
							printf("[2] Thoat Khoi Chung trinh\n");
							printf("Nhap chuc nang : ");
							int ChucNang2;
							scanf("%d", &ChucNang2);
							if (ChucNang2 == 1)
							{
								goto Menu3;
							}
							else {
								exit(0);
							}
						}
					}
					/*
					Chinh sua ho va ten
					nhap vao : ho va ten moi
					*/
					case 3:
					{

						system("cls");
						gets_s(ten);
						printf("Nhap vao Ho va Ten moi :");
						gets_s(DanhSach.MangChuaDocGia[q].HoTen);
						printf("\n Chinh sua thanh cong !\n");
						getch();
						system("cls");
						{
							printf("[1] tro lai Menu\n");
							printf("[2] Thoat Khoi Chung trinh\n");
							printf("Nhap chuc nang : ");
							int ChucNang2;
							scanf("%d", &ChucNang2);
							if (ChucNang2 == 1)
							{
								goto Menu3;
							}
							else {
								exit(0);
							}
						}
					}
					/*
					Chinh sua Email moi
					nhan vao : email moi*/
					case 4:
					{
						system("cls");
						gets_s(ten);
						printf("Nhap vao Gioi Tinh moi :");
						gets_s(DanhSach.MangChuaDocGia[q].GioiTinh);
						printf("Chinh sua thanh cong !\n");
						getch();
						system("cls");
						{
							printf("[1] tro lai Menu\n");
							printf("[2] Thoat Khoi Chung trinh\n");
							printf("Nhap chuc nang : ");
							int ChucNang2;
							scanf("%d", &ChucNang2);
							if (ChucNang2 == 1)
							{
								goto Menu3;
							}
							else {
								exit(0);
							}
						}


					}
					/*
					Chinh sua gioi tinh
					nhan vao : gioi tinh moi
					*/
					case 5: {

						system("cls");
						gets_s(ten);
						printf("Nhap vao Email moi : ");
						gets_s(DanhSach.MangChuaDocGia[q].Email);
						printf("Chinh sua thanh cong !\n");
						getch();
						system("cls");
						{
							printf("[1] tro lai Menu\n");
							printf("[2] Thoat Khoi Chung trinh\n");
							printf("Nhap chuc nang : ");
							int ChucNang2;
							scanf("%d", &ChucNang2);
							if (ChucNang2 == 1)
							{
								goto Menu3;
							}
							else {
								exit(0);
							}
						}

					}
							/*
							Chinh sua ngay thang nam sinh
							nhan vao : ngay thang nam sinh moi
							*/
					case 6: {
						system("cls");
						gets_s(ten);
						int q3 = KiemTraNgayThangNam(DanhSach.MangChuaDocGia[q].NgaySinh, DanhSach.MangChuaDocGia[q].ThangSinh, DanhSach.MangChuaDocGia[q].NamSinh);
						getch();
						system("cls");
						{
							printf("[1] tro lai Menu\n");
							printf("[2] Thoat Khoi Chung trinh\n");
							printf("Nhap chuc nang : ");
							int ChucNang2;
							scanf("%d", &ChucNang2);
							if (ChucNang2 == 1)
							{
								goto Menu3;
							}
							else {
								exit(0);
							}
						}

					}
							/*
							Chinh sua thoi gian thanh la the
							nhan vao : thoi gian thanh lap the moi*/
					case 7: {
						system("cls");
						gets_s(ten);
						int q4 = KiemTraNgayThangNam(DanhSach.MangChuaDocGia[q].NgayMuon, DanhSach.MangChuaDocGia[q].ThangMuon, DanhSach.MangChuaDocGia[q].NamMuon);
						DanhSach.MangChuaDocGia[q].NgayHet = DanhSach.MangChuaDocGia[q].NgayMuon;
						DanhSach.MangChuaDocGia[q].ThangHet = DanhSach.MangChuaDocGia[q].ThangMuon;
						DanhSach.MangChuaDocGia[q].NamHet = DanhSach.MangChuaDocGia[q].NamMuon + 4;
						system("cls");
						printf("\n Chinh sua thanh cong ! \n");
						getch();
						system("cls");
						{
							printf("[1] tro lai Menu\n");
							printf("[2] Thoat Khoi Chung trinh\n");
							printf("Nhap chuc nang : ");
							int ChucNang2;
							scanf("%d", &ChucNang2);
							if (ChucNang2 == 1)
							{
								goto Menu3;
							}
							else {
								exit(0);
							}

						}
					}
							/*
							tro ve menu chinh
							*/
					case 8:
					{
						goto Menu1;
					}
					case 9:
					{
						FILE*FileOut = fopen("DANHSACHDOCGIA.TXT", "w");
						fclose(FileOut);
						for (int i = 0; i < DanhSach.n; i++)
						{
							LuuVaoTepTin(DanhSach.MangChuaDocGia[i]);
						}
						printf("Thanh cong\n");
						getch();
						goto MenuChinh;
					}
					default:
					{
						system("cls");
						printf("Khong co chuc nang nay !\n");
						getch();
						goto Menu3;
					}

					}

				}
			}
			// ----------------ket thuc xu li sua thong tin doc gia---------
				/*
				Xoa thong tin cua 1 doc gia
				*/
			case 4:
			{
				system("cls");
				int q = KiemTraMaSo(DanhSach);
				if (q != -1)
				{
					DanhSach.n = DanhSach.n - 1;
					for (int i = q; i < DanhSach.n; i++)
					{
						system("cls");
						strcpy(DanhSach.MangChuaDocGia[i].HoTen, DanhSach.MangChuaDocGia[i + 1].HoTen);
						strcpy(DanhSach.MangChuaDocGia[i].Email, DanhSach.MangChuaDocGia[i + 1].Email);
						strcpy(DanhSach.MangChuaDocGia[i].DiaChi, DanhSach.MangChuaDocGia[i + 1].DiaChi);
						DanhSach.MangChuaDocGia[i].NgaySinh = DanhSach.MangChuaDocGia[i + 1].NgaySinh;
						DanhSach.MangChuaDocGia[i].ThangSinh = DanhSach.MangChuaDocGia[i + 1].ThangSinh;
						DanhSach.MangChuaDocGia[i].NamSinh = DanhSach.MangChuaDocGia[i + 1].NamSinh;
						DanhSach.MangChuaDocGia[i].NgayMuon = DanhSach.MangChuaDocGia[i + 1].NgayMuon;
						DanhSach.MangChuaDocGia[i].ThangMuon = DanhSach.MangChuaDocGia[i + 1].ThangMuon;
						DanhSach.MangChuaDocGia[i].NamMuon = DanhSach.MangChuaDocGia[i + 1].NamMuon;
						DanhSach.MangChuaDocGia[i].NgayHet = DanhSach.MangChuaDocGia[i + 1].NgayHet;
						DanhSach.MangChuaDocGia[i].ThangHet = DanhSach.MangChuaDocGia[i + 1].ThangHet;
						DanhSach.MangChuaDocGia[i].NamHet = DanhSach.MangChuaDocGia[i + 1].NamHet;
						DanhSach.MangChuaDocGia[i].Cmnd = DanhSach.MangChuaDocGia[i + 1].Cmnd;
						DanhSach.MangChuaDocGia[i].MaDocGia = DanhSach.MangChuaDocGia[i + 1].MaDocGia;
					}
					FILE*FileIn = fopen("DANHSACHDOCGIA.TXT", "w");
					fclose(FileIn);
					for (int i = 0; i < DanhSach.n; i++)
					{
						LuuVaoTepTin(DanhSach.MangChuaDocGia[i]);
					}
					system("cls");
					printf("Xoa thanh cong !\n");
					getch();
					goto MenuChinh;

				}

				else {
					system("cls");
					printf("Khong ton tai doc gia ! Kiem tra lai \n");
					getch();
					goto Menu1;
				}

			}
			/*
			Tim kiem doc gia bang Cmnd
			*/
			case 5:
			{
				int q = TimKiemBangCMND(DanhSach);
				if (q != -1)
				{
					system("cls");
					HamXuat(DanhSach.MangChuaDocGia[q]);
					getch();
					goto Menu1;
				}
				else {
					system("cls");
					printf("Khong ton tai CMND ! Kiem tra lai !\n");
					getch();
					goto Menu1;
				}
			}
			case 6:
			{
				int q = TimKiemDocGiaTheoHoTen(DanhSach);
				if (q != -1)
				{
					system("cls");
					HamXuat(DanhSach.MangChuaDocGia[q]);
					getch();
					goto Menu1;
				}
				else {
					system("cls");
					printf("Khong ton tai ten nay ! Kiem tra lai !\n");
					getch();
					goto Menu1;
				}
			}
			case 7:
			{
				goto MenuChinh;
			}
			default:
			{
				system("cls");
				printf("Khong co chuc nang nay !\n");
				goto Menu1;
			}
			}
		}
	}
	// quan li thong tin sach
	case 2:
	{
	Menu4:
		system("cls");
		printf(" ===Quan li sach=== \n");
		printf("  [1] : Xem thong tin sach trong thu vien \n ");
		printf(" [2] : Them sach \n ");
		printf(" [3] : Chinh sua thong tin 1 quyen sach thu vien \n ");
		printf(" [4] : Xoa thong tin quyen sach \n ");
		printf(" [5] : Tim kiem sach theo ISBN\n ");
		printf(" [6] : Tim Kiem sach theo ten sach\n ");
		printf(" [7] : Quay Lai Menu chinh\n ");
		DocNhieuSach(dss);
		printf("Chon chuc nang  : ");
		int ChucNang;

		scanf("%d", &ChucNang);

		switch (ChucNang)
		{
			/* Xem thong tin cua sach trong thu vien
			*/
		case 1:
		{int Check = 1;

		FILE *FileIn = fopen("DANHSACHQUYENSACH.TXT", "r");
		if (!FileIn)
		{
			Check = 0;
			system("cls");
			printf("Khong co sach ! Kiem tra lai\n");
			getch();
			goto Menu4;
		}
		if (Check != 0)
		{
			fseek(FileIn, 0, 2);
			if (ftell(FileIn) == 0)
			{
				system("cls");
				printf("Khong co sach ! Kiem tra lai\n");
				getch();
				goto Menu4;
			}
			else
			{
				system("cls");
				XuatDanhSachSach(dss);
				fclose(FileIn);
				goto Menu4;
			}
		}
		}

		/*	Ham nhap sach
		nhap vao : ten sach, tac gia , nha xuat ban , the loai, gia sach , so quyen sach, nam xuat ban,ISBn
		*/
		case 2: {
			system("cls");
			NhapDanhSachSach(dss);
			getch();
			goto Menu4;

		}
				/* Chinh sua thonng cua sach
				Nhan vao :  ten sach, tac gia , nha xuat ban , the loai, gia sach , so quyen sach, nam xuat ban,ISBn
				Xuat ra : ten sach, tac gia , nha xuat ban , the loai, gia sach , so quyen sach, nam xuat ban,ISBn moi
				*/
		case 3:
		{
			system("cls");
			printf("== Chuc nang chinh sua thong tin sach ==\n");
			int q = KiemTraMaSoSach(dss);
			if (q == -1)
			{
				system("cls");
				printf("Khong Co so MSDG can tim\n");
				printf("Nhan enter de chon chuc nang\n");
				getch();
				system("cls");
				printf("[1] tro lai Menu\n");
				printf("[2] Thoat Khoi Chung trinh\n");
				printf("Nhap chuc nang : ");
				int ChucNang2;
				scanf("%d", &ChucNang2);
				if (ChucNang2 == 1)
				{
					goto Menu4;
				}
				else {
					exit(0);
				}
			}

			else
			{
				system("cls");
			Menu5:
				system("cls");
				printf("== Chuc nang chinh sua thong tin doc gia ==\n");
				printf(" [1] : Chinh sua ten sach \n ");
				printf("[2] : Chinh sua tac gia \n ");
				printf("[3] : Chinh sua nha xuat ban \n ");
				printf("[4] : Chinh sua the loai\n ");
				printf("[5] : Chinh sua gia sach \n ");
				printf("[6] : Chinh sua so quyen sach\n ");
				printf("[7] : Chinh sua nam xuat ban\n ");
				printf("[8] : Chinh sua ISBN\n ");
				printf("[9] : Luu Chinh sua vao tep tin!\n ");
				printf("[10] : Quay lai Menu \n ");

				printf("Nhap vao chuc nang : ");
				int ChucNang3;
				scanf("%d", &ChucNang3);
				//gets_s(ten[q]);
				fflush(stdin);
				switch (ChucNang3)
				{
					char ten[2];
				case 1: {
					system("cls");

					gets_s(ten);
					printf("Nhap ten sach moi : ");
					gets_s(dss.MangChuaSach[q].TenSach);
					//LuuChinhSua(dss);
					getch();
					system("cls");
					{
						printf("[1] tro lai Menu\n");
						printf("[2] Thoat Khoi Chung trinh\n");
						printf("Nhap chuc nang : ");
						int ChucNang2;
						scanf("%d", &ChucNang2);
						if (ChucNang2 == 1)
						{
							goto Menu5;
						}
						else {
							exit(0);
						}
					}
				}
				case 2:
				{
					system("cls");
					gets_s(ten);
					printf("Nhap ten tac gia  : ");
					gets_s(dss.MangChuaSach[q].TacGia);
					//LuuChinhSua(dss);
					getch();
					system("cls");
					{
						printf("[1] tro lai Menu\n");
						printf("[2] Thoat Khoi Chung trinh\n");
						printf("Nhap chuc nang : ");
						int ChucNang2;
						scanf("%d", &ChucNang2);
						if (ChucNang2 == 1)
						{
							goto Menu5;
						}
						else {
							exit(0);
						}
					}
				default:
					break;
				}
				case 3:
				{
					system("cls");
					gets_s(ten);
					printf("Nhap nha xuat ban moi : ");
					gets_s(dss.MangChuaSach[q].NSB);
					//LuuChinhSua(dss);
					getch();
					system("cls");
					{
						printf("[1] tro lai Menu\n");
						printf("[2] Thoat Khoi Chung trinh\n");
						printf("Nhap chuc nang : ");
						int ChucNang2;
						scanf("%d", &ChucNang2);
						if (ChucNang2 == 1)
						{
							goto Menu5;
						}
						else {
							exit(0);
						}
					}
				}
				case 4:
				{fflush(stdin);
				system("cls");
				gets_s(ten);
				printf("Nhap the loai moi : ");
				gets_s(dss.MangChuaSach[q].TheLoai);
				//LuuChinhSua(dss);
				getch();
				system("cls");
				{
					printf("[1] tro lai Menu\n");
					printf("[2] Thoat Khoi Chung trinh\n");
					printf("Nhap chuc nang : ");
					int ChucNang2;
					scanf("%d", &ChucNang2);
					if (ChucNang2 == 1)
					{
						goto Menu5;
					}
					else {
						exit(0);
					}
				}
				}
				case 5:
				{
					system("cls");
					printf("Nhap gia sach moi : ");
					scanf("%d", &dss.MangChuaSach[q].GiaSach);
					//LuuChinhSua(dss);
					getch();
					system("cls");
					{
						printf("[1] tro lai Menu\n");
						printf("[2] Thoat Khoi Chung trinh\n");
						printf("Nhap chuc nang : ");
						int ChucNang2;
						scanf("%d", &ChucNang2);
						if (ChucNang2 == 1)
						{
							goto Menu5;
						}
						else {
							exit(0);
						}
					}
				}
				case 6:
				{
					system("cls");
					printf("Nhap so quyen sach moi : ");
					scanf("%d", &dss.MangChuaSach[q].SoQuyenSach);
					//LuuChinhSua(dss);
					getch();
					system("cls");
					{
						printf("[1] tro lai Menu\n");
						printf("[2] Thoat Khoi Chung trinh\n");
						printf("Nhap chuc nang : ");
						int ChucNang2;
						scanf("%d", &ChucNang2);
						if (ChucNang2 == 1)
						{
							goto Menu5;
						}
						else {
							exit(0);
						}
					}
				}
				case 7:
				{
					system("cls");
					printf("Nhap nam san xuat moi : ");
					scanf("%d", &dss.MangChuaSach[q].NamXuatBan);
					//LuuChinhSua(dss);
					getch();
					system("cls");
					{
						printf("[1] tro lai Menu\n");
						printf("[2] Thoat Khoi Chung trinh\n");
						printf("Nhap chuc nang : ");
						int ChucNang2;
						scanf("%d", &ChucNang2);
						if (ChucNang2 == 1)
						{
							goto Menu5;
						}
						else {
							exit(0);
						}}
				}
				case 8:
				{
					system("cls");
					printf("Nhap ISBN moi : ");
					scanf("%d", &dss.MangChuaSach[q].ISBN);
					//LuuChinhSua(dss);
					getch();
					system("cls");
					{
						printf("[1] tro lai Menu\n");
						printf("[2] Thoat Khoi Chung trinh\n");
						printf("Nhap chuc nang : ");
						int ChucNang2;
						scanf("%d", &ChucNang2);
						if (ChucNang2 == 1)
						{
							goto Menu5;
						}
						else {
							exit(0);
						}}

				}

				case 9:
				{
					FILE*FileOut = fopen("DANHSACHQUYENSACH.TXT", "w");
					fclose(FileOut);
					for (int i = 0; i < dss.n; i++)
					{
						LuuVaoTepTin(dss.MangChuaSach[i]);
					}
					printf("Thanh cong\n");
					getch();
					goto MenuChinh;
				}
				case 10:
				{
					goto Menu4;
				}
				}
			}

			{
				printf("Khong co chuc nang nay ! Kiem tra lai\n");
				getch();
				goto Menu5;
			}
		}

		/*
		Xoa thong tin cua sach
		*/
		case 4:
		{
			system("cls");
			int q = KiemTraMaSoSach(dss);
			if (q == -1)
			{
				system("cls");
				printf("Khong ton tai ISBN nay ! Kiem tra lai \n");
				getch();
				goto Menu4;
			}
			else {
				dss.n = dss.n - 1;
				for (int i = q; i < dss.n; i++)
				{
					system("cls");
					strcpy(dss.MangChuaSach[i].TenSach, dss.MangChuaSach[i + 1].TenSach);
					strcpy(dss.MangChuaSach[i].TacGia, dss.MangChuaSach[i + 1].TacGia);
					strcpy(dss.MangChuaSach[i].NSB, dss.MangChuaSach[i + 1].NSB);
					strcpy(dss.MangChuaSach[i].TheLoai, dss.MangChuaSach[i + 1].TheLoai);
					dss.MangChuaSach[i].NamXuatBan = dss.MangChuaSach[i + 1].NamXuatBan;
					dss.MangChuaSach[i].GiaSach = dss.MangChuaSach[i + 1].GiaSach;
					dss.MangChuaSach[i].ISBN = dss.MangChuaSach[i + 1].ISBN;
					dss.MangChuaSach[i].SoQuyenSach = dss.MangChuaSach[i + 1].SoQuyenSach;
				}
				FILE*FileIn = fopen("DANHSACHQUYENSACH.TXT", "w");
				fclose(FileIn);
				for (int i = 0; i < DanhSach.n; i++)
				{
					LuuVaoTepTin(DanhSach.MangChuaDocGia[i]);
				}
				system("cls");
				printf("Xoa thanh cong !\n");
				getch();
				goto MenuChinh;
			}
		}
		case 5:
		{
			system("cls");
			int q = KiemTraMaSoSach(dss);
			if (q != -1)
			{
				system("cls");
				printf("--------THONG TIN SACH -----------\n");
				XuatThongTinSach(dss.MangChuaSach[q]);
				getch();
				goto Menu4;
			}
			else
			{
				system("cls");
				printf("Khong ton ISBN nay ! Kiem tra lai !\n");
				getch();
				goto Menu4;
			}
		}
		case 6:
		{// Tim kiem sach theo ten
			system("cls");
			int q = TimKiemSachTheoTen(dss);
			if (q != -1)
			{
				system("cls");
				printf("--------THONG TIN SACH -----------\n");
				XuatThongTinSach(dss.MangChuaSach[q]);
				getch();
				goto Menu4;
			}
			else {
				system("cls");
				printf("Khong ton tai ten nay ! Kiem tra lai !\n");
				getch();
				goto Menu4;
			}
		}
		case 7:
		{
			goto MenuChinh;
		}
		}
	}
	// Phieu muon sach
	case 3:

	{
	Menu7:
		system("cls");

		printf("---------- QUAN LI PHIEU MUON SACH ----------\n");
		printf("[1] : Xem danh sach phieu muon sach\n");
		printf("[2] : Them phieu muon sach\n");
		printf("[3] : Tro ve Menu\n");
		int ChucNang6;
		DocDuLieuTiepTin(dspms);
		printf("Nhap chuc nang : ");
		scanf("%d", &ChucNang6);
		switch (ChucNang6)
		{
		case 1:
		{
			int Check = 1;

			FILE *FileIn = fopen("PHIEUMUONSACH.TXT", "r");
			if (!FileIn)
			{
				Check = 0;
				system("cls");
				printf("Khong co phieu muon sach nao ! Kiem tra lai\n");
				getch();
				goto Menu7;
			}
			if (Check != 0)
			{
				fseek(FileIn, 0, 2);
				if (ftell(FileIn) == 0)
				{
					system("cls");
					printf("Khong co phieu muon sach nao ! Kiem tra lai\n");
					fclose(FileIn);
					getch();
				}
				else
				{
					system("cls");
					XuatDanhSachPhieuMuonSach(dspms);
					fclose(FileIn);
					goto Menu7;
				}
			}
			goto Menu7;
		}

		case 2:
		{
			system("cls");
			int q = NhapDanhSachPhieuMuonSach(dspms, dss, DanhSach);
			if (q == 1)
			{
				system("cls");
				printf("Khong thanh cong ! Kiem tra lai\n");
				getch();
				goto Menu7;
			}
			else if (q==0)
			{
				system("cls");
				printf("Thanh cong !\n");
				getch();
				goto Menu7;
			}
		}

		case 3: {
			goto MenuChinh;
		}
		}
	}
			
		// Phieu tra sach
		case 4 :
		{
			system("cls");
		MenuTraSach:
			system("cls");
			printf("======== QUAN LI PHIEU TRA SACH ========\n");
			printf("[1] : Xem danh sach phieu tra sach\n");
			printf("[2] : Them phieu tra sach\n");
			printf("[3] : Quay lai menu\n");
			DocDuLieu(dspts);
			fflush(stdin);
			int ChucNang6;
			printf("Chon chuc nang : ");
			scanf("%d", &ChucNang6);
			switch (ChucNang6)
			{
			case 1:
			{
				int Check = 1;

				FILE *FileIn = fopen("PHIEUTRASACH.TXT", "r");
				if (!FileIn)
				{
					Check = 0;
					system("cls");
					printf("Khong co phieu tra sach ! Kiem tra lai\n");
					getch();
					goto MenuTraSach;
				}
				if (Check != 0)
				{
					fseek(FileIn, 0, 2);
					if (ftell(FileIn) == 0)
					{
						system("cls");
						printf("Khong co pieu tra sach ! Kiem tra lai\n");
						getch();
					}
					else
					{
						system("cls");
						XuatDanhSachPhieuTraSach(dspts);
						getch();
						goto MenuTraSach;
					}
				}
				fclose(FileIn);
				goto MenuTraSach;
			}
			case 2:

			{
				system("cls");
				int q = NhapDanhSachPhieuTraSach(dspts, dspms,dss);
				if (q == 0)
				{
					system("cls");
					printf("KHONG TON TAI ISBN HOAC MA DOC GIA ! KIEM TRA LAI\n");
					getch();
					goto MenuTraSach;
				}
				getch();
				goto MenuTraSach;
				// Kiem tra ngay thang nam nhap				

			}
			case 3 :
			{
				goto MenuChinh;

			}
			}
			
			}
		// Cach thong ke khac
		case 5:
		{

			system("cls");
		Menu8:
			system("cls");
			printf("==== CAC THONG KE CO BAN KHAC\n");
			printf("[1] : Thong ke so sach trong thu vien\n");
			printf("[2] : Thong ke luong sach theo the loai\n");
			printf("[3] : Thong ke so luong doc gia\n");
			printf("[4] : Thong ke luong doc gia theo gioi tinh\n");
			printf("[5] : Thong ke so sach bi muon tre\n");
			printf("[6] : Thong ke danh sach doc gia muon tre\n");
			printf("[7] : Quay lai Menu\n");
			printf("Nhap chuc nang : ");
			int ChucNang8;
			scanf("%d", &ChucNang8);
			switch (ChucNang8)
			{
				// Thong ke so luong sach trong thu vien
			case 1:
			{
				if (dss.n == 0)
				{
					system("cls");
					printf("So luong sach : 0 quyen sach ");
					getch();
					system("cls");
					printf("[1] tro lai Menu\n");
					printf("[2] Thoat Khoi Chung trinh\n");
					printf("Nhap chuc nang : ");
					int ChucNang2;
					scanf("%d", &ChucNang2);
					if (ChucNang2 == 1)
					{
						goto Menu8;
					}
					else
					{
						exit(0);
					}
				}
				else {
					system("cls");
					int Tong = 0;
					for (int i = 0; i < dss.n; i++)
					{
						Tong = Tong + dss.MangChuaSach[i].SoQuyenSach;
					}
					printf("So luong sach : %d quyen sach\n",Tong);
					getch();
					system("cls");
					printf("[1] tro lai Menu\n");
					printf("[2] Thoat Khoi Chung trinh\n");
					printf("Nhap chuc nang : ");
					int ChucNang2;
					scanf("%d", &ChucNang2);
					if (ChucNang2 == 1)
					{
						goto Menu8;
					}
					else
					{
						exit(0);
					}
				}
			}
			// Thong ke so luong sach theo the loai
			case 2:
			{
				if (dss.n == 0)
				{
					system("cls");
					printf("So sach thu vien : 0 quyen ! Kiem tra lai !!!\n");
					getch();
					system("cls");
					printf("[1] tro lai Menu\n");
					printf("[2] Thoat Khoi Chung trinh\n");
					printf("Nhap chuc nang : ");
					int ChucNang2;
					scanf("%d", &ChucNang2);
					if (ChucNang2 == 1)
					{
						goto Menu8;
					}
					else {
						exit(0);
					}
				}
				else
				{
					ThongKeSachTheoTheLoai(dss);
					getch();
					system("cls");
					printf("[1] tro lai Menu\n");
					printf("[2] Thoat Khoi Chung trinh\n");
					printf("Nhap chuc nang : ");
					int ChucNang2;
					scanf("%d", &ChucNang2);
					if (ChucNang2 == 1)
					{
						goto Menu8;
					}
					else {
						exit(0);
					}
				}
			}
			case 3:
			{
				if (DanhSach.n == 0)
				{
					system("cls");
					printf("So doc gia trng thu vien : 0 doc gia ! Kiem tra lai !!!\n");
					getch();
					system("cls");
					printf("[1] tro lai Menu\n");
					printf("[2] Thoat Khoi Chung trinh\n");
					printf("Nhap chuc nang : ");
					int ChucNang2;
					scanf("%d", &ChucNang2);
					if (ChucNang2 == 1)
					{
						goto Menu8;
					}
					else {
						exit(0);
					}
				}
				else
				{
					system("cls");
					printf("So doc gia trong thu vien la : %d doc gia ", DanhSach.n);
					getch();
					system("cls");
					printf("[1] tro lai Menu\n");
					printf("[2] Thoat Khoi Chung trinh\n");
					printf("Nhap chuc nang : ");
					int ChucNang2;
					scanf("%d", &ChucNang2);
					if (ChucNang2 == 1)
					{
						goto Menu8;
					}
					else {
						exit(0);
					}
				}
			}
			case 4: {
				if (DanhSach.n == 0)
				{
					system("cls");
					printf("So doc gia trong thu vien : 0 doc gia ! Kiem tra lai !!!\n");
					getch();
					system("cls");
					printf("[1] tro lai Menu\n");
					printf("[2] Thoat Khoi Chung trinh\n");
					printf("Nhap chuc nang : ");
					int ChucNang2;
					scanf("%d", &ChucNang2);
					if (ChucNang2 == 1)
					{
						goto Menu8;
					}
					else {
						exit(0);
					}
				}
				else
				{
					system("cls");
					ThongKeDocGiaTheoGioiTinh(DanhSach);
					system("cls");
					printf("[1] tro lai Menu\n");
					printf("[2] Thoat Khoi Chung trinh\n");
					printf("Nhap chuc nang : ");
					int ChucNang2;
					scanf("%d", &ChucNang2);
					if (ChucNang2 == 1)
					{
						goto Menu8;
					}
					else {
						exit(0);
					}
				}

			default:
				break;
			}
			case 5:
			{
				system("cls");
				printf("So sach bi tra tre : %d quyen sach\n", dspts.n);
				getch();
				system("cls");
				printf("[1] tro lai Menu\n");
				printf("[2] Thoat Khoi Chung trinh\n");
				printf("Nhap chuc nang : ");
				int ChucNang2;
				scanf("%d", &ChucNang2);
				if (ChucNang2 == 1)
				{
					goto Menu8;
				}
				else
				{
					exit(0);
				}
			}
			case 6: {
				system("cls");
				if (dspts.n == 0)
				{
					printf("Khong co doc gia nao tra tre !\n");
				}
				else {
					printf("DANH SACH DOC GIA TRA SACH TRE\n");
					for (int i = 0; i < dspts.n; i++)
					{
						printf("Ma so doc gia : %d\n", dspts.DanhSachPhieuTraSach[i].MDGTS);
					}
				}
				getch();
				system("cls");
				printf("[1] tro lai Menu\n");
				printf("[2] Thoat Khoi Chung trinh\n");
				printf("Nhap chuc nang : ");
				int ChucNang2;
				scanf("%d", &ChucNang2);
				if (ChucNang2 == 1)
				{
					goto Menu8;
				}
				else
				{
					exit(0);
				}
			}
			case 7:
			{
				goto MenuChinh;
			}
			}
		}
		case 6:
		{
			exit(0);
		}
		default:
		{system("cls");
			printf("Khong co chuc nang nay !\n");
			getch();
			goto MenuChinh;
		}
		}
		
	}
	
