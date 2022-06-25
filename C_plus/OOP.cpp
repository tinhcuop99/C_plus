#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
class People
{

public:
    string name;
    int age;
    string adress;
    void nhap_thongtin()
    {
        cin >> name;
        cin >> age;
        cin >> adress;
    }
    void xuat_thongtin()
    {
        cout << " Name: " << name << endl;
        cout << " Age: " << age << endl;
        cout << " Dia chi: " << adress;
    }

    People();
    ~People();
};


int main()
{
    People p1;
    p1.nhap_thongtin();
    p1.xuat_thongtin();

    system("pause");
    getch();
    return 0;
}