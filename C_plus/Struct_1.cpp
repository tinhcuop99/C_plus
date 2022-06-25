#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
/*struct thong_tin
{
    char name[30];
    int age;
    float chieu_cao;
    float can_nang;
    
};
void nhap_thong_tin(thong_tin s1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " Nhap sinh vien thu " << i+1;
        fflush(stdin);
        cout << " Enter your name ";
        gets(s1[i].name);
        cout << " Enter your age: ";
        cin >> s1[i].age;
        cout << " Enter your height: ";
        cin >> s1[i].chieu_cao;
        cout << " Enter your weight: ";
        cin >> s1[i].can_nang;
    }
    
}
void xuat_thong_tin(thong_tin s1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " Sinh vien thu " << i+1;

        cout << " Name: " << s1[i].name;
        cout << " Age: " << s1[i].age;
        cout << " Height: " << s1[i].chieu_cao;
        cout << " Weight: " << s1[i].can_nang;
    }
    
}*/
struct  sinhvien            
{
    string name;
    int age;
    void nhap_sv()
    {
        cin >> name;
        cin >> age;
    }
    void xuat_sv()
    {
        cout << "Name: " << name << endl;
        cout << " Age: " << age << endl;
    }
};


int main()
{
    int n;  
    fflush(stdin);
    sinhvien s1[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s1[i].nhap_sv();
    }
    for (int i = 0; i < n; i++)
    {
        s1[i].xuat_sv();
    }
    
    system("pause");
    getch();
    return 0;
}
    /*thong_tin s1[10];
    int n;
    cout << " Nhap so luong sinh vien ";
    cin >>n;
    nhap_thong_tin(s1, n);
    xuat_thong_tin(s1, n);
    

  


    system("pause");
    getch();
    return 0;
}*/