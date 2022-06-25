#include<iostream>
#include<conio.h>
using namespace std;

void nhap( int Ar[100][100] , int &m, int &n )
{
    for (int  i = 0; i < m; i++)
    {
        for (int j  = 0; j < n; j++)
        {
            cout << "Ar["<<i<<"]["<<j<<"]=";
            cin >> Ar[i][j];
        }
        
    }
    
}
void xuat(int Ar[100][100], int m, int n)
{
    for (int  i = 0; i < m; i++)
    {
        for (int j  = 0; j < n; j++)
        {
            cout << Ar[i][j] << " ";
        }
        cout << endl;
        
    }
}
int sum_hang(int Ar[100][100], int n, int dong)
{
    int sum = 0;

    for (int j = 0; j < n; j++)
    {
        sum = sum + Ar[dong][j];
        return sum;
    }
}
int main()
{
    int hang, cot;
    int Arr[100][100];

    cout << " Nhap so hang :";
    cin >> hang;
    cout << " Nhap so cot : ";
    cin >> cot;

    cout << " Nhap mang" << endl;

    nhap(Arr,hang,cot);

    cout << " Xuat mang" << endl;
    xuat(Arr,hang,cot);
    int nDong;
    cout << " Nhap so dong can tinh :";
    cin >> nDong;

    cout << " Tong dong can tinh: " << sum_hang(Arr, cot, nDong)<< endl;
    

    
    system("pause");
    getch();
    return 0;
}