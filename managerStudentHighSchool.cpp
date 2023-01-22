#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
struct date
{
    int day,month,year;
};
struct diemTN
{
    float ly,hoa,sinh;
};
struct diemXH
{
    float gdcd,su,dia;
};
struct diem
{
    float van,toan,ta;
    diemTN TN;
    diemXH XH;
};
struct hs
{
    char name[100];
    char sbd[11];
    char clas[100];
    date ngaysinh;
    char gioitinh[4];
    char KV[4];
    int phanloai;//1 la XH, 0 la TN
    diem test;

};
//Ham MENU
void menu(hs a[],int &sl);
void menubatbuoc(hs a[],int &sl);
void huongdannhapKV();
//HAM KIEM TRA VA XU LY
bool ktngaysinh(hs a);
void xoachuoi(int &sl, char a[], int k);
void xoaMang(hs a[], int &sl, int vi_tri);
void xoahs(hs a[], int &sl);
void ktkhoangcach(int &sl, char a[]);
void inhoadau(char a[]);
//HAM NHAP
void nhapngaysinh(hs &a);
void nhapdiemTN(hs &a);
void nhapdiemXH(hs &a);
void nhapdiem(hs &a);
void nhap1hs(hs &a);
void chinhsua(hs a[], int sl);
void nhapmoihs(hs a[], int &sl);
void nhaphs(hs a[],int sl);
void readfile(hs a[],int &sl);
//HAM XUAT
void xuat1hs(hs a);
void xuaths(hs a[],int sl);
void xuatfile(hs a[],int sl);
void xuatfileliet(hs a[],int sl);
//HAM TIM KIEM
void timhocsinhtheoSBD(hs a[], int sl);
void timhocsinhtheohoten(hs a[], int sl);
void timhocsinhtheoten(hs a[], int sl);
void timthukhoa(hs a[], int sl);
int timkitudau(char a[]);
void timhocsinhLIET(hs a[],int sl,hs hocsinhliet[],int &sohocsinhliet);
//HAM SAP XEP
void sapxeptheosbd(hs a[], int sl);
void sapxeptheoten(hs a[], int sl);
int main()
{
    int sl;
    hs a[400];
    menubatbuoc(a,sl);
    system("cls");
    huongdannhapKV();
    menu(a,sl);
    return 0;
}
bool ktngaysinh(hs a)
{
    if(a.ngaysinh.year<=0){return false;}
            switch (a.ngaysinh.month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(a.ngaysinh.day>=1&&a.ngaysinh.day<=31){return true;}
                else{return false;}
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(a.ngaysinh.day>=1&&a.ngaysinh.day<=30){return true;}
                else{return false;}
                break;
            case 2:
                if(a.ngaysinh.year%4==0&&a.ngaysinh.year%100!=0||a.ngaysinh.year%400==0)//Kiểm tra năm nhuận
                    {
                        if(a.ngaysinh.day>=1&&a.ngaysinh.day<=29){return true;}
                        else{return false;}
                    }
                else
                    {
                        if(a.ngaysinh.day>=1&&a.ngaysinh.day<=28){return true;}
                        else{return false;}
                    }
                break;
            default:
                return false;
                break;
            }
}
void readfile(hs a[],int &sl)
{
    int i,j=0;
    FILE *file;
    file=fopen("Danhsachhs.txt","r");//cho phep doc
    if(file==NULL)
        {
            printf("\t\tFILE KHONG TON TAI!!\n");
            printf("\tVui long nhap thu cong\n");
            printf("Nhan ENTER de bat dau");
            getch();
           system("cls");
            do
            {
                 printf("NHAP SO LUONG SINH VIEN: ");
                 scanf("%d",&sl);
            }while(sl<=0||sl>400);
            nhaphs(a,sl);
            system("cls");
        };
    fscanf(file,"So luong: %d\n",&sl);
    for(i=0;i<sl;i++)
         {
             fscanf(file,"\t%d\n",&a[i].phanloai);// doc phan loai de chia TN - XH
             fscanf(file,"\t%[^\n]",&a[i].name);//Đọc cho tới khi gặp \n
             fscanf(file,"\tSo Bao Danh hoc sinh: %s\n",&a[i].sbd);
             fscanf(file,"\tLop: %s\n",&a[i].clas);
             fscanf(file,"\tGioi tinh: %s\n",&a[i].gioitinh);
             fscanf(file,"\tNgay sinh: %d / %d / %d\n",&a[i].ngaysinh.day,&a[i].ngaysinh.month,&a[i].ngaysinh.year);
             fscanf(file, "\tKhu vuc: %s\n", &a[i].KV);
             fscanf(file,"\tDiem Toan: %f\n",&a[i].test.toan);
             fscanf(file,"\tDiem Van: %f\n",&a[i].test.van);
             fscanf(file,"\tDiem Tieng Anh: %f\n",&a[i].test.ta);
    if(a[i].phanloai==0)
        {
            fscanf(file,"\tDiem Sinh: %f\n",&a[i].test.TN.sinh);
            fscanf(file,"\tDiem Ly: %f\n",&a[i].test.TN.ly);
            fscanf(file,"\tDiem Hoa: %f\n",&a[i].test.TN.hoa);
        }
    else if(a[i].phanloai==1)
        {
            fscanf(file,"\tDiem GDCD: %f\n",&a[i].test.XH.gdcd);
            fscanf(file,"\tDiem Su: %f\n",&a[i].test.XH.su);
            fscanf(file,"\tDiem Dia: %f\n",&a[i].test.XH.dia);
        }
        }
         printf("NHAP THANH CONG");
    getch();
   fclose(file);
}
void nhapdiemTN(hs &a)
{
    do
    {
    printf("\tNhap diem Ly: ");
    scanf_s("%f",&a.test.TN.ly);
    }while(a.test.TN.ly<0 ||a.test.TN.ly>10);
    do
    {
    printf("\tNhap diem Hoa: ");
    scanf_s("%f",&a.test.TN.hoa);
    }while(a.test.TN.hoa<0 ||a.test.TN.hoa>10);
    do
    {
    printf("\tNhap diem Sinh: ");
    scanf_s("%f",&a.test.TN.sinh);
    }while(a.test.TN.sinh<0 ||a.test.TN.sinh>10);
}
void nhapdiemXH(hs &a)
{
    do
    {
    printf("\tNhap diem GDCD: ");
    scanf_s("%f",&a.test.XH.gdcd);
    }while(a.test.XH.gdcd<0 ||a.test.XH.gdcd>10);
    do
    {
    printf("\tNhap diem Su: ");
    scanf_s("%f",&a.test.XH.su);
    }while(a.test.XH.su<0 ||a.test.XH.su>10);
    do
    {
    printf("\tNhap diem Dia: ");
    scanf_s("%f",&a.test.XH.dia);
    }while(a.test.XH.dia<0 ||a.test.XH.dia>10);
}
void nhapdiem(hs &a)
{
    do
    {
    printf("\tNhap diem Toan: ");
    scanf_s("%f",&a.test.toan);
    }while(a.test.toan<0 ||a.test.toan>10);
    do
    {
    printf("\tNhap diem Van: ");
    scanf_s("%f",&a.test.van);
    }while(a.test.van<0 ||a.test.van>10);
    do
    {
    printf("\tNhap diem TA: ");
    scanf_s("%f",&a.test.ta);
    }while(a.test.ta<0 ||a.test.ta>10);
    do
    {
    printf("\t\tMOI BAN CHON TN-XH: 0-1\n");
    scanf_s("%d",&a.phanloai);
    }while(a.phanloai!=1 && a.phanloai!=0);
    if(a.phanloai==1)
        {
            nhapdiemXH(a);
        }
    else
        {
            nhapdiemTN(a);
        }
}
void nhapngaysinh(hs &a)
{
    do
    {   
        printf("\tNhap ngay sinh: ");
        scanf_s("%d",&a.ngaysinh.day);
        printf("\tNhap thang sinh: ");
        scanf_s("%d",&a.ngaysinh.month);
        printf("\tNhap nam sinh: ");
        scanf_s("%d",&a.ngaysinh.year);

    }while(ktngaysinh(a)==false);
}
void nhap1hs(hs &a)
{
    char nam[]={"nam"};
    char nu[]={"nu"};
    fflush(stdin);
    getchar();
    printf("**************************************************************\n");
    do
    {
    printf("\tNhap ten sinh vien: ");
    gets(a.name);
    int i = strlen(a.name);
    ktkhoangcach(i,a.name);//Xóa khoảng cách
    inhoadau(a.name);//In hoa chữ đầu
    }while(strlen(a.name)==0);//Kiểm tra chuỗi !=0
    do
    {
    printf("\tNhap So Bao Danh: (10 KY TU)");
    gets(a.sbd);
    int i = strlen(a.sbd);
    ktkhoangcach(i,a.sbd);//Xóa khoảng cách
    }while(strlen(a.sbd)!=10);
    do
    {
    printf("\tNhap ten lop: ");
    gets(a.clas);
    int i = strlen(a.clas);
    ktkhoangcach(i, a.clas);
    }while(strlen(a.clas)==0);
    do
    {
    printf("\tNhap gioi tinh: ( Nam - Nu ) ");
    gets(a.gioitinh);
    int i = strlen(a.gioitinh);
    ktkhoangcach(i, a.gioitinh);
    strlwr(a.gioitinh);//NaM,nU --> nam, nu
    }while( strcmp(a.gioitinh,nam)!=0&&strcmp(a.gioitinh,nu)!=0);//so sánh 2 chuỗi trên
    inhoadau(a.gioitinh);
    nhapngaysinh(a);
    printf("\tNhap vao khu vuc: ");
    do {
        gets(a.KV);
        int i = strlen(a.KV);
        ktkhoangcach(i, a.KV);
        fflush(stdin);
    } while ((strcmp(a.KV, "1") != 0) && (strcmp(a.KV, "2") != 0) && (strcmp(a.KV, "3") != 0) && (strcmp(a.KV, "2NT") != 0));
    nhapdiem(a);
    printf("**************************************************************\n");

}
void nhapmoihs(hs a[], int &sl)
{
	int x,dem=0;
	printf("\n\t\tSO HOC SINH KHONG VUOT QUA 400:\n\t\tSO HOC SINH HIEN CO: %d",sl);
	do {
	printf("\n\tNhap so hoc sinh muon them: ");
	scanf("%d",&x);
	} while ( sl + x > 400 || x <= 0);
	printf("\n\tNhap thong tin cua hoc sinh muon them:\n ");
    for (dem; dem< x;)
        {
        sl++;
        loop:
        printf("\n\t\t\tNHAP HOC SINH THU %d\n",sl);
        nhap1hs(a[sl - 1]);// nhập từ vị trí cuối mảng
        for (int i = 0; i < sl;i++)
        {
            if(i!=sl-1)
                {
                    if(strcmp(a[i].sbd,a[sl-1].sbd)==0)
                        {
                            printf("\t\t\tBAN DA TRUNG, MOI NHAP LAI\n");
                            goto loop;
                        }
                }
        }
        dem++;//nhập x=3 --> dem++ 3 lần là lặp 3 lần
        }
    printf("\n\tNhan ENTER de tiep tuc chuong trinh.");
    _getch();
}
void nhaphs(hs a[],int sl)
{
    int i,j,test;
    for(i=0;i<sl;i++)
        {
            loop:
            test=0;
            printf("\n\t\t\tNHAP HOC SINH THU %d\n",i+1);
            nhap1hs(a[i]);
            for(j=0;j<sl;j++)
                {
                    if(j!=i)
                        {
                            if(strcmp(a[i].sbd,a[j].sbd)==0)
                                test++;
                        }
                }
            if(test!=0)
                {
                    printf("\t\t\tBAN DA TRUNG, MOI NHAP LAI\n");
                    goto loop;
                }

        }
}
void menubatbuoc(hs a[],int &sl)
{
    int luachonbandau;

    do
        {
        system("cls");
        printf("\t\tMENU NHAP THONG TIN DE BAT DAU CHUONG TRINH\n");
        printf("\t1.Nhap thu cong\n\t2.Nhap tu file co san\n");
        printf("Nhap lua chon: ");
        scanf_s("%d",&luachonbandau);
        }while(luachonbandau!=1&&luachonbandau!=2);
        switch(luachonbandau)
        {
            case 1:
                    printf("\t\tBAN DA CHON LUA CHON 1\n");
                    printf("Nhan ENTER de bat dau");
                    getch();
                    system("cls");
                    do
                    {
                        printf("NHAP SO LUONG SINH VIEN: ");
                        scanf("%d",&sl);
                    }while(sl<=0||sl>400);
                    nhaphs(a,sl);
                    system("cls");
                    break;
            case 2:
                    printf("\t\tBAN DA CHON LUA CHON 2\n");  
                    printf("Nhan ENTER de bat dau");
                    getch();
                    system("cls");
                    readfile(a,sl);
                    system("cls");
                    break;
        }
}
void menu(hs a[],int &sl)
{
    int n,i;
    do
    {
    printf("-------------------BANG MENU QUAN LY HOC SINH-------------------\n");
    printf("\t1.Sua danh sach hoc sinh\n");
    printf("\t2.Tim theo So Bao Danh\n");
    printf("\t3.Tim theo ho va ten\n");
    printf("\t4.Tim thu khoa\n");
    printf("\t5.Sap xep theo ten\n");
    printf("\t6.Sap xep theo So Bao Danh\n");
    printf("\t7.Loc hoc sinh bi diem LIET\n");
    printf("\t8.Xuat thong tin hoc sinh\n");
    printf("\t9.Xuat ra file\n");
    printf("\t0.Thoat khoi chuong trinh\n");
    printf("SO HOC SINH HIEN CO: %d\n", sl);
    printf("Nhap lua chon: ");
    scanf_s("%d",&n);
    switch (n)
    {
    case 1:
        int choice;
        printf("\t\tBAN DA CHON LUA CHON 1\n");
        printf("Nhan ENTER de bat dau");
        getch();
        do
        {
        system("cls");
        printf("\t\tMENU NHAP THONG TIN\n");
        printf("\t1.Nhap them hoc sinh\n\t2.Xoa hoc sinh\n\t3.Nhap lai tu file co san\n\t4.Chinh sua hoc sinh theo So Bao Danh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
        if(choice==1)
            {
            system("cls");
            nhapmoihs(a, sl);
            system("cls");
            }
        else if(choice==2)
            {
            system("cls");
            xoahs(a, sl);
            }
        else if(choice==3)
            {
            readfile(a, sl);
            system("cls");
            }
        else if(choice==4)
            {
            system("cls");
            chinhsua(a, sl);
            }
        system("cls");
        break;
    case 2:
            printf("\t\tBAN DA LUA CHON 2\n");
            printf("Nhan ENTER de bat dau");
            _getch();
            system("cls");
            timhocsinhtheoSBD(a, sl);
            system("cls");
            break;
    case 3:
            int luachon;
            printf("\t\tBAN DA LUA CHON 3\n");
            printf("Nhan ENTER de bat dau");
            _getch();
            system("cls");
            do 
            {
                printf("\n\t\tNhan 1 de tim theo ho ten");
                printf("\n\t\tNhan 2 de tim theo ten");
                printf("\n\tNHAP LUA CHON CUA BAN: ");
                scanf("%d", &luachon);
            } while (luachon !=1 && luachon != 2);
            system("cls");
            if (luachon == 1)
            {
                timhocsinhtheohoten(a, sl);
            }
            else
            {
                timhocsinhtheoten(a, sl);
            }
            system("cls");
            break;
    case 4:
            printf("\t\tBAN DA LUA CHON 4\n");
            printf("Nhan ENTER de bat dau");
            _getch();
            system("cls");
            timthukhoa(a, sl);
            printf("Nhan ENTER de tiep tuc");
            getch();
            system("cls");
            break;
    case 5:
            printf("\t\tBAN DA LUA CHON 5\n");
            printf("Nhan ENTER de bat dau");
            _getch();
            system("cls");
            sapxeptheoten(a, sl);
            xuaths(a, sl);
            printf("Nhan ENTER de tiep tuc");
            getch();
            system("cls");
            break;
    case 7:
            {hs hocsinhliet[400];
            int soliet=0;
            printf("\t\tBAN DA LUA CHON 7\n");
            printf("Nhan ENTER de bat dau");
            _getch();
            system("cls");
            timhocsinhLIET(a,sl,hocsinhliet,soliet);
            int m;
            printf("\t\tBAN CO DONG Y XUAT THANH DANH SACH\n");
            printf("\t1.YES\n\t2.NO\nNHAP LUA CHON: ");
            do
            {
                scanf("%d", &m);
        } while (m != 1 && m != 2);
        if(m==1)
        {
                xuatfileliet(hocsinhliet, soliet);
        }
        printf("Nhan ENTER de tiep tuc");
            getch();
            system("cls");
        }
        break;
    case 6:
        printf("\t\tBAN DA LUA CHON 6\n");
        printf("Nhan ENTER de bat dau");
        _getch();
        system("cls");
        sapxeptheosbd(a, sl);
        xuaths(a, sl);
        printf("Nhan ENTER de tiep tuc");
        getch();
        system("cls");
        break;
    case 8:
        printf("\t\tBAN DA CHON LUA CHON 8\n");
        printf("Nhan ENTER de bat dau");
        getch();
        system("cls");
        xuaths(a,sl);
        printf("Nhan ENTER de tiep tuc");
        getch();
        system("cls");
        break;
    case 9:
        xuatfile(a,sl);
        printf("XUAT THANH CONG");
        getch();
        system("cls");
        break;
    default:
        if(n==0)
            {
                printf("Nhan ENTER de thoat khoi chuong trinh\n");
            }
        else
            {
                printf("*Khong co lua chon nay , nhan ENTER de nhap lai.*\n");
            } 
        getch();
        system("cls");
        break;
    }
    }while(n!=0);

}
void huongdannhapKV()
{
    printf("Huong dan nhap khuc vuc cho hoc sinh:");
    printf("\n\tLUU Y: CHI CO 4 KV NEU NHAP SAI PHAI NHAP LAI");
    printf("\n\tNhan 1 de nhap vao KV1. Doi voi KV 1 se duoc cong 0.75 diem");
    printf("\n\tNhan 2 de nhap vao KV2. Doi voi khu vuc 2 se duoc cong vao 0.25 diem");
    printf("\n\tNhan 2NT de nhap vao KV2-NT. Doi voi khu vuc 2 - NT se duoc cong vao 0.5 diem");
    printf("\n\tNhan 3 de nhap vao KV3. Doi voi khu vuc 3 thi khong duoc cong diem");
    printf("\nSau day la MENU cho chuong trinh:\n");
}
void xuatfile(hs a[],int sl)
{
    FILE *file;
    int i;
    file=fopen("Danhsachhs.txt","w");//cho phep ghi
    if(file==NULL)
        {
            printf("FILE ERROR!!");
            exit(1);
        }
    fprintf(file,"So luong: %d\n",sl);
    for(i=0;i<sl;i++)
        {
            fprintf(file,"\t%d\n",a[i].phanloai);//in ra phanloai de khi readfile phan biet TN hay XH
            fprintf(file,"\t%s\n",a[i].name);
            fprintf(file,"\tSo Bao Danh hoc sinh: %s\n",a[i].sbd);
            fprintf(file,"\tLop: %s\n",a[i].clas);
            fprintf(file,"\tGioi tinh: %s\n",a[i].gioitinh);
            fprintf(file,"\tNgay sinh: %d / %d / %d\n",a[i].ngaysinh.day,a[i].ngaysinh.month,a[i].ngaysinh.year);
            fprintf(file, "\tKhu vuc: %s\n", a[i].KV);
            fprintf(file,"\tDiem Toan: %.2f\n",a[i].test.toan);
            fprintf(file,"\tDiem Van: %.2f\n",a[i].test.van);
            fprintf(file,"\tDiem Tieng Anh: %.2f\n",a[i].test.ta);
    if(a[i].phanloai==0)
        {
            fprintf(file,"\tDiem Sinh: %.2f\n",a[i].test.TN.sinh);
            fprintf(file,"\tDiem Ly: %.2f\n",a[i].test.TN.ly);
            fprintf(file,"\tDiem Hoa: %.2f\n",a[i].test.TN.hoa);
        }
    else if(a[i].phanloai==1)
        {
            fprintf(file,"\tDiem GDCD: %.2f\n",a[i].test.XH.gdcd);
            fprintf(file,"\tDiem Su: %.2f\n",a[i].test.XH.su);
            fprintf(file,"\tDiem Dia: %.2f\n",a[i].test.XH.dia);
        }
        }
    fclose(file);
}
void xuatfileliet(hs a[],int sl)
{
    FILE *file;
    int i;
    file=fopen("Danhsachhsliet.txt","w");//cho phep ghi
    if(file==NULL)
        {
            printf("FILE ERROR!!");
            exit(1);
        }
    fprintf(file,"So luong: %d\n",sl);
    for(i=0;i<sl;i++)
        {
            fprintf(file,"\t%d\n",a[i].phanloai);//in ra phanloai de khi readfile phan biet TN hay XH
            fprintf(file,"\t%s\n",a[i].name);
            fprintf(file,"\tSo Bao Danh hoc sinh: %s\n",a[i].sbd);
            fprintf(file,"\tLop: %s\n",a[i].clas);
            fprintf(file,"\tGioi tinh: %s\n",a[i].gioitinh);
            fprintf(file,"\tNgay sinh: %d / %d / %d\n",a[i].ngaysinh.day,a[i].ngaysinh.month,a[i].ngaysinh.year);
            fprintf(file, "\tKhu vuc: %s\n", a[i].KV);
            fprintf(file,"\tDiem Toan: %.2f\n",a[i].test.toan);
            fprintf(file,"\tDiem Van: %.2f\n",a[i].test.van);
            fprintf(file,"\tDiem Tieng Anh: %.2f\n",a[i].test.ta);
    if(a[i].phanloai==0)
        {
            fprintf(file,"\tDiem Sinh: %.2f\n",a[i].test.TN.sinh);
            fprintf(file,"\tDiem Ly: %.2f\n",a[i].test.TN.ly);
            fprintf(file,"\tDiem Hoa: %.2f\n",a[i].test.TN.hoa);
        }
    else if(a[i].phanloai==1)
        {
            fprintf(file,"\tDiem GDCD: %.2f\n",a[i].test.XH.gdcd);
            fprintf(file,"\tDiem Su: %.2f\n",a[i].test.XH.su);
            fprintf(file,"\tDiem Dia: %.2f\n",a[i].test.XH.dia);
        }
        }
    fclose(file);
}
void xuat1hs(hs a)
{
    printf("**************************************************************\n");
    printf("\tTen hoc sinh: %s\n",a.name);
    printf("\tSo Bao Danh hoc sinh: %s\n",a.sbd);
    printf("\tLop: %s\n",a.clas);
    printf("\tGioi tinh: %s\n",a.gioitinh);
    printf("\tNgay sinh: %d / %d / %d\n",a.ngaysinh.day,a.ngaysinh.month,a.ngaysinh.year);
    printf("\tKhu vuc: %s\n",a.KV);
    printf("\tDiem Toan: %.2f\n",a.test.toan);
    printf("\tDiem Van: %.2f\n",a.test.van);
    printf("\tDiem Tieng Anh: %.2f\n",a.test.ta);
    if(a.phanloai==0)
        {
            printf("\tDiem Sinh: %.2f\n",a.test.TN.sinh);
            printf("\tDiem Ly: %.2f\n",a.test.TN.ly);
            printf("\tDiem Hoa: %.2f\n",a.test.TN.hoa);
        }
    else if(a.phanloai==1)
        {
            printf("\tDiem GDCD: %.2f\n",a.test.XH.gdcd);
            printf("\tDiem Su: %.2f\n",a.test.XH.su);
            printf("\tDiem Dia: %.2f\n",a.test.XH.dia);
        }
    printf("**************************************************************\n");
}
void xuaths(hs a[],int sl)
{
    int i;
    for(i=0;i<sl;i++)
        {
            printf("\n\t\t\tTHONG TIN HOC SINH THU %d\n",i+1);
            xuat1hs(a[i]);
        }
    if(sl==0){
            printf("\t\tKhong co thong tin, moi nhap them!\n");}
}
void timhocsinhtheoSBD(hs a[], int sl)
{
    char SBDCanTim[11];
    int flag = 0;
    fflush(stdin);
    getchar();
    do {
        printf("\n\tNhap vao SBD hoc sinh can tim (10 ky tu): ");
        gets(SBDCanTim);
        fflush(stdin);
        int i = strlen(SBDCanTim);
    ktkhoangcach(i,SBDCanTim);//Xóa khoảng cách

    } while (strlen(SBDCanTim) != 10);//Nhap SBD và kiểm tra 10 ký tự
    for (int i = 0; i < sl; i++)
    {// 0 --> sl-1
        if (strcmp(SBDCanTim, a[i].sbd) == 0)//so sánh
        {
            printf("\n\tHoc sinh ban can tim co cac thong tin nhu sau:\n");
            xuat1hs(a[i]);
            flag = 1;
            break;//vì chỉ có 1 sbd thôi
        }
    }
    if (flag == 0) printf("\n\tKhong tim duoc hoc sinh nao co so bao danh %s.\n", SBDCanTim);
    printf("\n\tNhan ENTER de tiep tuc chuong trinh.");
    _getch();
}
void timhocsinhtheohoten(hs a[], int sl)
{
    char HoTenCanTim[50];
    hs HocSinhCanTim[400];
    int sohocsinhcantim = 0;
    hs tam;
    getchar();
    printf("\n\tNhap vao ho ten hoc sinh ban can tim: ");
    gets(HoTenCanTim);
    int i = strlen(HoTenCanTim);
    ktkhoangcach(i, HoTenCanTim);//xóa khoảng cách
    strlwr(HoTenCanTim);// in thường hết chữ IN
    fflush(stdin);
    for (int i = 0; i < sl; i++)
    {
        strcpy(tam.name, a[i].name);//back up vào tam
        strlwr(tam.name);//in thường
        if (strcmp(tam.name, HoTenCanTim) == 0)
        {
            HocSinhCanTim[sohocsinhcantim++] = a[i];//nhập a[i] đúng vào mảng, bắt đầu từ 0
        }
    }
    if (sohocsinhcantim == 0)
    {
        printf("\n\tKhong co hoc sinh nao co ten nhu vay trong danh sach.");
    }
    else//khác 0
    {
        printf("\n\tCo %d hoc sinh so huu ten ban tim kiem.", sohocsinhcantim);
        printf("\n\tHoc sinh ban tim co cac thong tin nhu sau:\n");
        for (int i = 0; i < sohocsinhcantim; i++)
        {
            xuat1hs(HocSinhCanTim[i]);// xuất từng phần tử trong mảng
        }
    }
    printf("\tNhan Enter de tiep tuc chuong trinh.");
    _getch();
}
void timhocsinhtheoten(hs a[], int sl)
{
    char TenCanTim[50];
    hs HocSinhCanTim[400];
    int sohocsinhcantim = 0, index = 0;
    char TenTam[50];
    char TenKQ[50];
    getchar();
    printf("\n\tNhap vao ten hoc sinh ban can tim: ");
    gets(TenCanTim);
    int i = strlen(TenCanTim);
    ktkhoangcach(i, TenCanTim);//kt khoảng cách
    strlwr(TenCanTim);// in thưòng
    fflush(stdin);
    for (int i = 0; i < sl; i++)// từng phần tử mảng học sinh
    {
        for (int j = 0; j <= strlen(a[i].name); j++)// HAM TACH TEN
        {
            if (a[i].name[j] != '\0' && a[i].name[j] != 32)//TT NN --> TT '\0'kết thúc chuỗi  -> NN\0
            {
                TenTam[index++] = a[i].name[j];
            }
            else 
            {
                TenTam[index] = '\0';
                strcpy(TenKQ, TenTam);
                index = 0;
            }
        }
        strlwr(TenKQ);
        if (strcmp(TenKQ, TenCanTim) == 0)
        {
            HocSinhCanTim[sohocsinhcantim++] = a[i];
        }
    }
    if (sohocsinhcantim == 0)
    {
        printf("\n\tKhong co hoc sinh nao co ten nhu vay trong danh sach.\n");
    }
    else
    {
        printf("\n\tCo %d hoc sinh so huu ten ban tim kiem.", sohocsinhcantim);
        printf("\n\tHoc sinh ban tim co cac thong tin nhu sau:\n");
        for (int i = 0; i < sohocsinhcantim; i++)
        {
            xuat1hs(HocSinhCanTim[i]);
        }
    }
    printf("\tNhan Enter de tiep tuc chuong trinh.");
    _getch();
}
void sapxeptheoten(hs a[], int sl)
{
    int i, j;
    for (i = 0; i < sl-1;i++)//BUBBLE SORT
        {
        for (j = sl - 1; j > i;j--)
            {
                if(a[j].name[timkitudau(a[j].name)]<a[j-1].name[timkitudau(a[j-1].name)])//Tăng dần
                    {
                hs temp = a[j];//HOán vị
                a[j] = a[j - 1];
                a[j - 1] = temp;
                    }
            }
        }
    
}
void sapxeptheosbd(hs a[], int sl)
{
    int i, j;
    for (i = 0; i < sl - 1;i++)
    {
            for (j = sl - 1; j > i;j--)
            {
                if(strcmp(a[j].sbd,a[j-1].sbd)<0)
                {
                hs temp = a[j];//HOán vị
                a[j] = a[j - 1];
                a[j - 1] = temp;
                }
            }
    }
}
void timthukhoa(hs a[], int sl)
{
    char thukhoa[2];// tối đa 1 ký tự, vị trí 1 chứa \0
    float diemmax (-1), diem(0);
    int dem(0);
    hs SoThuKhoa[400];
    printf("\n\tCO TAT CA 4 KHOI GOM:");
    printf("\n\t\tKHOI A: TOAN LY HOA");
    printf("\n\t\tKHOI B: LY HOA SINH");
    printf("\n\t\tKHOI C: SU DIA GDCD");
    printf("\n\t\tKHOI D: TOAN VAN ANH");;
    do 
    {
        getchar();
        printf("\n\tNHAP VAO KHOI BAN MUON TIM THU KHOA: ");
        gets(thukhoa);
        int i = strlen(thukhoa);
        ktkhoangcach(i, thukhoa);
        fflush(stdin);
        strlwr(thukhoa);
    } while (strcmp(thukhoa,"a")!=0&& strcmp(thukhoa, "b") != 0 && strcmp(thukhoa, "c") != 0 && strcmp(thukhoa, "d") != 0 );
    if (strcmp(thukhoa,"a")==0)
    {
        for (int i = 0; i < sl; i++)
        {
            if (a[i].phanloai == 0) {
                diem += a[i].test.toan + a[i].test.TN.hoa + a[i].test.TN.ly;
                if (strcmp(a[i].KV, "1") == 0)
                {
                    diem += 0.75;
                }
                else if (strcmp(a[i].KV, "2") == 0)
                {
                    diem += 0.25;
                }
                else if (strcmp(a[i].KV, "2NT") == 0)
                {
                    diem += 0.5;
                }
                if (diemmax < diem)//tìm điểm max
                {
                    diemmax = diem;
                }
                diem = 0;
            }
        }
            for (int i = 0; i < sl; i++)
            {
                diem += a[i].test.toan + a[i].test.TN.hoa + a[i].test.TN.ly;
                if (strcmp(a[i].KV, "1") == 0)
                {
                    diem += 0.75;
                }
                else if (strcmp(a[i].KV, "2") == 0)
                {
                    diem += 0.25;
                }
                else if (strcmp(a[i].KV, "2NT") == 0)
                {
                    diem += 0.5;
                }
                if (diemmax == diem)
                {
                    SoThuKhoa[dem++] = a[i];
                }
                diem = 0;
            }
            if (dem == 1)
            {
                printf("\n\t\tThu khoa khoi A co thong tin la:\n");
                xuat1hs(SoThuKhoa[0]);
            }
            else if (dem == 0)
            {
                printf("\n\t\tKhong co thu khoa khoi nay.");
                printf("\n\t\tVui long tim lai.");
            }
            else
            {
                printf("\n\t\tCo %d thu khoa khoi A.", dem);
                printf("\n\t\tThong tin cua tung thu khoa co thong tin nhu sau:\n");
                for (int i = 0; i < dem; i++)
                {
                    xuat1hs(SoThuKhoa[i]);
                }
            }
        
        
    }
    else if (strcmp(thukhoa,"b")==0)
    {
        for (int i = 0; i < sl; i++)
        {
            if (a[i].phanloai == 0) {
                diem += a[i].test.TN.sinh + a[i].test.TN.hoa + a[i].test.TN.ly;
                if (strcmp(a[i].KV, "1") == 0)
                {
                    diem += 0.75;
                }
                else if (strcmp(a[i].KV, "2") == 0)
                {
                    diem += 0.25;
                }
                else if (strcmp(a[i].KV, "2NT") == 0)
                {
                    diem += 0.5;
                }
                if (diemmax < diem)
                {
                    diemmax = diem;
                }
                diem = 0;
            }
        }
        for (int i = 0; i < sl; i++)
        {
            diem += a[i].test.TN.sinh + a[i].test.TN.hoa + a[i].test.TN.ly;
            if (strcmp(a[i].KV, "1") == 0)
            {
                diem += 0.75;
            }
            else if (strcmp(a[i].KV, "2") == 0)
            {
                diem += 0.25;
            }
            else if (strcmp(a[i].KV, "2NT") == 0)
            {
                diem += 0.5;
            }
            if (diemmax == diem)
            {
                SoThuKhoa[dem++] = a[i];
            }
            diem = 0;
        }
        if (dem == 1)
        {
            printf("\n\t\tThu khoa khoi B co thong tin la:\n");
            xuat1hs(SoThuKhoa[0]);
        }
        else if (dem == 0)
        {
            printf("\n\t\tKhong co thu khoa khoi nay.");
            printf("\n\t\tVui long tim lai.");
        }
        else
        {
            printf("\n\t\tCo %d thu khoa khoi B.", dem);
            printf("\n\t\tThong tin cua tung thu khoa co thong tin nhu sau:\n");
            for (int i = 0; i < dem; i++)
            {
                xuat1hs(SoThuKhoa[i]);
            }
        }
    }
    else if (strcmp(thukhoa,"c")==0)
    {
    for (int i = 0; i < sl; i++)
    {
        if (a[i].phanloai == 1) {
            diem += a[i].test.XH.dia + a[i].test.XH.gdcd + a[i].test.XH.su;
            if (strcmp(a[i].KV, "1") == 0)
            {
                diem += 0.75;
            }
            else if (strcmp(a[i].KV, "2") == 0)
            {
                diem += 0.25;
            }
            else if (strcmp(a[i].KV, "2NT") == 0)
            {
                diem += 0.5;
            }
            if (diemmax < diem)
            {
                diemmax = diem;
            }
            diem = 0;
        }
    }
    for (int i = 0; i < sl; i++)
    {
        diem += a[i].test.XH.dia + a[i].test.XH.gdcd + a[i].test.XH.su;
        if (strcmp(a[i].KV, "1") == 0)
        {
            diem += 0.75;
        }
        else if (strcmp(a[i].KV, "2") == 0)
        {
            diem += 0.25;
        }
        else if (strcmp(a[i].KV, "2NT") == 0)
        {
            diem += 0.5;
        }
        if (diemmax == diem)
        {
            SoThuKhoa[dem++] = a[i];
        }
        diem = 0;
    }
    if (dem == 1)
    {
        printf("\n\t\tThu khoa khoi C co thong tin la:\n");
        xuat1hs(SoThuKhoa[0]);
    }
    else if (dem == 0)
    {
        printf("\n\t\tKhong co thu khoa khoi nay.");
        printf("\n\t\tVui long tim lai.");
    }
    else
    {
        printf("\n\t\tCo %d thu khoa khoi C.", dem);
        printf("\n\t\tThong tin cua tung thu khoa co thong tin nhu sau:\n");
        for (int i = 0; i < dem; i++)
        {
            xuat1hs(SoThuKhoa[i]);
        }
    }
    }
    else
    {
    for (int i = 0; i < sl; i++)
    {
        diem += a[i].test.van+a[i].test.ta+a[i].test.toan;
        if (strcmp(a[i].KV, "1") == 0)
        {
            diem += 0.75;
        }
        else if (strcmp(a[i].KV, "2") == 0)
        {
            diem += 0.25;
        }
        else if (strcmp(a[i].KV, "2NT") == 0)
        {
            diem += 0.5;
        }
        if (diemmax < diem)
        {
            diemmax = diem;
        }
        diem = 0;
    }
    for (int i = 0; i < sl; i++)
    {
        diem += a[i].test.van + a[i].test.ta + a[i].test.toan;
        if (strcmp(a[i].KV, "1") == 0)
        {
            diem += 0.75;
        }
        else if (strcmp(a[i].KV, "2") == 0)
        {
            diem += 0.25;
        }
        else if (strcmp(a[i].KV, "2NT") == 0)
        {
            diem += 0.5;
        }
        if (diemmax == diem)
        {
            SoThuKhoa[dem++] = a[i];
        }
        diem = 0;
    }
    if (dem == 1)
    {
        printf("\n\t\tThu khoa khoi D co thong tin la:\n");
        xuat1hs(SoThuKhoa[0]);
    }
    else if (dem == 0)
    {
        printf("\n\t\tKhong co thu khoa khoi nay.");
        printf("\n\t\tVui long tim lai.");
    }
    else
    {
        printf("\n\t\tCo %d thu khoa khoi D.", dem);
        printf("\n\t\tThong tin cua tung thu khoa co thong tin nhu sau:\n");
        for (int i = 0; i < dem; i++)
        {
            xuat1hs(SoThuKhoa[i]);
        }
    }
    }
}
void timhocsinhLIET(hs a[],int sl,hs hocsinhliet[],int &sohocsinhliet)
{
    int i;
    for (i = 0; i < sl;i++)
    {
        if(a[i].test.van<2 ||a[i].test.ta<1||a[i].test.toan<1)
            {
            hocsinhliet[sohocsinhliet++] = a[i];
            }
        else if(a[i].phanloai==0)
            {
                if(a[i].test.TN.hoa<1 ||a[i].test.TN.ly<1||a[i].test.TN.sinh<1)
                    {
                     hocsinhliet[sohocsinhliet++] = a[i];
                    }
            }
        else if(a[i].phanloai==1)
            {
                if(a[i].test.XH.dia<1 ||a[i].test.XH.gdcd<1||a[i].test.XH.su<1)
                    {
                     hocsinhliet[sohocsinhliet++] = a[i];
                    }
            }    
    }
    if(sohocsinhliet==1)
        {
            printf("\t\tThong tin hoc sinh bi diem LIET\n");
            xuat1hs(hocsinhliet[0]);
        }
    else if(sohocsinhliet==0)
        {
            printf("\t\tKhong co hoc sinh nao bi diem LIET\n");
        }
    else
        {
            printf("\n\t\tCo %d hoc sinh bi diem liet.", sohocsinhliet);
            printf("\n\t\tThong tin cua tung hoc sinh co thong tin nhu sau:\n");
            for (int i = 0; i < sohocsinhliet; i++)
                {
                    xuat1hs(hocsinhliet[i]);
                }
        }
}
void xoachuoi(int &sl, char a[], int k)
{
    int i;
    for(i=k;i<sl-1;i++)
        {
        a[i]=a[i+1];
        }
    sl--;
    a[sl]='\0';//chuỗi
}
void xoaMang(hs a[], int &sl, int vi_tri)
{
	for(int i=vi_tri; i<sl-1; i++)
	{
		a[i] = a[i+1];
	}
	sl--; 
}
void xoahs (hs a[],int &sl)
{
    char SBDCanTim[11];
    int flag = 0;
    do
    {
    fflush(stdin);
    getchar();
    printf("\n\tNhap So Bao Danh cua hoc sinh muon xoa:");
    gets(SBDCanTim);
    } while (strlen(SBDCanTim) != 10);
    for ( int i = 0 ; i< sl; i++) 
	{
		if (strcmp(a[i].sbd,SBDCanTim)==0) 
			{xoaMang(a,sl,i);flag++;}
        
    }
    if(flag==0){printf("\n\tKhong tim duoc hoc sinh nao co so bao danh %s.\n", SBDCanTim);}
    printf("\tNhan Enter de tiep tuc chuong trinh.");
    _getch();
}
void ktkhoangcach(int &sl,char a[])
{
    int i;
    {
    for(i=0;i<sl;i++)
        {
            if(a[0]==' '){xoachuoi(sl,a,0);}
            if(a[i]==' ' && a[i+1]==' ')
                {
                xoachuoi(sl,a,i);
                i--;
                }
            if(a[sl-1]==' '){xoachuoi(sl,a,sl-1);}
        }
    }
}
void inhoadau(char a[])
{
        int i, j;
        j = strlen(a);
        if(a[0]>='a'&& a[0]<='z')//nếu a[0] là thường thì đổi sang IN
        {
            a[0] -= 32;
        }
        for (i = 1; i < j;i++)
            {
            if(a[i-1]==32 && a[i]>='a' && a[i]<='z')
                {
                a[i] -= 32;
                }
            else if(a[i-1]!=32 && a[i]>='A' && a[i]<='Z')
                {
                a[i] += 32;
                }
            }
}
int timkitudau(char a[])
{
    int i, j, dodai;
    dodai = strlen(a);
    j = 0;
    for (i = 0; i < dodai;i++)
        {
            if (a[i]==32)
            {
                j = i + 1;
            }
        }
    return j;
}
void chinhsua(hs a[], int sl)
{
    char SBDCanTim[11];
    int index = -1;
    fflush(stdin);
    getchar();
    do {
        printf("\n\tNhap vao SBD hoc sinh can tim (10 ky tu): ");
        gets(SBDCanTim);
        int i = strlen(SBDCanTim);
        ktkhoangcach(i, SBDCanTim);
        fflush(stdin);

    } while (strlen(SBDCanTim) != 10);
    for (int i = 0; i < sl;i++)
        {
            if (strcmp(SBDCanTim, a[i].sbd) == 0)
                {
                system("cls");
                printf("\n\tHoc sinh ban can tim co cac thong tin nhu sau:\n");
                xuat1hs(a[i]);
                index = i;
                break;
                }
        }
    if(index!=-1)
        {   printf("Nhan ENTER de sua\n");
            loop:
            int test=0;
            nhap1hs(a[index]);
            for(int i=0;i<sl;i++)
                {
                    if(i!=index)
                        {
                            if(strcmp(a[i].sbd,a[index].sbd)==0)
                                test++;
                        }
                }
            if(test!=0)
                {
                    printf("\t\t\tBAN DA TRUNG, MOI NHAP LAI\n");
                    goto loop;
                }
        }
    else
        {
        printf("\n\tKhong tim duoc hoc sinh nao co so bao danh %s.", SBDCanTim);
        }
    printf("\n\tNhan ENTER de tiep tuc chuong trinh.");
    _getch();    
}
//GOOD_JOB