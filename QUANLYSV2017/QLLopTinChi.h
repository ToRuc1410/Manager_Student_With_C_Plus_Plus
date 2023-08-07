#include <algorithm>
#include <cstdlib> 
#include <ctime> 
#include "QLSinhVien.h"
using namespace std;

struct Ltc {
	int  malopTc; 		//ma lop
	char mmh[11];		//ma mon hoc
	char nienkhoa[5];		// nien khoa
	char  hocki[2]; 		// hoc ki
	char  nhom[2]; 			//nhom
	int  nsvmax;
	int nsvmin;
	PTRDK DSDK = NULL;
};
struct	Dslop {
	Ltc data;
	Dslop *left;
	Dslop *right;
};
void updateLTC(Dslop* root, int malop, NodeDK sv);
void Free( Dslop* root );
int LeftOf( const Ltc value, const Dslop* root );
int RightOf( const Ltc value, const Dslop* root );
Dslop* Insert( Dslop* root, const Ltc value );
bool Search( const Dslop* root, Ltc value );
Ltc LeftMostValue( const Dslop* root );
Dslop* Delete( Dslop* root, Ltc value );
void PreOrder(Dslop* root);
void InOrder(Dslop* root);
void PostOrder(Dslop* root);
Dslop* DocDSLTCTuFile(Dslop* root);
void XuatMotLopTC(Ltc lop);
void InDSLopTCPost(Dslop* root);
void InDSLopTC(Dslop* root);
void Post_MMH(Dslop* root,PTRSV L, char mamonhoc[]);
void InDSLopTC_MMH(Dslop* root,PTRSV L, char mamonhoc[]);
void Post_Nhom(Dslop* root, PTRSV L,char nhom[]);
void InDSLopTC_Nhom(Dslop* root, PTRSV L,char nhom[]);
void Post_HK(Dslop* root, PTRSV L, char hocky[]);
void InDSLopTC_HK(Dslop* root,PTRSV L, char hocky[]);
void Post_nienkhoa(Dslop* root,PTRSV L, char nienkhoa[]);
void InDSLopTC_nienkhoa(Dslop* root,PTRSV L, char nienkhoa[]);
void Post_nienkhoahocky(Dslop* root, char nienkhoa[],char hocky[]);
int kiemtra_nienkhoahocky(Dslop* root, char nienkhoa[],char hocky[], int chon);
void InDSLopTC_nienkhoahocky(Dslop* root, char nienkhoa[],char hocky[]);
int sinhsongaunhien(Dslop* root,Ltc &lop);
Dslop* ThemLTC(Dslop* root);
Dslop* XoaLTC(Dslop* root);
void SuaLTC(  Dslop* &root, int maloptc );
// ham nay tra ve la chuoi ma lop dang ky
void DKLopTC(Dslop* root,char mssv[]);
void updateLTC(Dslop* root, int malop, NodeDK sv);
//User nh?p vào niên khóa, h?c k?, nhóm , môn h?c
// in danh sach lop tin chi theo hoc ky
void XuatMotDongCauH(Ltc loptc,PTRSV listSV);
void XuatMotDongCauH2(Ltc &loptc,PTRSV listSV);
// ham nay ho tro in bang diem ra man hinh
void Post_Inbangdiemmonhoc(Dslop* root,PTRSV listSV, dsmh dsMH, char hocky[], char nhom[], char nienkhoa[], char mmh[]);
// xuat file bang diem mon hoc cua sinh vien
void XuatFile_bangdiemmonhoc(Dslop* root,PTRSV listSV, dsmh dsMH, char hocky[], char nhom[], char nienkhoa[], char mmh[]);
// ham nay xuat danh sach sinh vien co diem theo nhom, nien khoa, ma mon hoc
void Post_cauH2(Dslop* root,PTRSV listSV, char hocky[], char nhom[], char nienkhoa[], char mmh[]);
// chuc nang in bang diem cho sinh vien
void chucnangInbangDiem(PTRSV listSV, Dslop* root, dsmh dsMH);
// chuc nang nhap diem cho sinh vien
void chucnangHNhapDiem(PTRSV listSV, Dslop* root);
// tim kiem sinh vien
void SearchSinhVien( const Dslop* root,PTRSV listSV,dsmh dsMH, char masinhvien[14], float &tongdiem, float &hesochia );
// xuat ra file diem cua 1 lop tin chi
void XuatFileDiem1LopTheotinChi(PTRSV listSV, Dslop* root,dsmh dsMH,char malop[14]);
// In ra diem cua 1 lop tin chi
void InDiem1LopTheotinChi(PTRSV listSV, Dslop* root,dsmh dsMH);
// lay do dai danh sach lop tin chi tra ve la do dai cua danh sacch
void LenDSLopTC(Dslop* root, int &ncount);
ofstream out1;
void XuatFile(Dslop* root, int n);

void LuuFileLTC(Dslop* root);




void Free( Dslop* root )
{
    if ( root == NULL )
        return;
 
    Free( root->left );
    Free( root->right );
    free( root );
}
 int LeftOf( const Ltc value, const Dslop* root )
{
    // N?u b?n mu?n cây BST cho phép giá tr? trùng l?p, hãy s? d?ng dòng code th? 2
    return value.malopTc < root->data.malopTc;
//    return value <= root->data;
}
int RightOf( const Ltc value, const Dslop* root )
{
    // N?u b?n mu?n cây BST cho phép giá tr? trùng l?p, hãy s? d?ng dòng code th? 2
    return value.malopTc > root->data.malopTc;
//    return value <= root->data;
}
Dslop* Insert( Dslop* root, const Ltc value )
{
    if ( root == NULL )
    {
        Dslop* node = (Dslop*)malloc( sizeof( Dslop ) );
        node->left = NULL;
        node->right = NULL;
        
        node->data.malopTc = value.malopTc;
        node->data.nsvmax = value.nsvmax;
        node->data.nsvmin = value.nsvmin;
        strcpy(node->data.hocki,value.hocki);
        strcpy(node->data.mmh,value.mmh);
        strcpy(node->data.nhom,value.nhom);
        strcpy(node->data.nienkhoa,value.nienkhoa);
        node->data.DSDK=value.DSDK;
        
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}
bool Search( const Dslop* root, Ltc value )
{
    if ( root == NULL )
        return false;
    if(root->data.malopTc == value.malopTc){
        return true;
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
        return Search( root->right, value );
    }
}

Ltc LeftMostValue( const Dslop* root )
{
    while ( root->left != NULL )
        root = root->left;
    return root->data;
}

Dslop* Delete( Dslop* root, Ltc value )
{
    if ( root == NULL )
        return root;
    if ( LeftOf( value, root ) )
        root->left = Delete( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Delete( root->right, value );
    else
    {
        // root->data == value, delete this node
        if ( root->left == NULL )
        {
            Dslop* newRoot = root->right;
            free( root );
            return newRoot;
        }
        if ( root->right == NULL )
        {
            Dslop* newRoot = root->left;
            free( root );
            return newRoot;
        }
        root->data = LeftMostValue( root->right );
        root->right = Delete( root->right, root->data );
    }
    return root;
}
void PreOrder(Dslop* root){
    if(root != NULL)
    {
        printf("%d\n", root->data.malopTc);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void InOrder(Dslop* root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data.malopTc);
        InOrder(root->right);
    }
}
void PostOrder(Dslop* root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data.malopTc);
    }
}

Dslop* DocDSLTCTuFile(Dslop* root)
{

	int n;
	char temp[50];
	ifstream file;
	file.open("DSLTC.txt");
	if(file.fail())
	{
		cout << " Loi trong qua trinh mo file " << endl;
		return root;
	}
	Ltc x;
	int ssv;
	string s;
	
	
	file >> n;
	file.ignore();
//	cout << n <<endl;
	
	//cout << DS.n<<endl;
	file.getline(temp,50); // doc dong xuong dong 
	
	//cout << temp<<endl;
	for(int i = 0;i<n; i++)
	{
		file >> x.malopTc; //cout << x.malopTc <<endl;
		file.ignore();
		file.getline(x.mmh,11);  //cout << x.mmh <<endl;
		file.getline(x.nienkhoa,5);//cout << x.nienkhoa <<endl;
		file.getline(x.hocki,2);//cout << x.hocki <<endl;
		file.getline(x.nhom,2);//cout << x.nhom <<endl;
		file >> x.nsvmax;//cout //<< x.nsvmax <<endl;
		file >> x.nsvmin;//cout << x.nsvmin <<endl;
		file >> ssv; //cout << ssv<<endl;
		file.ignore();
		DK_Init(x.DSDK);
		for(int j = 0; j < ssv; j++)
		{
			NodeDK nodedk;
			file >> nodedk.maSV>> nodedk.diem;
			file.ignore();
			//cout << nodedk.mssv <<"  " << nodedk.diem <<endl;
			
			
			DK_Insert_first(x.DSDK,nodedk);
			
		}
		if(ssv>0)
		{
			file.getline(temp,50);
		}
		//cout << "SSV = " <<ssv << "; ";
		//cout << "len " << i << " = "<< DK_len(x.DSDK) <<endl;
		root=Insert(root,x);
		file.getline(temp,50);
		//cout <<temp<<endl;
	}

	
	file.close();
	return root;
}
void XuatMotLopTC(Ltc lop)
{
	
	printf("%13d%20s%20s%20s%20s%13d%13d\n",lop.malopTc,lop.mmh,lop.nienkhoa,lop.hocki,lop.nhom,lop.nsvmax,lop.nsvmin);
	
	//cout << "LEN = "<<len << endl;
}
void InDSLopTCPost(Dslop* root){
    if(root != NULL)
    {
    	XuatMotLopTC(root->data);
        InDSLopTCPost(root->left);
        InDSLopTCPost(root->right);
        
    }
}
void InDSLopTC(Dslop* root)
{
	if(root == NULL) 
	{
		cout << "Danh sach rong\n";
		return;
	}
	printf("%13s%20s%20s%20s%20s%13s%13s\n","Ma lop", "Ma MH", "Nien khoa","Hoc ky","Nhom","SV MAX","SV Min");
	InDSLopTCPost(root);
}
// in danh sach lop tin chi theo ma mon hoc
int  kiemtra_mmh(Dslop* root, char mamonhoc[]){
    if(root != NULL )
    {
    	if(strcmp(root->data.mmh,mamonhoc)==0)
    	{
    			return 1;
		}
        kiemtra_mmh(root->left,mamonhoc);
        kiemtra_mmh(root->right,mamonhoc);
        return 0;
    }
}
void Post_MMH(Dslop* root,PTRSV L, char mamonhoc[]){
    if(root != NULL )
    {
    	if(strcmp(root->data.mmh,mamonhoc)==0)
    	{
    			// duyet danh sach dang ky va xuat thoi
	    	dsdk *P=root->data.DSDK; 
			    
			while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
			{
			    	nodesinhvien node;
			    	SV_Travesinhvien(L,P->data.maSV,node);
			    	//SV_XuatMotSV(node);
			        P = P->next;
			        //printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
			    
			}
		}
        Post_MMH(root->left,L,mamonhoc);
        Post_MMH(root->right,L,mamonhoc);
        
    }
}
void InDSLopTC_MMH(Dslop* root,PTRSV L, char mamonhoc[])
{
	if(root == NULL) 
	{
		return;
	}
	printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
	//printf("%13s%20s%20s%20s%20s%13s%13s\n","Ma lop", "Ma MH", "Nien khoa","Hoc ky","Nhom","SV MAX","SV Min");
	Post_MMH(root,L, mamonhoc);
}

// in danh sach lop tin chi theo nhom
int kiemtra_Nhom(Dslop* root, char nhom[]){
    if(root != NULL )
    {
    	if(strcmp(root->data.nhom,nhom)==0)
    	{
    		return 1;
		}
        kiemtra_Nhom(root->left,nhom);
        kiemtra_Nhom(root->right,nhom);
        return 0;
    }
}
void Post_Nhom(Dslop* root, PTRSV L, char nhom[]){
    if(root != NULL )
    {
    	if(strcmp(root->data.nhom,nhom)==0)
    	{
    			// duyet danh sach dang ky va xuat thoi
	    	dsdk *P=root->data.DSDK; 
			    
			while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
			{
			    	nodesinhvien node;
			    	SV_Travesinhvien(L,P->data.maSV,node);
			    	//SV_XuatMotSV(node);
			        P = P->next;
			        //printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
			    
			}
		}
        Post_Nhom(root->left,L,nhom);
        Post_Nhom(root->right,L,nhom);
        
    }
}
void InDSLopTC_Nhom(Dslop* root, PTRSV L, char nhom[])
{
	if(root == NULL) 
	{
		return;
	}
	printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
	//printf("%13s%20s%20s%20s%20s%13s%13s\n","Ma lop", "Ma MH", "Nien khoa","Hoc ky","Nhom","SV MAX","SV Min");
	Post_Nhom(root,L, nhom);
}
// in danh sach lop tin chi theo hoc ky
int kiemtra_HK(Dslop* root, char hocky[]){
    if(root != NULL )
    {
    	if(strcmp(root->data.hocki,hocky)==0)
    	{
    	
	    	return 1;
		}
    	//XuatMotLopTC(root->data);
        kiemtra_HK(root->left,hocky);
        kiemtra_HK(root->right,hocky);
        return 0;
    }
}
void Post_HK(Dslop* root, PTRSV L, char hocky[]){
    if(root != NULL )
    {
    	if(strcmp(root->data.hocki,hocky)==0)
    	{
    	
	    		// duyet danh sach dang ky va xuat thoi
	    	dsdk *P=root->data.DSDK; 
			    
			while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
			{
			    	nodesinhvien node;
			    	SV_Travesinhvien(L,P->data.maSV,node);
			    	//SV_XuatMotSV(node);
			        P = P->next;
			        //printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
			    
			}
		}
    	//XuatMotLopTC(root->data);
        Post_HK(root->left,L,hocky);
        Post_HK(root->right,L,hocky);
        
    }
}
void InDSLopTC_HK(Dslop* root,  PTRSV L,char hocky[])
{
	if(root == NULL) 
	{
		return;
	}
	printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
	//printf("%13s%20s%20s%20s%20s%13s%13s\n","Ma lop", "Ma MH", "Nien khoa","Hoc ky","Nhom","SV MAX","SV Min");
	Post_HK(root,L,hocky);
}
// in danh sach lop tin chi theo nien khoa
// ham kiem tra nien khoa xem ton tai hay khong
int kiemtra_nienkhoa(Dslop* root, char nienkhoa[]){
    if(root != NULL)
    {
    	if(strcmp(root->data.nienkhoa,nienkhoa)==0)
    	{
    		return 1;
		}
    	
        kiemtra_nienkhoa(root->left,nienkhoa);
        kiemtra_nienkhoa(root->right,nienkhoa);
        return 0;
    }
    
}
void Post_nienkhoa(Dslop* root, PTRSV L, char nienkhoa[]){
    if(root != NULL)
    {
    	if(strcmp(root->data.nienkhoa,nienkhoa)==0)
    	{
    		// duyet danh sach dang ky va xuat thoi
    		dsdk *P=root->data.DSDK; 
		    
		    while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
		    {
		    	nodesinhvien node;
		    	SV_Travesinhvien(L,P->data.maSV,node);
		    	//SV_XuatMotSV(node);
		        P = P->next;
		        
		    }
		}
    		//XuatMotLopTC(root->data);
        Post_nienkhoa(root->left,L,nienkhoa);
        Post_nienkhoa(root->right,L,nienkhoa);
        
    }
}
void InDSLopTC_nienkhoa(Dslop* root,PTRSV L, char nienkhoa[])
{
	if(root == NULL) 
	{
		return;
	}
	printf("%20s%20s%20s%20s%20s%20s%20s\n","maSV","Ho","Ten","Phai","So dien thoai","Ma lop","Nam nhap hoc");
	//printf("%13s%20s%20s%20s%20s%13s%13s\n","Ma lop", "Ma MH", "Nien khoa","Hoc ky","Nhom","SV MAX","SV Min");
	Post_nienkhoa(root,L,nienkhoa);
}

// in danh sach lop tin chi theo nien khoa
void Post_nienkhoahocky(Dslop* root, char nienkhoa[],char hocky[]){
    if(root != NULL)
    {
    	if(strcmp(root->data.nienkhoa,nienkhoa)==0 && strcmp(root->data.hocki,hocky)==0)
    	{
    		XuatMotLopTC(root->data);
    	}
        Post_nienkhoahocky(root->left,nienkhoa,hocky);
        Post_nienkhoahocky(root->right,nienkhoa,hocky);
        
    }
}
int kiemtra_nienkhoahocky(Dslop* root, char nienkhoa[],char hocky[], int chon, char maSV[]){
    if(root != NULL)
    {
    	if(strcmp(root->data.nienkhoa,nienkhoa)==0 && strcmp(root->data.hocki,hocky)==0 && (chon == root->data.malopTc))
    	{
    		//  can duyet qua de kiem tra xem co sinh vien do trong lop chua
    		dsdk *P=root->data.DSDK; 
		    
		    while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
		    {
		    	if(strcmp(P->data.maSV,maSV)==0)
		    	{
		    		cout << P->data.maSV <<" vs " << maSV<<endl;
		    		cout << "Da co sinh vien trong danh sach dang ky!!!\n";
		    		return -1;
				}
		        P = P->next;
		    }
    		// luc dau anh dat ham return 2 o day bi sai 
    	}
        kiemtra_nienkhoahocky(root->left,nienkhoa,hocky,chon,maSV);
        kiemtra_nienkhoahocky(root->right,nienkhoa,hocky,chon,maSV);
        // phai dat xuong da 
        return 2;
        
    }
    
}
void InDSLopTC_nienkhoahocky(Dslop* root, char nienkhoa[],char hocky[])
{
	if(root == NULL) 
	{
		return;
	}
	
	printf("%13s%20s%20s%20s%20s%13s%13s\n","Ma lop", "Ma MH", "Nien khoa","Hoc ky","Nhom","SV MAX","SV Min");
	Post_nienkhoahocky(root,nienkhoa,hocky);
}
int sinhsongaunhien(Dslop* root,Ltc &lop)
{
	srand((int)time(0));
	lop.malopTc = rand()%100+1;
	//cout << lop.malopTc <<endl;
	while(Search(root,lop) ==true)
	{
		lop.malopTc = rand()%100+1;
		//cout << lop.malopTc <<endl;
	}
	return -1;
}

Dslop* ThemLTC(Dslop* root,dsmh ds)
{
	Ltc lop;
	sinhsongaunhien(root,lop);
tieptucmmh:
	cout << "Nhap vao ma mon hoc: ";
	cin.getline(lop.mmh,11);
	cout << "Nhap vao nien khoa:";
	if(MH_laysoTTmaMH(ds,lop.mmh)==-1)
	{
		cout << "Ma mon hoc da ton tai\n";
		goto tieptucmmh;
	}
	cin.getline(lop.nienkhoa,5);
	cout << "Nhap vao hoc ky: ";
	cin.getline(lop.hocki,2);
	cout <<"Nhap vao nhom: ";
	cin.getline(lop.nhom,2);
	cout << "Nhap vao so sinh vien max: ";
	cin >> lop.nsvmax;
	cout << "Nhap vao so sinh vien min: ";
	cin >> lop.nsvmin;
	
	Insert(root,lop);
	return root;
}
Dslop* XoaLTC(Dslop* root)
{
	cout << "Nhap vao ma lop tin chi: ";
	Ltc lop;
	
	cin >> lop.malopTc;
	cin.ignore();
	if(Search(root,lop)==false)
	{
		cout << "Ma lop tin chi khong ton tai: ";
		return root;
	}
	Delete(root,lop);
	return root;
	
}
void SuaLTC(  Dslop* &root, int maloptc )
{
	Ltc value;
	value.malopTc = maloptc;
    if ( root == NULL )
        return ;
    if(root->data.malopTc == maloptc)
	{
		
		//sua trong nay
		// bat dau sua
		char temp[10];
		char c;
		do{
			printf("Ban muon sua Ma mon hoc(c:co, k: khong):");
			cin.getline(temp,10);
			c = temp[0];
		}while(!(c=='c'|| c=='k'));
		if(c=='c')
		{
			cout << ("Nhap ma mon hoc moi: ");
			cin.getline(root->data.mmh,11);
		}
		// nhap nien khoa moi
		do{
			printf("Ban muon sua nien khoa(c:co, k: khong):");
			cin.getline(temp,10);
			c = temp[0];
		}while(!(c=='c'|| c=='k'));
		if(c=='c')
		{
			cout << ("Nhap nien khoa: ");
			cin.getline(root->data.nienkhoa,5);
		}
			// nhap hoc ky moi
		do{
			printf("Ban muon sua hoc ky(c:co, k: khong):");
			cin.getline(temp,10);
			c = temp[0];
		}while(!(c=='c'|| c=='k'));
		if(c=='c')
		{
			cout << ("Nhap hoc ky: ");
			cin.getline(root->data.hocki,2);
		}
			// nhap nhom moi
		do{
			printf("Ban muon sua nhom(c:co, k: khong):");
			cin.getline(temp,10);
			c = temp[0];
		}while(!(c=='c'|| c=='k'));
		if(c=='c')
		{
			cout << ("Nhap nien khoa: ");
			cin.getline(root->data.nhom,2);
		}
			// nhap so sinnh vien max
		do{
			printf("Ban muon sua so sinh vien max(c:co, k: khong):");
			cin.getline(temp,10);
			c = temp[0];
		}while(!(c=='c'|| c=='k'));
		if(c=='c')
		{
			cout << ("Nhap so sinh vien max: ");
			cin >> root->data.nsvmax;
			cin.ignore();
		}
		
			// nhap so sinnh vien min
		do{
			printf("Ban muon sua so sinh vien min(c:co, k: khong):");
			cin.getline(temp,10);
			c = temp[0];
		}while(!(c=='c'|| c=='k'));
		if(c=='c')
		{
			cout << ("Nhap so sinh vien min: ");
			cin >> root->data.nsvmin;
			cin.ignore();
		}
		
		return;
		/**/
        
    }else if ( LeftOf( value, root ) ){
         SuaLTC( root->left, maloptc );
    }else if( RightOf( value, root ) ){
         SuaLTC( root->right, maloptc );
    }
}
// ham nay tra ve la chuoi ma lop dang ky
void DKLopTC(Dslop* root,char mssv[])
{
	char nienkhoa[5], hocky[2];
	int chon = 0;
	cout << "Nhap nien khoa: ";
	cin.getline(nienkhoa,5);
	cout << "Nhap hoc ky: ";
	cin.getline(hocky,2);
	InDSLopTC_nienkhoahocky(root,nienkhoa,hocky);
	int arr[50];
	int narr = 0;
	do{
		if(narr>=1)
		{
			cout << "\tBan da chon cac lop: ";
			for(int i = 0; i < narr-1;i++)
			{
				cout << arr[i]<< " ";
			}
			cout <<endl;
		}
		cout << "Nhap chon cac ma lop muon dang ky(nhan 0 de thoat): ";
		cin >> chon;
		cin.ignore();
		//cout << "Chon = "<<chon  << " va ket qua = "<<kiemtra_nienkhoahocky(root,nienkhoa,hocky,chon,mssv)<<endl;
		if(kiemtra_nienkhoahocky(root,nienkhoa,hocky,chon,mssv)==2)
		{
			
			int check = 0;
			for(int k = 0; k < narr; k++)
			{
				if(arr[k] == chon)
				{
					check = 1;
				}
			}
			if(check ==0 )
			{
				arr[narr] = chon;
				narr++;
				cout << "\t\tBan da dang ky lop co ma lop la "<<chon <<" !!!\n";
			}
			else
			{
				cout << "Da chon lop nay roi!\n";
			}
			
			
		}
		else
		{
			//cout << "Ban khong duoc dang ky lop hoc nay vui long chon lop dang ky khac!!!\n";
		}
		if(chon == 0)
		{
			cout << "Ban da chon thoat roi!\n";
		}
	}while(chon != 0);
	cin.ignore();
	char temp[10];
	char c;
	int i = 0;
	while(i<narr-1)
	{
		 
		do{
			cout<<"\t\t\t\t\t\t----------------------------------------------------\n";
        	cout<<"\t\t\t\t\t\t|            CHUC NANG HIEU CHINH                  |\n";
        	cout<<"\t\t\t\t\t\t|      1. Lua chon                                 |\n";
        	cout<<"\t\t\t\t\t\t|      2. Khong chon                               |\n";
        	cout<<"\t\t\t\t\t\t----------------------------------------------------\n";
			printf("Ban muon chon hoac bo chon lop co ma lop la %d\n",arr[i]);
			cout << "Nhap lua chon: ";
			cin.getline(temp,10);
			c = temp[0];
		}while(!(c=='1'|| c=='2'));
		if(c=='2')
		{
			for(int j = i;j<narr-1;j++)
			{
				arr[j]=arr[j+1];
			}
			cout << "Thanh cong!!!\n";
			narr--;
		}
		else
			i++;
		
	}
	if(narr>=1)
		{
			cout << "\tBan da chon cac lop: ";
			for(int i = 0; i < narr-1;i++)
			{
				cout << arr[i]<< " ";
			}
			cout <<endl;
		}
	else if(narr<=0)
	{
		//cout << "Ban khong chon lop nao!!!\n";
		cout <<"Bam phim bat ky de thoat!\n";
		system("pause");
	}
		for(int i = 0; i < narr-1;i++)
		{
			NodeDK dk;
			dk.diem = 0;
			strcpy(dk.maSV,mssv);
			updateLTC(root,arr[i],dk);
		}
	
	//updateLTC(root, mssv,arr,narr,nienkhoa,hocky);
}
void updateLTC(Dslop* root, int malop, NodeDK sv)
{
	if(root != NULL)
    {
    	if(root->data.malopTc==malop)
    	{
    		DK_Insert_first(root->data.DSDK,sv);
    		return;
    	}
        updateLTC(root->left,malop,sv);
        updateLTC(root->right,malop,sv);
        
    }
}
//User nh?p vào niên khóa, h?c k?, nhóm , môn h?c
// in danh sach lop tin chi theo hoc ky
void XuatMotDongCauH(Ltc loptc,PTRSV listSV)
{
	
	int len = DK_len(loptc.DSDK);
	if(len == 0)
	{
		cout << "Lop nay chua co sinh vien nao dang ky!!\n";
		return;
	}
//	for(int i = 0; i < len; i++ )
	//{
	//	printf("%13d%20s%20s%20s%20s\n",i+1, loptc.DSDK->, "Ho","Ten","Diem");
	//}
	dsdk *P=loptc.DSDK; 
    int i=1;
    
    while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach1
    {
    	nodesinhvien sv = SV_TimSVtuMa(listSV,P->data.maSV);
    	printf("%13d%20s%20s%20s%20.1f\n",i, P->data.maSV, sv.ho,sv.ten,P->data.diem);
        P = P->next;
        i++;
    }
    
	
}
void XuatMotDongCauH2(Ltc &loptc,PTRSV listSV)
{
	
	int len = DK_len(loptc.DSDK);
	if(len == 0)
	{
		cout << "Lop nay chua co sinh vien nao dang ky!!\n";
		return;
	}
//	for(int i = 0; i < len; i++ )
	//{
	//	printf("%13d%20s%20s%20s%20s\n",i+1, loptc.DSDK->, "Ho","Ten","Diem");
	//}
	dsdk *P=loptc.DSDK; 
    int i=1;
    
    while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
    	nodesinhvien sv = SV_TimSVtuMa(listSV,P->data.maSV);
    	printf("%13d%20s%20s%20s",i, P->data.maSV, sv.ho,sv.ten);
    	cout << "                  ";
    	cin >> P->data.diem;
    	cin.ignore();
        P = P->next;
        i++;
    }
    
	
}
void Post_Inbangdiemmonhoc(Dslop* root,PTRSV listSV, dsmh dsMH, char hocky[], char nhom[], char nienkhoa[], char mmh[]){
    if(root != NULL )
    {
    	if(strcmp(root->data.hocki,hocky)==0 && strcmp(root->data.nhom,nhom) ==0 && strcmp(root->data.nienkhoa,nienkhoa)==0 && strcmp(root->data.mmh,mmh)==0) 
    	{
    		// in trong nay
    		cout << "\t\t\t\t\tBANG DIEM MON HOC: "<<MH_layvitriMH(dsMH,root->data.mmh)<<endl;
    		cout << "\t\t\t\t\tNien khoa: "<<root->data.nienkhoa<<"\tHoc ky: "<<root->data.hocki<<"\tNhom: "<<root->data.nhom<<endl;
    		cout <<"\n\n";
    		printf("%13s%20s%20s%20s%20s\n","STT", "MASV", "Ho","Ten","Diem");
    		XuatMotDongCauH(root->data,listSV);
			return;	
		}
        Post_Inbangdiemmonhoc(root->left,listSV,dsMH,hocky,nhom,nienkhoa,mmh);
        Post_Inbangdiemmonhoc(root->right,listSV,dsMH,hocky,nhom,nienkhoa,mmh);
        
    }
}
void XuatFile_bangdiemmonhoc(Dslop* root,PTRSV listSV, dsmh dsMH, char hocky[], char nhom[], char nienkhoa[], char mmh[]){
    if(root != NULL )
    {
    	if(strcmp(root->data.hocki,hocky)==0 && strcmp(root->data.nhom,nhom) ==0 && strcmp(root->data.nienkhoa,nienkhoa)==0 && strcmp(root->data.mmh,mmh)==0) 
    	{
    		cout << "Nhap ten file: ";
    		char str[50];
    		cin.getline(str,50);
    		FILE *file;
    		
   			file = fopen(str,"w");
    		// in trong nay
    		fprintf(file,"%s %s\n", "\t\t\t\t\tBANG DIEM MON HOC: ",MH_layvitriMH(dsMH,root->data.mmh));
    		fprintf(file,"\t\t\t\t\tNien khoa: %s \tHoc ky: %s\tNhom: %s\n\n\n",root->data.nienkhoa,root->data.hocki,root->data.nhom);
    		
    		fprintf(file,"%13s%20s%20s%20s%20s\n","STT", "MASV", "Ho","Ten","Diem");
    		//XuatMotDongCauH(root->data,listSV);
    		
    		int len = DK_len(root->data.DSDK);
			if(len == 0)
			{
				fprintf(file,"Lop nay chua co sinh vien nao dang ky!!\n");
				fclose(file);
				return;
			}
		//	for(int i = 0; i < len; i++ )
			//{
			//	printf("%13d%20s%20s%20s%20s\n",i+1, loptc.DSDK->, "Ho","Ten","Diem");
			//}
			dsdk *P=root->data.DSDK; 
		    int i=1;
		    
		    while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach1
		    {
		    	nodesinhvien sv = SV_TimSVtuMa(listSV,P->data.maSV);
		    	//cout << sv.mssv<< sv.ten << sv.ho <<endl;
		    	fprintf(file,"%13d%20s%20s%20s%20.1f\n",i, P->data.maSV, sv.ho,sv.ten,P->data.diem);
		        P = P->next;
		        i++;
		    }
    		fclose(file);
			return;	
		}
        XuatFile_bangdiemmonhoc(root->left,listSV,dsMH,hocky,nhom,nienkhoa,mmh);
        XuatFile_bangdiemmonhoc(root->right,listSV,dsMH,hocky,nhom,nienkhoa,mmh);
        
    }
}
void Post_cauH2(Dslop* root,PTRSV listSV, char hocky[], char nhom[], char nienkhoa[], char mmh[]){
    if(root != NULL )
    {
    	if(strcmp(root->data.hocki,hocky)==0 && strcmp(root->data.nhom,nhom) ==0 && strcmp(root->data.nienkhoa,nienkhoa)==0 && strcmp(root->data.mmh,mmh)==0) 
    	{
    		// in trong nay
    		printf("%13s%20s%20s%20s%20s\n","STT", "MASV", "Ho","Ten","Diem");
    		XuatMotDongCauH2(root->data,listSV);
			return;	
		}
        Post_cauH2(root->left,listSV,hocky,nhom,nienkhoa,mmh);
        Post_cauH2(root->right,listSV,hocky,nhom,nienkhoa,mmh);
        
    }
}
void chucnangInbangDiem(PTRSV listSV, Dslop* root, dsmh dsMH)
{
	InDSLopTC(root);
	char nienkhoa[5],hocky[2],nhom[2],mamonhoc[11];
	cout << "Nhap vao nien khoa: ";
	cin.getline(nienkhoa,5);
	cout << "Nhap vao hoc ky: ";
	cin.getline(hocky,2);
	cout << "Nhap vao nhom: ";
	cin.getline(nhom,2);
	cout << "Nhap vao ma mon hoc: ";
	cin.getline(mamonhoc,11);
	
	
	Post_Inbangdiemmonhoc(root,listSV,dsMH,hocky,nhom,nienkhoa,mamonhoc);
	XuatFile_bangdiemmonhoc(root,listSV,dsMH,hocky,nhom,nienkhoa,mamonhoc);
	
}
void chucnangHNhapDiem(PTRSV listSV, Dslop* root)
{
	InDSLopTC(root);
	char nienkhoa[5],hocky[2],nhom[2],mamonhoc[11];
	cout << "Nhap vao nien khoa: ";
	cin.getline(nienkhoa,5);
	cout << "Nhap vao hoc ky: ";
	cin.getline(hocky,2);
	cout << "Nhap vao nhom: ";
	cin.getline(nhom,2);
	cout << "Nhap vao ma mon hoc: ";
	cin.getline(mamonhoc,11);
	
	Post_cauH2(root,listSV,hocky,nhom,nienkhoa,mamonhoc);
}

void SearchSinhVien( const Dslop* root,PTRSV listSV,dsmh dsMH, char masinhvien[14], float &tongdiem, float &hesochia )
{
	if(root==NULL)
	{
		// duyet den het danh sach 
		
		return;
	}
		
	// kiem tra tai day
	int len = DK_len(root->data.DSDK);
	char maMH[11];
	float lt = 0.0, th = 0.0;
	for(int i = 0; i< len;i++)
	{
		dsdk *DK=root->data.DSDK; 
		if(DK == NULL)
		{
			//cout <<"jfgshfgksjhgjskghs\n";
		}
	    while (DK != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
	    {
	    	// tim ra
	    	if(strcmp(DK->data.maSV,masinhvien)==0)
	    	{
	    		lt = 0, th = 0;
	    		
	    		
	    		for(int tt =0 ;tt<dsMH.n;tt++)
	    		{
	    		//	if(strcmp(masinhvien,"N15DCCN166")==0)
	    			//	{
	    					
	    					//cout << "LT = "<<lt <<" TH = "<<th<<endl;
	    					//cout << root->data.mmh<<"---"<<dsMH.nodemonhoc[tt].mmh<<endl;
						//}
	    		
	    			if(strcmp(root->data.mmh,dsMH.nodemonhoc[tt]->mmh)==0)
	    			{
	    				lt = dsMH.nodemonhoc[tt]->stclt;
	    				th = dsMH.nodemonhoc[tt]->stcth;
	    				
	    				break;
					}
				}
				
	    		tongdiem = tongdiem+ DK->data.diem *(lt+th) ;
	    		hesochia = hesochia +lt+th;
	    		
	    		//cout <<"Tong diem = " <<tongdiem << "He so chia = "<<hesochia<<endl;
			}
	        DK = DK->next;
	    }
	}
	
	SearchSinhVien( root->left,listSV,dsMH, masinhvien, tongdiem,hesochia );
    SearchSinhVien( root->right,listSV, dsMH, masinhvien, tongdiem,hesochia );
}
/*
B?NG TH?NG KÊ ?I?M TRUNG BÌNH KHÓA H?C 
	L?p 	 : <malop>	N?m nh?p h?c: 9999

*/
void XuatFileDiem1LopTheotinChi(PTRSV listSV, Dslop* root,dsmh dsMH,char malop[14])
{
	// nhap ma lop hoc
	char str[50];
	cout <<"Nhap ten File: ";
	cin.getline(str,50);
	FILE *file;
	file = fopen(str,"w");
	// dua vao ma lop thi co cac sinh vien trong lop voi moi sinh vien thi se tim va tinh tat ca cac diem
	DSSV *P=listSV; 
    float hesochia = 0;
    float tongdiem = 0;
   
    int i=1;
    fprintf(file, "\t\t\t\t\t\tBANG THONG KE DIEM TRUNG BINH KHOA HOC\n");
    fprintf(file,"\t\t\t\t\t\tLop: %s \tNam nhap hoc: %d\n\n",malop,SV_NamNhaphoctuMaLop(listSV,malop));
    fprintf(file,"%13s%20s%20s%20s%20s\n","STT", "MASV", "Ho","Ten","Diem TB");
    while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
    	if(strcmp(P->data.malop,malop)==0)
    	{
    		tongdiem = 0;
    		hesochia = 0;
    		// Tim thay sinh vien la thanh vien cua lop 'malop'
			SearchSinhVien(root,listSV,dsMH,P->data.maSV,tongdiem,hesochia);
			nodesinhvien sv = SV_TimSVtuMa(listSV,P->data.maSV);
			//cout <<"Tong diem = " <<tongdiem << "He so chia = "<<hesochia<<endl;
			float DTB = float(tongdiem)/hesochia;
			if(hesochia == 0) DTB = 0;
			//cout << "Tong diem = " << tongdiem <<" He so chia = "<<hesochia<<endl;
			fprintf(file,"%13d%20s%20s%20s%20.1f\n",i, sv.maSV, sv.ho,sv.ten,DTB);
			i++;
		}
        P = P->next;
        
    }
    fclose(file);
	
}
void InDiem1LopTheotinChi(PTRSV listSV, Dslop* root,dsmh dsMH)
{
	// nhap ma lop hoc
	char malop[14];
	cout <<"Nhap vao ma lop: ";
	cin.getline(malop,14);
	// dua vao ma lop thi co cac sinh vien trong lop voi moi sinh vien thi se tim va tinh tat ca cac diem
	DSSV *P=listSV; 
    float hesochia = 0;
    float tongdiem = 0;
   
    int i=1;
    cout << "\t\t\t\t\t\tBANG THONG KE DIEM TRUNG BINH KHOA HOC\n";
    cout << "\t\t\t\t\t\tLop: "<<malop<<"\tNam nhap hoc: "<<SV_NamNhaphoctuMaLop(listSV,malop)<<endl<<endl;
    printf("%13s%20s%20s%20s%20s\n","STT", "MASV", "Ho","Ten","Diem TB");
    while (P != NULL) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
    	if(strcmp(P->data.malop,malop)==0)
    	{
    		tongdiem = 0;
    		hesochia = 0;
    		// Tim thay sinh vien la thanh vien cua lop 'malop'
			SearchSinhVien(root,listSV,dsMH,P->data.maSV,tongdiem,hesochia);
			nodesinhvien sv = SV_TimSVtuMa(listSV,P->data.maSV);
			//cout <<"Tong diem = " <<tongdiem << "He so chia = "<<hesochia<<endl;
			float DTB = float(tongdiem)/hesochia;
			if(hesochia == 0) DTB = 0;
			//cout << "Tong diem = " << tongdiem <<" He so chia = "<<hesochia<<endl;
			printf("%13d%20s%20s%20s%20.1f\n",i, sv.maSV, sv.ho,sv.ten,DTB);
			i++;
		}
        P = P->next;
        
    }
    XuatFileDiem1LopTheotinChi(listSV,root,dsMH,malop);
	
}
void LenDSLopTC(Dslop* root, int &ncount){
    if(root != NULL)
    {
    	ncount ++;
        LenDSLopTC(root->left,ncount);
        LenDSLopTC(root->right,ncount);
        
    }
}


void XuatFile(Dslop* root, int n){
	if(n!=-1)
	{
		out1<<n<<endl;
		out1 <<"------------------------------------------------\n";
		n=-1;
	}
    if(root != NULL)
    {
    	out1<<root->data.malopTc<<endl;
    	out1<<root->data.mmh<<endl;
    	out1<<root->data.nienkhoa<<endl;
    	out1<<root->data.hocki<<endl;
    	out1<<root->data.nhom<<endl;
    	out1<<root->data.nsvmax<<endl;
    	out1<<root->data.nsvmin<<endl;
    	
    	int ssv = DK_len(root->data.DSDK);
    	out1 << ssv <<endl;
    	
    	if(ssv>0)
    	{
		
	    	dsdk *P=root->data.DSDK; 
		   
		    while (P != NULL ) //duyet danh sach den khi ket thuc danh sach
		    {
		    	out1<<P->data.maSV <<" "<<P->data.diem<<" ";
		        P = P->next;
		        
		    }
		    out1<<"\n------------------------------------------------\n";
		}
		else
		{
			out1<<"------------------------------------------------\n";
		}
    	
        XuatFile(root->left,n);
        XuatFile(root->right,n);
        
    }
}
void LuuFileLTC(Dslop* root)
{
	out1.open("DSLTC.txt");
	int n = 0;
	LenDSLopTC(root,n);
	
	XuatFile(root,n);
	out1.close();
}

