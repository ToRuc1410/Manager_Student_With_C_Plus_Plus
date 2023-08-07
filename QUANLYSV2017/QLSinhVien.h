#include <iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
#include <algorithm>
using namespace std;

//danh sach lien ket don
struct nodesinhvien {
	char maSV[11]; 	//ma sinh vien
	char ho[21]; 	//ho sinh vien
	char ten[11];	//ten sinh vien
	char phai[4]; 	// gioi tinh
	char sdt[12]; 	// so dien thoai
	char malop[14]; // ma lop
	int namnhaphoc; // nam nhap hoc
};
struct DSSV {
	nodesinhvien data;
	DSSV *next;
};
typedef DSSV *PTRSV;
// khoi tao danh sach rong
void SV_Init(PTRSV &L);// &L lay dia chi cua danh sach ngay khi truyen vao ham
// kiem tra danh sach rong hay khong
int SV_Isempty (PTRSV L);
int SV_len (PTRSV L);
DSSV *SV_Make_Node (DSSV *P, nodesinhvien x); //tao 1 Node P chua thong tin la x 
// chen node  P vao vi tri dau tien
void SV_Insert_first (PTRSV &L, nodesinhvien x) ; //Chen x vao vi tri dau tien trong danh sach
// chen node p vao vi tri k trong danh sach
void SV_Insert_k (PTRSV &L, nodesinhvien x, int k); //chen x vao vi tri k trong danh sach
int getLenDSSV (PTRSV L); //tim x trong danh sach
// tim phan tu co gia tri X trong danh sach
int SV_Search (PTRSV L, nodesinhvien x); //tim x trong danh sach
// xoa phan tu o vi tri dau tien
void SV_Del_frist (PTRSV &L, nodesinhvien &x); //Xoa phan tu dau tien
// xoa phan tu o vi tri k
void SV_Del_k (PTRSV &L, nodesinhvien &x, int k); //Xoa Node k trong danh sach
// xoa phan tu co gia tri x
void SV_Del_x (PTRSV &L, nodesinhvien x); //xoa phan tu x trong danh sach
void SV_DocDSSVTuFile(PTRSV &DS);
void SV_XuatMotSV(nodesinhvien SV);
void SV_XuatDSSV(PTRSV ds);
void swap(nodesinhvien &a, nodesinhvien &b);
void SV_Sapxep (PTRSV &L) ;
void SV_XuatDSSVtheomalop(PTRSV ds,char malop[]);
void SV_MenuThemSuaXoa();
void SV_NhapSV(PTRSV &ds);
// tim phan tu co gia tri X trong danh sach
nodesinhvien SV_TimSVtuMa (PTRSV L, char maSV[]); //tim x trong danh sach
int SV_NamNhaphoctuMaLop (PTRSV L, char malop[]); //tim x trong danh sach
void SV_LuuFileSV(PTRSV L);
nodesinhvien SV_Bang(nodesinhvien a);
int Demkituchuoi(char str[], int length);
char * chuanhoachuoi(char* a);




//////////////////////////////////MON HOC/////////////////////////////////////
#define ooMH 300

//------Monhoc------ 
//mang con tro
struct NodeMH {
	char mmh[11];	//ma mon hoc
	char tmh[36];	// ten mon hoc
	float stclt;		// so tinh chi li thuyet
	float stcth;		// so tinh chi thuc hanh
};
struct	dsmh {
	int n; // so luong mon hoc
	NodeMH *nodemonhoc[301];//con tro mon hoc
	
};
// ham doi vi tri hai mon hoc chinh la ham swap dung trong sap xep, doi cho
void MH_doivitri2MH(NodeMH &a, NodeMH &b);
// menu quan ly mon hoc
void MH_MenuQuanLyMonHoc();
// ham cap phat bo nho cho mang con tro mon hoc
// dau vao la so mon hoc max
NodeMH *MH_createRecordMH(int nMAX);
// ham nay la ham doc danh sach mon hoc tu file
void MH_DocDSMHTuFile(dsmh &DS);
// Xuat mot mon hoc ra man hinh
void MH_XuatMotMonHoc(NodeMH MH);
// Xuat danh sach mon hoc ra man hinh
void MH_XuatDSMH(dsmh ds);
// ham nay la ham lay so thu tu trong danh sach tu ma mon hoc 
int MH_laysoTTmaMH(dsmh ds, char temp[]);
// ham nay la ham lay vi tri mon hoc trong danh sach mon hoc
int MH_layvitriMH(dsmh ds);
// ham tra ve ten mon hoc tu ma mon hoc nhap vao
char* MH_layvitriMH(dsmh ds, char mmh[]);
// ham them mon hoc
void MH_themMH(dsmh &DS);
// ham sua mon hoc
void MH_suaMH(dsmh &DS);
// ham xoa mon hoc
void MH_xoaMH(dsmh &DS);
// ham luu file mon hoc
void MH_LuuFileMonHoc(dsmh DS);
//////////////////////////////// DANH SACH DANNG KY
//------danh sach dang ki------
//danh sach lien ket don
struct NodeDK {
	char maSV[11]; //ma sinh vien
	float diem; 	//diem
};
struct dsdk {
	NodeDK data;
	dsdk *next;
};
typedef dsdk *PTRDK;
// khoi tao danh sach rong
void DK_Init(PTRDK &L);// &L lay dia chi cua danh sach ngay khi truyen vao ham
// kiem tra danh sach rong hay khong
int DK_Isempty (PTRDK L);
int DK_len (PTRDK L) ;
// tao mot node trong danh sach
dsdk *DK_Make_Node (dsdk *P, NodeDK x); //tao 1 Node P chua thong tin la x
// chen node  P vao vi tri dau tien
void DK_Insert_first (PTRDK &L, NodeDK x);  //Chen x vao vi tri dau tien trong danh sach
// chen node p vao vi tri k trong danh sach
void DK_Insert_k (PTRDK &L, NodeDK x, int k) ;//chen x vao vi tri k trong danh sach
// tim phan tu co gia tri X trong danh sach
int DK_Search (PTRDK L, NodeDK x); //tim x trong danh sach
// xoa phan tu o vi tri dau tien
void DK_Del_frist (PTRDK &L, NodeDK &x); //Xoa phan tu dau tien
// xoa phan tu o vi tri k
void DK_Del_k (PTRDK &L, NodeDK &x, int k); //Xoa Node k trong danh sach
// xoa phan tu co gia tri x
void DK_Del_x (PTRDK &L, NodeDK x); //xoa phan tu x trong danh sach



//////////////////////////////Source code


// khoi tao danh sach rong
void SV_Init(PTRSV &L)// &L lay dia chi cua danh sach ngay khi truyen vao ham
{
	L = NULL;//Cho L tro den NULL
}
// kiem tra danh sach rong hay khong
int SV_Isempty (PTRSV L)
{
    return (L==NULL);
}
// tinh do dai danh sach
int SV_len (PTRSV L) 
{
    DSSV *P=L; //tao 1 Node P de duyet danh sach L
    int i=0; //bien dem
    while (P!=NULL) //trong khi P chua tro den NULL (cuoi danh sach thi lam)
    {
        i++; //tang bien dem
        P=P->next; //cho P tro den Node tiep theo
    }
    return i; //tra lai so Node cua l
}
// tao mot node trong danh sach
DSSV *SV_Make_Node (DSSV *P, nodesinhvien x) //tao 1 Node P chua thong tin la x 
{
    P = (DSSV *) malloc (sizeof (DSSV)); //Cap phat vung nho cho P
    P->next = NULL; //Cho truong Next tro den NULL
    P->data.namnhaphoc = x.namnhaphoc; //Ghi du lieu vao Data
    strcpy(P->data.ho,x.ho);
    strcpy(P->data.malop,x.malop);
    strcpy(P->data.maSV,x.maSV);
    strcpy(P->data.phai,x.phai);
    strcpy(P->data.sdt,x.sdt);
    strcpy(P->data.ten,x.ten);
	return P; 
}
// chen node  P vao vi tri dau tien
void SV_Insert_first (PTRSV &L, nodesinhvien x)  //Chen x vao vi tri dau tien trong danh sach
{
    DSSV *P = NULL; 
    P = SV_Make_Node(P,x); //tao 1 Node P
    P->next = L; //Cho P tro den L
    L = P; //L tro ve P
}
// chen node p vao vi tri k trong danh sach
void SV_Insert_k (PTRSV &L, nodesinhvien x, int k) //chen x vao vi tri k trong danh sach
{
    DSSV *P = NULL, *Q = L; 
    int i=1;
    if (k<1 || k> SV_len(L)+1) printf("Vi tri chen khong hop le !"); //kiem tra dieu kien
    else
    {
        P = SV_Make_Node(P,x); //tao 1 Node P
        if (k == 1) SV_Insert_first(L,x); //chen vao vi tri dau tien
        else //chen vao k != 1
        {
            while (Q != NULL && i != k-1) //duyet den vi tri k-1
            {
                i++;
                Q = Q->next;
            }
            P->next = Q->next; 
            Q->next = P;
        }
    }
}
int getLenDSSV (PTRSV L) //tim x trong danh sach
{
    DSSV *P=L; 
    int i=0;
    while (P != NULL) //duyet danh sach den khi ket thuc danh sach
    {
        P = P->next;
        i++;
    }
    return i; 
    
}
void SV_Travesinhvien (PTRSV L, char masv[], nodesinhvien &x) //tim x trong danh sach
{
    DSSV *P=L; 
    int i=1;
    while (P != NULL ) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
    	if( strcmp(P->data.maSV,masv)==0)
    	{
    		strcmp(x.ho, P->data.ho);
    		strcmp(x.ten, P->data.ten);
    		strcmp(x.malop, P->data.malop);
    		strcmp(x.maSV, P->data.maSV);
    		x.namnhaphoc=P->data.namnhaphoc;
    		strcmp(x.phai, P->data.phai);
    		strcmp(x.sdt, P->data.sdt);
    		SV_XuatMotSV(P->data);
    		//system("pause");
    		return;
		}
        P = P->next;
        
    }
  
}
// tim phan tu co gia tri X trong danh sach
int SV_Search (PTRSV L, nodesinhvien x) //tim x trong danh sach
{
    DSSV *P=L; 
    int i=1;
    while (P != NULL && strcmp(P->data.maSV,x.maSV)!=0) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
        P = P->next;
        i++;
    }
    if (P != NULL) return i; //tra ve vi tri tim thay
    else return 0; //khong tim thay
}
// xoa phan tu o vi tri dau tien
void SV_Del_frist (PTRSV &L, nodesinhvien &x) //Xoa phan tu dau tien
{
    //x = L->Data; //lay gia tri ra neu can dung
    L = L->next; //Cho L tro den Node thu 2 trong danh sach
}
// xoa phan tu o vi tri k
void SV_Del_k (PTRSV &L, nodesinhvien &x, int k) //Xoa Node k trong danh sach
{
    DSSV *P=L;
    int i=1;
    if (k<1 || k>SV_len(L)) printf("Canh Bao!!!!Vi tri xoa khong hop le !"); //kiem tra dieu kien
    else
    {
        if (k==1) SV_Del_frist(L,x); //xoa vi tri dau tien
        else //xoa vi tri k != 1
        {
            while (P != NULL && i != k-1) //duyet den vi tri k-1
            {
                P=P->next;
                i++;
            }
            P->next = P->next->next; //cho P tro sang Node ke tiep vi tri k
        }
    }
}
// xoa phan tu co gia tri x
void SV_Del_x (PTRSV &L, nodesinhvien x) //xoa phan tu x trong danh sach
{
    while (SV_Search(L,x)) SV_Del_k (L,x,SV_Search(L,x)); //trong khi van tim thay x thi van xoa
}

void SV_DocDSSVTuFile(PTRSV &DS)
{

	int n;
	char temp[50];
	ifstream file;
	file.open("DSSV.txt");
	if(file.fail())
	{
		cout << "Canh bao!!! Loi trong qua trinh mo file " << endl;
		return ;
	}
	nodesinhvien x;
	file >> n;
	file.ignore();
	//cout << n <<endl;
	
	//cout << DS.n<<endl;
	file.getline(temp,50); // doc dong xuong dong
	//cout << temp<<endl;
	for(int i = 0;i<n; i++)
	{
		file.getline(x.maSV,11); 
		file.getline(x.ho,21);
		file.getline(x.ten,11);
		file.getline(x.phai,4);
		file.getline(x.sdt,12);
		file.getline(x.malop,14);
		file >> x.namnhaphoc;
		file.ignore();
		file.getline(temp,50);
		SV_Insert_first(DS,x);
	}

	
	file.close();
}

void SV_XuatMotSV(nodesinhvien SV)
{
	
	printf("%20s%20s%20s%20s%20s%20s%20d\n",SV.maSV,SV.ho,SV.ten,SV.phai,SV.sdt,SV.malop,SV.namnhaphoc);
}
void SV_XuatDSSV(PTRSV ds)
{
	int n = SV_len(ds);
	if(n == 0)
	{
		cout << "Chuong trinh thong bao!!!Khong co sinh vien nao trong danh sach\n";
		return;
	}
	printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
	DSSV *P=ds; //tao 1 Node P de duyet danh sach L
    int i=0; //bien dem
    while (P!=NULL) //trong khi P chua tro den NULL (cuoi danh sach thi lam)
    {
        SV_XuatMotSV(P->data);
        P=P->next; //cho P tro den Node tiep theo
    }
   
}
void SV_XuatDSSVkhongkihieu(PTRSV ds)
{
	int n = SV_len(ds);
	if(n == 0)
	{
		cout << "Chuong trinh thong bao!!!Khong co sinh vien nao trong danh sach\n";
		return;
	}
	//printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
	DSSV *P=ds; //tao 1 Node P de duyet danh sach L
    int i=0; //bien dem
    while (P!=NULL) //trong khi P chua tro den NULL (cuoi danh sach thi lam)
    {
        SV_XuatMotSV(P->data);
        P=P->next; //cho P tro den Node tiep theo
    }
   
}
nodesinhvien SV_Bang(nodesinhvien a)
{
	nodesinhvien c;
	strcpy(c.ho,a.ho);
	strcpy(c.malop,a.malop);
	strcpy(c.maSV,a.maSV);
	strcpy(c.phai,a.phai);
	strcpy(c.sdt,a.sdt);
	strcpy(c.ten,a.ten);
	c.namnhaphoc = a.namnhaphoc;
	return c;
}
void swap(nodesinhvien &a, nodesinhvien &b)
{
	nodesinhvien c;
	c = SV_Bang(a);
	a = SV_Bang(b);
	b = SV_Bang(c);
}
void SV_Sapxep (PTRSV &L) 
{
    DSSV *P=L,*H; 
    
    while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
    	H=P->next;
    	while(H!=NULL)
    	{
    		if(strcmp(P->data.maSV,H->data.maSV)>0)
    		{
    			swap(P->data,H->data);
			}
			H=H->next;
		}
        P = P->next;
        
    }
    
}
void SV_XuatDSSVtheomalop(PTRSV ds,char malop[])
{
	int n = SV_len(ds);
	if(n == 0)
	{
		cout << "Khong co sinh vien nao trong danh sach\n";
		return;
	}
	SV_Sapxep(ds);
	printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
	DSSV *P=ds; //tao 1 Node P de duyet danh sach L
    int i=0; //bien dem
    while (P!=NULL) //trong khi P chua tro den NULL (cuoi danh sach thi lam)
    {
    	//cout << malop << "   " << P->data.malop<<endl;
    	if(strcmp(malop,P->data.malop)==0)
        	SV_XuatMotSV(P->data);
        P=P->next; //cho P tro den Node tiep theo
    }
   
}
void SV_XuatDSSVnienkhoa(PTRSV ds,char nienkhoa[])
{
	int n = SV_len(ds);
	if(n == 0)
	{
		cout << "Khong co sinh vien nao trong danh sach\n";
		return;
	}
	SV_Sapxep(ds);
	printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
	DSSV *P=ds; //tao 1 Node P de duyet danh sach L
    int i=0; //bien dem
    while (P!=NULL) //trong khi P chua tro den NULL (cuoi danh sach thi lam)
    {
    	//cout << malop << "   " << P->data.malop<<endl;
    	if(nienkhoa,P->data.namnhaphoc ==0)
        	SV_XuatMotSV(P->data);
        P=P->next; //cho P tro den Node tiep theo
    }
   
}
void SV_MenuThemSuaXoa()
{
		cout<<"--------------------------------------------------\n";
        cout<<"|          LUA CHON QUAN LY SINH VIEN            |\n";
        cout<<"|      1. Them sinh vien                         |\n";
        cout<<"|      2. Sua sinh vien                          |\n";
        cout<<"|      3. Xoa sinh vien                          |\n";
		cout<<"|      4. thoat                                  |\n";
        cout<<"--------------------------------------------------\n";
        cout<< "Ban chon = ";
}
void SV_SuaTTSV(PTRSV &ds)
{
	nodesinhvien sv;
	cout << "\t=> Vui long Nhap ma so SV: ";
	cin.getline(sv.maSV,11);
	if(SV_Search(ds,sv) ==0)
	{
		cout << "Khong tim thay ma sinh vien trong danh sach!!!\n";
		return;
	}
			
	DSSV *P=ds; 
    
    while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
    	
    	if( strcmp(P->data.maSV,sv.maSV)==0)
    	{
    		char c, temp[14];
			do{
				printf("Ban muon sua ho(ten lot)(c:co, k: khong):");
				cin.getline(temp,14);
				c = temp[0];
			}while(!(c=='c'|| c=='k'));
			if(c=='c')
			{
				cout << ("Nhap ho (ten lot): ");
				cin.getline(P->data.ho,21);
			}
			
			do{
				printf("Ban muon sua ten(c:co, k: khong):");
				cin.getline(temp,14);
				c = temp[0];
			}while(!(c=='c'|| c=='k'));
			if(c=='c')
			{
				cout << ("Nhap ten: ");
				cin.getline(P->data.ten,11);
			}
			do{
				printf("Ban muon sua gioi tinh(c:co, k: khong):");
				cin.getline(temp,14);
				c = temp[0];
			}while(!(c=='c'|| c=='k'));
			if(c=='c')
			{
				cout << ("Nhap gioi tinh: ");
				cin.getline(P->data.phai,4);
			}
			do{
				printf("Ban muon sua so dien thoai(c:co, k: khong):");
				cin.getline(temp,14);
				c = temp[0];
			}while(!(c=='c'|| c=='k'));
			if(c=='c')
			{
				cout << ("Nhap ten: ");
				cin.getline(P->data.sdt,12);
			}
			do{
				printf("Ban muon sua nam nhap hoc(c:co, k: khong):");
				cin.getline(temp,14);
				c = temp[0];
			}while(!(c=='c'|| c=='k'));
			if(c=='c')
			{
				cout << ("Nhap nam nhap hoc: ");
				cin >> P->data.namnhaphoc;
				cin.ignore();
			}
    		return;
		}
    	
        P = P->next;
        
    }
   
}
void SV_XoaTTSV(PTRSV &ds)
{
	nodesinhvien sv;
	cout << "\t=> Vui long Nhap ma so SV: ";
	cin.getline(sv.maSV,11);
	if(SV_Search(ds,sv) ==0)
	{
		cout << "Khong tim thay ma sinh vien trong danh sach!!!\n";
		return;
	}
	SV_Del_x(ds,sv);
	cout << "Xoa thanh cong!!!\n";
}
void SV_NhapSV(PTRSV &ds)
{
	char temp[14];
	char malop[14];
	int chon;
	nodesinhvien sv[50];
	cout << "\t=> Vui long Nhap ma lop: ";
	cin.getline(malop,14);
	int kitu = 0;
	int i = 0;
	while(1)
	{
		strcpy(sv[i].malop,malop);
		cout << "\t=> Vui long Nhap ma so SV: ";
		cin.getline(sv[i].maSV,11);
		
		kitu = Demkituchuoi(sv[i].maSV,strlen(sv[i].maSV));
		//cout << "ki tu = "<<kitu<<endl;
		//cout << "ki tu = " <<kitu<<endl;
		if(kitu==0)
		{
			cout << "Thong bao...Ket thuc qua trinh nhap sinh vien\n";
			return;
		}
		cout << "\t=> Vui long Nhap ho (ten lot): ";
		
		char ho[21];
		cin.getline(ho,21);
		char *t_ho = chuanhoachuoi(ho);
		t_ho[strlen(ho)] = '\0';
		strcpy(sv[i].ho,t_ho);
		
		cout << "\t=> Vui long Nhap ten: ";
		char ten[11];
		cin.getline(ten,11);
		char* t_ten= chuanhoachuoi(ten);
		t_ten[strlen(ten)] = '\0';
		strcpy(sv[i].ten,t_ten); 
		
		cout << "\t=> Vui long Nhap gioi tinh: ";
		char phai[4];
		cin.getline(phai,4);
		char* t_phai = chuanhoachuoi(phai);
		t_phai[strlen(phai)] = '\0';
		strcpy(sv[i].phai,t_phai);
		cout << "\t=> Vui long Nhap so dien thoai: ";
		cin.getline(sv[i].sdt,12);
		cout << "\t=> Vui long Nhap nam nhap hoc: ";
		cin >> sv[i].namnhaphoc;
		
		cin.ignore();
		system("cls");
		cout << "Ma lop: " << malop<<endl;
		printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
		for(int j = 0; j <=i; j++)
			SV_XuatMotSV(sv[j]);
		SV_MenuThemSuaXoa();
		cin >> chon;
		cin.ignore();
		if(chon == 2)
		{
			char c;
			do{
				printf("Ban muon sua ho(ten lot)(c:co, k: khong):");
				cin.getline(temp,14);
				c = temp[0];
			}while(!(c=='c'|| c=='k'));
			if(c=='c')
			{
				cout << ("Nhap ho (ten lot): ");
				cin.getline(sv[i].ho,21);
			}
			
			do{
				printf("Ban muon sua ten(c:co, k: khong):");
				cin.getline(temp,14);
				c = temp[0];
			}while(!(c=='c'|| c=='k'));
			if(c=='c')
			{
				cout << ("Nhap ten: ");
				cin.getline(sv[i].ten,11);
			}
			do{
				printf("Ban muon sua gioi tinh(c:co, k: khong):");
				cin.getline(temp,14);
				c = temp[0];
			}while(!(c=='c'|| c=='k'));
			if(c=='c')
			{
				cout << ("Nhap gioi tinh: ");
				cin.getline(sv[i].phai,4);
			}
			do{
				printf("Ban muon sua so dien thoai(c:co, k: khong):");
				cin.getline(temp,14);
				c = temp[0];
			}while(!(c=='c'|| c=='k'));
			if(c=='c')
			{
				cout << ("Nhap ten: ");
				cin.getline(sv[i].sdt,12);
			}
			do{
				printf("Ban muon sua nam nhap hoc(c:co, k: khong):");
				cin.getline(temp,14);
				c = temp[0];
			}while(!(c=='c'|| c=='k'));
			if(c=='c')
			{
				cout << ("Nhap nam nhap hoc: ");
				cin >> sv[i].namnhaphoc;
				cin.ignore();
			}
			
			SV_Insert_first(ds,sv[i]);
			i++;
		}
		else if(chon ==3)
		{
			system("cls");
			cout << "Ma lop: " << malop<<endl;
			printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
			for(int j = 0; j <i; j++)
				SV_XuatMotSV(sv[j]);
		}
		else if (chon == 4)
		{
			cout << "Thong bao...Ket thuc qua trinh nhap sinh vien\n";
			return;
		}
		else
		{
			SV_Insert_first(ds,sv[i]);
			i++;
		}
		
	}
}
// tim phan tu co gia tri X trong danh sach
nodesinhvien SV_TimSVtuMa (PTRSV L, char maSV[]) //tim x trong danh sach
{
	nodesinhvien sv;
	strcpy(sv.malop, "");
    DSSV *P=L; 
    int i=1;
    while (P != NULL && strcmp(P->data.maSV,maSV)!=0) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
        P = P->next;
        i++;
    }
    if (P != NULL) return P->data; //tra ve vi tri tim thay
    else return sv; //khong tim thay
}
int SV_NamNhaphoctuMaLop (PTRSV L, char malop[]) //tim x trong danh sach
{
    DSSV *P=L; 
    int i=1;
    while (P != NULL && strcmp(P->data.malop,malop)!=0) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
        P = P->next;
        i++;
    }
    if (P != NULL) return P->data.namnhaphoc; //tra ve vi tri tim thay
    else return 0; //khong tim thay
}
void SV_LuuFileSV(PTRSV L)
{
	int n = getLenDSSV(L);
	
	ofstream out;
	out.open("DSSV.txt");
	out<<n<<endl;
	out<<"------------------------------------------------"<<endl;
	
	DSSV *P=L; 
    
    while (P != NULL) //duyet danh sach den khi ket thuc danh sach
    {
    	out<<P->data.maSV<<endl;
        out<<P->data.ho<<endl;
        out<<P->data.ten<<endl;
        out<<P->data.phai<<endl;
        out<<P->data.sdt<<endl;
        out<<P->data.malop<<endl;
        out<<P->data.namnhaphoc<<endl;
        out<<"------------------------------------------------"<<endl;
        P = P->next;
        
    }
	
	out.close();
}



//////////////////////////////////MON HOC/////////////////////////////////

void MH_MenuQuanLyMonHoc()
{
		cout<<"-------------------------------------------------------\n";
        cout<<"|            MENU QUAN LY MON HOC                     |\n";
        cout<<"|      1. Xem danh sach tat ca mon hoc                |\n";
        cout<<"|      2. Them mon hoc moi                            |\n";
        cout<<"|      3. Sua thong tin mon hoc                       |\n";
        cout<<"|      4. Xoa mon hoc                                 |\n";
        cout<<"|      5. In danh sach mon hoc tang dan theo ten MH   |\n";
        cout<<"|      0. Xoa mon hoc                                 |\n";
        cout<<"-------------------------------------------------------\n";
        cout << "Ban chon la: ";
        
}


NodeMH *MH_createRecordMH(int nMAX){
    struct NodeMH *MH;
    MH = new NodeMH[nMAX];
    return MH;
}

void MH_DocDSMHTuFile(dsmh &DS)
{
	char temp[11];
	char tenmh[36];
	float tc;
	ifstream file;
	file.open("DSMH.txt");
	if(file.fail())
	{
		cout << " Loi trong qua trinh mo file " << endl;
		return ;
	}
	file >> DS.n;
	//cout << DS.n<<endl;
	file.ignore();
	for(int i = 0;i<DS.n; i++)
	{
		
		file.getline(temp,11); strcpy(DS.nodemonhoc[i]->mmh,temp); //cout << DS.nodemonhoc[i].mmh <<endl;
		file.getline(tenmh,36); strcpy(DS.nodemonhoc[i]->tmh,tenmh);//cout << DS.nodemonhoc[i].tmh<<endl;
		file >> tc; DS.nodemonhoc[i]->stclt = tc; //cout << DS.nodemonhoc[i].stclt <<endl;
		file>>tc; DS.nodemonhoc[i]->stcth = tc;//cout << DS.nodemonhoc[i].stcth <<endl;
		file.ignore();
		//cout << DS.nodemonhoc[i]->mmh <<endl;
	
		
	}

	
	file.close();
}


void MH_XuatMotMonHoc(NodeMH MH)
{
	
	printf("%20s%35s%20.1f%20.1f\n",MH.mmh,MH.tmh,MH.stclt,MH.stcth);
}
void MH_XuatDSMH(dsmh ds)
{
	if(ds.n == 0)
	{
		cout << "Khong co mon hoc nao trong danh sach\n";
		return;
	}
	//sap xep noi bot
	for(int i = 0; i < ds.n;i++)
	{
		for(int j = i+1; j<ds.n; j++)
		{
			if(strcmp(ds.nodemonhoc[i]->tmh,ds.nodemonhoc[j]->tmh)>0)
			{
				MH_doivitri2MH(*ds.nodemonhoc[i],*ds.nodemonhoc[j]);
			}
		}
	}	
	printf("%20s%35s%20s%20s\n","Ma MH","Ten MH","TC ly thuyet","TC thuc hanh");
	for(int i = 0; i < ds.n; i++)
	{
		
		MH_XuatMotMonHoc(*ds.nodemonhoc[i]);
		
	}
}
int MH_laysoTTmaMH(dsmh ds, char temp[])
{
	
	
	int vt = -1;
	for(int i = 0; i < ds.n; i++)
		{
			if(strcmp(temp,ds.nodemonhoc[i]->mmh)==0)
			{
				vt = i;
			}
		}
	if(vt >=ds.n) vt = -1;
	return vt;
}
int MH_layvitriMH(dsmh ds)
{
	
	char temp[12];
	cout << ("Nhap ma MH: ");
	cin.getline(temp,12);
	int vt = -1;
	for(int i = 0; i < ds.n; i++)
		{
			if(strcmp(temp,ds.nodemonhoc[i]->mmh)==0)
			{
				vt = i;
			}
		}
	if(vt >=ds.n) vt = -1;
	return vt;
}

char* MH_layvitriMH(dsmh ds, char mmh[])
{
	

	
	for(int i = 0; i < ds.n; i++)
		{
			if(strcmp(ds.nodemonhoc[i]->mmh,mmh)==0)
			{
				return ds.nodemonhoc[i]->tmh;
			}
		}
	return (char*)("");
}
NodeMH MHBang(NodeMH a)
{
	NodeMH c;
	//c<-a
	strcpy(c.mmh,a.mmh);
	strcpy(c.tmh,a.tmh);
	c.stclt = a.stclt;
	c.stcth = a.stcth;
	return c;
}
void MH_doivitri2MH(NodeMH &a, NodeMH &b)
{
	NodeMH c;
	//c<-a
	c = MHBang(a);
	a = MHBang(b);
	b = MHBang(c);
}
void MH_themMH(dsmh &DS)
{
	// thêm vào vi tri n
	// n se tang len 1 don vi
	int i = DS.n;
	char temp[12];
	int vt=0;
	do{
		
		cout << "Nhap ma mon hoc: ";
		cin.getline(DS.nodemonhoc[i]->mmh,12);
		vt =MH_laysoTTmaMH(DS,DS.nodemonhoc[i]->mmh);
		if(vt!=-1)
		{
			cout << "Ma MH da ton tai\n";
				
		}
	}while(vt!=-1);
		
	
		
		// ten mon hoc
		cout << "Nhap ten mon hoc: ";
		cin.getline(DS.nodemonhoc[i]->tmh,36);
		
		cout << "Nhap tin chi ly thuyet: ";
		cin >> DS.nodemonhoc[i]->stclt;
		
		cout << "Nhap tin chi thuc hanh: ";
		cin >> DS.nodemonhoc[i]->stcth;
		
		cin.ignore();
		DS.n++; // tanng so luong len
}
void MH_suaMH(dsmh &DS)
{
	// láy vi tri trong danh sach
	   int vt = MH_layvitriMH(DS);
	   char temp[2];
		if(vt == -1)
		{
			cout << ("Kiem tra thong tin nhap vao!\n");
			return;
		}
		int i = vt;
		
		char c;
		do{
			cout <<("Ban muon sua ten mon hoc(c:co, k: khong):");
			cin.getline(temp,2);
			c = temp[0];
		}while(!(c=='c'|| c=='k'));
		if(c=='c')
		{
		// doc ten mon hoc
			cout << ("\t>Nhap ten mon hoc moi: ");
			cin.getline(DS.nodemonhoc[i]->tmh,36);
		}
		
		do{
			cout <<("Ban muon sua so tin chi ly thuyet(c:co, k: khong):");
			cin.getline(temp,2);
			c = temp[0];
		}while(!(c=='c'|| c=='k'));
		if(c=='c')
		{
		// tin chi ly thuyet
			cout << ("\t>Nhap so tin chi ly thuyet: ");
			cin >> DS.nodemonhoc[i]->stclt;
			cin.ignore();
		}
		do{
			cout <<("Ban muon sua so tin chi thuc hanh(c:co, k: khong):");
			cin.getline(temp,2);
			c = temp[0];
		}while(!(c=='c'|| c=='k'));
		if(c=='c')
		{
		// tin chi ly thuyet
			cout << ("\t>Nhap so tin chi thuc hanh: ");
			cin >> DS.nodemonhoc[i]->stcth;
		}
}
void MH_xoaMH(dsmh &DS)
{
	// trong ham lay vi tri co nhap ma mat hang
	int vt = MH_layvitriMH(DS);

	if(vt == -1)
	{
		cout << ("Khong co mon hoc trong danh sach\n");
		return;
	}
	
	while(vt<DS.n-1)
	{
		MH_doivitri2MH(*DS.nodemonhoc[vt],*DS.nodemonhoc[vt+1]);
		vt++;
	}
	DS.n=DS.n-1;
	free(DS.nodemonhoc[DS.n]); 
	cout << ("Da xoa thanh cong!!!!\n");
}
void MH_LuuFileMonHoc(dsmh DS)
{
		ofstream out;
		out.open("DSMH.txt");
		out<<DS.n<<endl;
		for(int i = 0; i < DS.n; i++)
		{
			out << DS.nodemonhoc[i]->mmh<<endl <<DS.nodemonhoc[i]->tmh<<endl<<DS.nodemonhoc[i]->stclt<<endl<<DS.nodemonhoc[i]->stcth<<endl;
		}
		out.close();
}


////////////////////////////////////////////DANH SACH DANG KY////////////////////////////////////////////////////////////
// khoi tao danh sach rong
void DK_Init(PTRDK &L)// &L lay dia chi cua danh sach ngay khi truyen vao ham
{
	L = NULL;//Cho L tro den NULL
}
// kiem tra danh sach rong hay khong
int DK_Isempty (PTRDK L)
{
    return (L==NULL);
}
// tinh do dai danh sach
int DK_len (PTRDK L) 
{
    dsdk *P=L; //tao 1 Node P de duyet danh sach L
    int i=0; //bien dem
    while (P!=NULL) //trong khi P chua tro den NULL (cuoi danh sach thi lam)
    {
        i++; //tang bien dem
        P=P->next; //cho P tro den Node tiep theo
    }
    return i; //tra lai so Node cua l
}
// tao mot node trong danh sach
dsdk *DK_Make_Node (dsdk *P, NodeDK x) //tao 1 Node P chua thong tin la x 
{
    P = (dsdk *) malloc (sizeof (dsdk)); //Cap phat vung nho cho P
    P->next = NULL; //Cho truong Next tro den NULL
    P->data.diem = x.diem; //Ghi du lieu vao Data
    strcpy(P->data.maSV,x.maSV);
  
	return P; 
}
// chen node  P vao vi tri dau tien
void DK_Insert_first (PTRDK &L, NodeDK x)  //Chen x vao vi tri dau tien trong danh sach
{
    dsdk *P = NULL; 
    P = DK_Make_Node(P,x); //tao 1 Node P
    P->next = L; //Cho P tro den L
    L = P; //L tro ve P
}
// chen node p vao vi tri k trong danh sach
void DK_Insert_k (PTRDK &L, NodeDK x, int k) //chen x vao vi tri k trong danh sach
{
    dsdk *P=NULL, *Q = L; 
    int i=1;
    if (k<1 || k> DK_len(L)+1) printf("Vi tri chen khong hop le !"); //kiem tra dieu kien
    else
    {
        P = DK_Make_Node(P,x); //tao 1 Node P
        if (k == 1) DK_Insert_first(L,x); //chen vao vi tri dau tien
        else //chen vao k != 1
        {
            while (Q != NULL && i != k-1) //duyet den vi tri k-1
            {
                i++;
                Q = Q->next;
            }
            P->next = Q->next; 
            Q->next = P;
        }
    }
}
// tim phan tu co gia tri X trong danh sach
int DK_Search (PTRDK L, NodeDK x) //tim x trong danh sach
{
    dsdk *P=L; 
    int i=1;
    while (P != NULL && strcmp(P->data.maSV,x.maSV)!=0) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
        P = P->next;
        i++;
    }
    if (P != NULL) return i; //tra ve vi tri tim thay
    else return 0; //khong tim thay
}
// xoa phan tu o vi tri dau tien
void DK_Del_frist (PTRDK &L, NodeDK &x) //Xoa phan tu dau tien
{
    //x = L->Data; //lay gia tri ra neu can dung
    L = L->next; //Cho L tro den Node thu 2 trong danh sach
}
// xoa phan tu o vi tri k
void DK_Del_k (PTRDK &L, NodeDK &x, int k) //Xoa Node k trong danh sach
{
    dsdk *P=L;
    int i=1;
    if (k<1 || k>DK_len(L)) printf("Vi tri xoa khong hop le !"); //kiem tra dieu kien
    else
    {
        if (k==1) DK_Del_frist(L,x); //xoa vi tri dau tien
        else //xoa vi tri k != 1
        {
            while (P != NULL && i != k-1) //duyet den vi tri k-1
            {
                P=P->next;
                i++;
            }
            P->next = P->next->next; //cho P tro sang Node ke tiep vi tri k
        }
    }
}
// xoa phan tu co gia tri x
void DK_Del_x (PTRDK &L, NodeDK x) //xoa phan tu x trong danh sach
{
    while (DK_Search(L,x)) DK_Del_k (L,x,DK_Search(L,x)); //trong khi van tim thay x thi van xoa
}

///////////////////////////////HAM HO TRO THEM/////////////////////////////
int Demkituchuoi(char str[], int length)
{
	if(str==NULL) return 0;
    int first = 0, last = length - 1;
    // xoa dau trang dau chuoi
    while (first < last && str[first] == ' ')
        first++;
    // xoa dau trang cuoi chuoi
    while (last > first && str[last] == ' ')
        last--;
    int k = 0;
    
 	for (int i = first ; i <last; i++)
    {
    	k++;
    }
   return k;
}
char* chuanhoachuoi(char* a)
{
	int batdau,ketthuc,end ,i;
	
	//tao bien bat dau va ket thuc
	for(i=0;i<strlen(a);i++) if(a[i]!=' ') 
	{ 
		batdau=i; 
		break; 
	} 
	for(i=strlen(a)-1;i>=0;i--)
		if(a[i]!=' ')
		{
			ketthuc=i;
			break;
		}
	//xoa trang phan giua
	int xoa=0, j;
	end=ketthuc;
	for(i=batdau+1;i<=end;i++)
	if(a[i]==' ' && a[i-1]==' ')
	{
		for(j=i;j<=end;j++)
			a[j]=a[j+1];
		i--;
		end--;
		xoa++;
	}
	char* ketqua;
	ketqua = new char[ketthuc-xoa-batdau+1];
	for(i=batdau;i<=ketthuc-xoa;i++)
	{
		ketqua[i-batdau] = a[i];
	}
	ketqua[strlen(ketqua)] = '\0';
	//std::cout <<strlen(ketqua) <<std::endl;
	for(int i = 0; i < strlen(ketqua); i++)
	{
		if(ketqua[i] >= 'a' && ketqua[i]<='z')
			ketqua[i] = ketqua[i]-32;
	}
	ketqua[strlen(ketqua)] = '\0';
	return ketqua;
}
