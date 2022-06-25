#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
struct people
{
    string name;
    string gioi_tinh;
    int id;
    int age;
    float Toan;
    float Ly;
    float Anh;
};
int id_lon_nhat(people a[], int n)
{
    int idmax = 0;
    if( n> 0)
    {
        idmax = a[0].id;
        for (int i = 0; i < n; i++)
        {
            if(a[i].id > idmax)
            {
                idmax= a[i].id;
            }
        }
        
    }
    return idmax;
}

void nhap_thong_tin(people p1)
{
    cout <<" ==================================" << endl;
    cout << " Nhap ten :" ;
    getline(cin, p1.name);
    cout << " Nhap gioi tinh: ";
    getline(cin, p1.gioi_tinh);
    cout << " Nhap ID :" ;
    cin >> p1.id;
    cout << " Nhap tuoi :";
    cin >> p1.age;
    cout << " Nhap diem Toan :";
    cin >> p1.Toan;
    cout << " Nhap diem Ly :";
    cin >> p1.Ly;
    cout << " Nhap diem Anh :";
    cin >> p1.Anh;
    cout <<" ==================================";
}
void nhap_sv(people a[n], int id, int n)
{
    cout << " Nhap sinh vien vien thu" << 
    nhap_thong_tin();
    
}
void cap_nhap_thong_tin()
{

}
void xuat_thong_tin(people p1)
{
    cout <<" ==================================" << endl;
    cout << " Your name: " << p1.name << "\n";
    cout << " Your sex:" << p1.gioi_tinh<< "\n";
    cout << " Your ID: " << p1.id << "\n";
    cout << " Your age:" << p1.age << "\n";
    cout << " Diem Toan: " << p1.Toan << "\n";
    cout << " Diem Ly: " << p1.Ly << "\n";
    cout << " Diem Anh: " << p1.Anh << "\n";
    cout <<" ==================================";
}
void them_thong_tin(people p1)
{

}
int main()
{
    people p1;
    int so_luong_sv;


    
    nhap_thong_tin(p1);

    xuat_thong_tin(p1);
    


    
    system("pause");
    getch();
    return 0;
}