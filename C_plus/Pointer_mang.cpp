#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
struct con_nguoi
{

    con_nguoi(string name, int t, float cc)
    {
        ten = name;
        tuoi = t;
        chieu_cao = cc;
    }
    string ten;
    int tuoi;
    float chieu_cao;
};


int main()
{
    con_nguoi team_boy[3]=
    {

    con_nguoi("Thanh", 19, 1.65),
    con_nguoi("Nam", 20, 1.80),
    con_nguoi("Dat", 21, 1.50)

    };
    con_nguoi *bi_an = nullptr;

    for (bi_an = team_boy; bi_an < team_boy + 3; bi_an++)
    {
        cout << (*bi_an).ten << endl;
    }
    
    system("pause");
    getch();
    return 0;
}