#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int a[100];
    int n;
    cout << " Nhap so phan tu cua mang: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a["<<i<<"]=";
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] <<" ";
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i]==a[j])
            {               
                for ( int k = i; k < n-1; k++)
                {
                    a[k] = a[k+1];
                    n--;
                    i--;
                }
                
            }
            
        }
        
    }
    cout << " Mang sau khi xoa phan tu trung nhau" << endl;
    for (int i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }
    
    
    

    system("pause");
    getch();
    return 0;
}