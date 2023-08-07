
#include "QLLopTinChi.h"
#include "windows.h"

void menu();
// Khai bao
dsmh DS;
PTRSV DSsinhvien;
Dslop* root_dsltc = NULL;
void khoitao()
{
	SV_Init(DSsinhvien);
	//DS.nodemonhoc = MH_createRecordMH(ooMH);
	for(int i = 0;i<300; i++)
	{
		DS.nodemonhoc[i] = new NodeMH;
	}
}
void docFile()
{
	MH_DocDSMHTuFile(DS);
	SV_DocDSSVTuFile(DSsinhvien);
	root_dsltc =  DocDSLTCTuFile(root_dsltc);
}
void giaiphong()
{
	Free( root_dsltc );
}
void MenuChinh();
void MenuQLlopTC();
void MenuQLsinhvien();
void MenuQLMonHoc();
void MenuTinChi();
int main()
{
	khoitao();
	docFile();
	
	int luachon = 0;
	do{
		system("cls");
		MenuChinh();
		cin >> luachon;
		cin.ignore();
		switch(luachon)
		{
			case 1:
				{
					int luachon1 = 0;
					do{
						tieeptuc:
							system("cls");
							MenuQLlopTC();
							cin >> luachon1;
							cin.ignore();
												switch(luachon1)
												{
													case 1:
														{
															cout << "\t\t\tDANH SACH CAC MON HOC DE MO LOP TIN CHI\n\n";
															MH_XuatDSMH(DS);
															cout << "\n";
															ThemLTC(root_dsltc,DS);
															LuuFileLTC(root_dsltc);
															break;
														}
													case 2:
														{
															int maloptinchi = 0;
															cout << "Nhap ma lop tin chi: ";
															cin >> maloptinchi;
															cin.ignore();
															Ltc lop;
															lop.malopTc = maloptinchi;
															if(Search(root_dsltc,lop)==false)
															{
																cout << "Khong co ma lop tin chi trong danh sach\n";
																system("pause");
																break;
															}
															else
															{
																SuaLTC(root_dsltc,maloptinchi);
																LuuFileLTC(root_dsltc);
																cout << "Sua thanh cong\n";
															}
															
															break;
														}
													case 3:
														{
															XoaLTC(root_dsltc);
															LuuFileLTC(root_dsltc);
															cout << "Xoa thanh cong\n";
															break;
														}
													case 4:
														{
															
															char nienkhoa[5];
															cout <<"Nhap nien khoa: ";
															cin.getline(nienkhoa,5);
															if(kiemtra_nienkhoa(root_dsltc,nienkhoa)==0)
															{
																cout << "Nien khoa khong ton tai\n";
																luachon1 = -1;
																system("pause");
																goto tieeptuc;
															}
															else
															{
																cout <<"\t\t\t\t\t\t\tD/sach sv dang ky lop tin chi theo nien khoa\n\n";
																InDSLopTC_nienkhoa(root_dsltc,DSsinhvien, nienkhoa);
																system("pause");
																break;
															}
															
															//break;	
														}
													case 5:
														{
														
															char hocky[2];
															cout <<"Nhap hoc ky: ";
															cin.getline(hocky,2);
															
															if(kiemtra_HK(root_dsltc,hocky)==0)
															{
																cout << "Hoc ky khong ton tai\n";
																system("pause");
																goto tieeptuc;
															}
															else
															{
																cout <<"\t\t\t\t\t\t\tD/sach sv dang ky lop tin chi theo hoc ky\n\n";
																InDSLopTC_HK(root_dsltc,DSsinhvien, hocky);
															}
																
															system("pause");
															break;
														}
													case 6:
														{
														
															char nhom[2];
															cout <<"Nhap nhom: ";
															cin.getline(nhom,2);
															
															if(kiemtra_Nhom(root_dsltc,nhom)==0)
															{
																cout << "Ma nhom khong ton tai\n";
																system("pause");
																goto tieeptuc;
															}
															else
															{
																cout <<"\t\t\t\t\t\t\tD/sach sv dang ky lop tin chi theo nhom\n\n";
																InDSLopTC_Nhom(root_dsltc,DSsinhvien, nhom);
															}
																
															system("pause");
															break;
														}
													case 7:
														{
															
															char mamonhoc[11];
															cout <<"Nhap ma mon hoc: ";
															cin.getline(mamonhoc,11);
															
															if(kiemtra_mmh(root_dsltc,mamonhoc)==0)
															{
																cout << "Ma mon hoc khong ton tai\n";
																system("pause");
																goto tieeptuc;
															}
															else
															{
																cout <<"\t\t\t\t\t\t\tD/sach sv dang ky lop tin chi theo ma mon hoc\n\n";
																InDSLopTC_MMH(root_dsltc,DSsinhvien,mamonhoc);
															}
																
															system("pause");
															break;
														}
													case 0:
														{
															cout << "Ban chon thoat roi\n";
															system("pause");
															break;
														}
												}
					}while(luachon1!=0);
						
					break;
				}
			case 2:
				{
					int luachon1 = 0;
					do{
						
							system("cls");
							MenuQLsinhvien();
							cin >> luachon1;
							cin.ignore();
												switch(luachon1)
												{
													case 1:
														{
															SV_NhapSV(DSsinhvien);
															SV_Sapxep(DSsinhvien);
															SV_LuuFileSV(DSsinhvien);
															system("pause");
															break;
														}
													case 2:
														{
															SV_SuaTTSV(DSsinhvien);
															SV_LuuFileSV(DSsinhvien);
															system("pause");
															break;
														}
													case 3:
														{
															SV_XoaTTSV(DSsinhvien);
															SV_LuuFileSV(DSsinhvien);
															system("pause");
															break;
														}
													case 4:
														{
															char malop[14];
															cout <<"Nhap ma lop: ";
															cin.getline(malop,14);
															cout <<"\t\t\t\t\t\t\tD/sach sv theo ma lop\n\n";
															SV_XuatDSSVtheomalop(DSsinhvien,malop);
															SV_LuuFileSV(DSsinhvien);
															system("pause");
														
															break;
														}
													case 0:
														{
															cout << "Ban chon thoat roi\n";
															system("pause");
															break;
														}
														
													
												}
						}while(luachon1!=0);
					break;
				}
			case 3:
				{
					int luachon1 = 0;
					do{
						
							system("cls");
							MenuQLMonHoc();
							cin >> luachon1;
							cin.ignore();
												switch(luachon1)
												{
													case 1:
														{
															MH_themMH(DS);
															MH_LuuFileMonHoc(DS);
															system("pause");
															break;
														}
													case 2:
														{
															MH_suaMH(DS);
															MH_LuuFileMonHoc(DS);
															system("pause");
															break;
														}
													case 3:
														{
															MH_xoaMH(DS);
															MH_LuuFileMonHoc(DS);
															system("pause");
															break;
														}
													case 4:
														{
															cout << "\t\t\t\t\t\t\tDANH SACH MON HOC\n\n";
															MH_XuatDSMH(DS);
															system("pause");
															break;
														}
													case 0:
														{
															break;
														}
												}
						}while(luachon1!=0);
					break;
				}
			case 4:
				{
						int luachon1 = 0;
					do{
						
							system("cls");
							MenuTinChi();
							cin >> luachon1;
							cin.ignore();
												switch(luachon1)
												{
													case 1:
														{
															char massv[11];
															cout <<"Nhap ma sinh vien: ";
															cin.getline(massv,11);
															nodesinhvien sv;
															strcpy(sv.maSV,massv);
															if(SV_Search(DSsinhvien,sv) == 0)
															{
																cout << "Ma sinh vien vua nhap khong co trong danh sach\n";
																system("pause");
															}
															else
															{
																DKLopTC(root_dsltc,massv);
																LuuFileLTC(root_dsltc);
																system("pause");
															}
															
															
															break;
														}
													case 2:
														{
															chucnangHNhapDiem(DSsinhvien,root_dsltc);
															LuuFileLTC(root_dsltc);
															system("pause");
															break;
														}
													case 3:
														{
															chucnangInbangDiem(DSsinhvien,root_dsltc,DS);
															system("pause");
															break;
														}
													case 4:
														{
															InDiem1LopTheotinChi(DSsinhvien,root_dsltc,DS);
															system("pause");
															break;
														}
													case 0:
														{
															break;
														}
												}
						}while(luachon1!=0);
					
					break;
				}
			
			case 0:
				{
					break;
				}
				
		}
	}while(luachon!=0);
	giaiphong();
	return 0;
}
void MenuTinChi()
{
		cout<<"\t\t\t\t\t\t------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t|            QUAN LY LOP TIN CHI                           |\n";
        cout<<"\t\t\t\t\t\t|      1. Dang ky lop tin chi                              |\n";
        cout<<"\t\t\t\t\t\t|      2. Nhap diem                                        |\n";
        cout<<"\t\t\t\t\t\t|      3. In bang diem mon hoc cua mot lop tin chi         |\n";
        cout<<"\t\t\t\t\t\t|      4. In Diem trung binh cua mot lop hoc               |\n";
    	cout<<"\t\t\t\t\t\t|      0. Thoat                                            |\n";
        cout<<"\t\t\t\t\t\t------------------------------------------------------------\n";
        cout << "\t\t\t\t\t\tLua chon = ";
}
void MenuQLMonHoc()
{
		cout<<"\t\t\t\t\t\t------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t|            QUAN LY MON HOC                               |\n";
        cout<<"\t\t\t\t\t\t|      1. Them mon hoc                                     |\n";
        cout<<"\t\t\t\t\t\t|      2. Sua mon hoc                                      |\n";
        cout<<"\t\t\t\t\t\t|      3. Xoa mon hoc                                      |\n";
        cout<<"\t\t\t\t\t\t|      4. In ds m/hoc tang dan theo ten mon hoc            |\n";
    	cout<<"\t\t\t\t\t\t|      0. Thoat                                            |\n";
        cout<<"\t\t\t\t\t\t------------------------------------------------------------\n";
        cout << "\t\t\t\t\t\tLua chon = ";
}
void MenuQLsinhvien()
{
		cout<<"\t\t\t\t\t\t------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t|            QUAN LY SINH VIEN                             |\n";
        cout<<"\t\t\t\t\t\t|      1. Them sinh vien                                   |\n";
        cout<<"\t\t\t\t\t\t|      2. Sua sinh vien                                    |\n";
        cout<<"\t\t\t\t\t\t|      3. Xoa sinh vien                                    |\n";
        cout<<"\t\t\t\t\t\t|      4. In lop sinh vien theo ma lop                     |\n";
    	cout<<"\t\t\t\t\t\t|      0. Thoat                                            |\n";
        cout<<"\t\t\t\t\t\t------------------------------------------------------------\n";
        cout << "\t\t\t\t\t\tLua chon = ";
}

void MenuQLlopTC()
{
		cout<<"\t\t\t\t\t\t----------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t|            QUAN LY LOP TIN CHI                               |\n";
        cout<<"\t\t\t\t\t\t|      1. Them Lop Tin Chi                                     |\n";
        cout<<"\t\t\t\t\t\t|      2. Sua Lop Tin Chi                                      |\n";
        cout<<"\t\t\t\t\t\t|      3. Xoa Lop Tin Chi                                      |\n";
        cout<<"\t\t\t\t\t\t|      4. D/sach sv dang ky lop tin chi theo nien khoa         |\n";
        cout<<"\t\t\t\t\t\t|      5. D/sach sv dang ky lop tin chi theo hoc ky            |\n";
       	cout<<"\t\t\t\t\t\t|      6. D/sach sv dang ky lop tin chi theo nhom              |\n";
       	cout<<"\t\t\t\t\t\t|      7. D/sach sv dang ky lop tin chi theo ma mon hoc        |\n";
    	cout<<"\t\t\t\t\t\t|      0. Thoat                                                |\n";
        cout<<"\t\t\t\t\t\t----------------------------------------------------------------\n";
         cout << "\t\t\t\t\t\tLua chon = ";
}

void MenuChinh()
{
		cout<<"\t\t\t\t\t\t----------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t|            QUAN LY DIEM SINH VIEN                |\n";
        cout<<"\t\t\t\t\t\t|      1. Quan Ly Lop Tin Chi                      |\n";
        cout<<"\t\t\t\t\t\t|      2. Quan Ly Sinh Vien                        |\n";
        cout<<"\t\t\t\t\t\t|      3. Quan Ly Mon Hoc                          |\n";
        cout<<"\t\t\t\t\t\t|      4. Quan Ly Dang Ki                          |\n";
       	cout<<"\t\t\t\t\t\t|      0. Thoat                                    |\n";
        cout<<"\t\t\t\t\t\t----------------------------------------------------\n";
         cout << "\t\t\t\t\t\tLua chon = ";
}

