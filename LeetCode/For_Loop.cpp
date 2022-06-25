#include<iostream>
#include<conio.h>

using namespace std;

int main(){
    int a[100];

    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
        if (a[i] >= 1 && a[i] <=9)
        {
            cout << "Hello Bro!";
        }
        
        if (a[i]%2 == 0 )
        {
            cout << a[i] << " la mot so chan";
        }

        if (a[i]%2 == 1)
        {
            cout << a[i] << "la mot so le";
        }
        
    }


    system("pause");
    getch();
    return 0;
    }