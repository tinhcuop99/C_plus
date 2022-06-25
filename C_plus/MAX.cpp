#include<iostream>
#include<conio.h>

using namespace std;


int main()
{
    int a[100];
    int n;
    cout << " Nhap so luong phan tu: ";
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        cout << "a["<<i<<"]: " ;
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    int max;
    for (int i = 0; i < n; i++)
    {
        max = a[0];
    
        if (a[i] > a[0])
        {
             max = a[i];
             
        }
               
    }
     cout << " Max: " << max << endl;
     int min;
     for (int i = 0; i < n; i++)
    {
        min = a[0];
    
        if (a[i] < a[0])
        {
             min = a[i];
             
        }
               
    }
    cout << "Min: " << min;

    system("pause");
    getch();
    return 0;
}