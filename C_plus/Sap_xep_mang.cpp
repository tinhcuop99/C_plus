#include<iostream>
#include<conio.h>
using namespace std;
 void nhap(int a[], int n)
 {
     for (int i = 0; i < n; i++)
     {
         cout << "a["<<i<<"]=";
        cin >> a[i];
     }
     
 }
 
 void xuat(int a[], int n)
 {
     for (int i = 0; i < n; i++)
     {
         cout << a[i] << " ";
     }
          
 }
 void sapxep(int a[], int n)
 {
     for (int i = 0; i < n; i++)
     {
         for (int j = i+1; j < n; j++)
         {
            if( a[i] < a[j] )
            {
                int temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
         }
         
         
     }
     
 }
 int main()
 {

     int A[100];
     int n;
     cout << "Nhap so phan tu:";
     cin >> n;
     cout << "\nNhap mang:" << endl;
     nhap(A,n);

     cout << "\nMang sau khi nhap:";
     xuat(A,n);

     cout << "\nMang sau khi sap xep:";
     sapxep(A,n);
     xuat(A,n);
     
     system("pause");
     getch();
     return 0;
 }