#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
class People
{

public:
    string  name;
    string address;
    int age;
    int id;
  People() : name("\0"), address("\0"), age(0), id(0)
    {
        cout << " ham tao mac dinh";
        
    }
    
    
    People(string name, string address) : name(name), address (address), age(0), id(0)
    {
        cout << " ham tao 2 tham so" << endl;
       
    }
    void nhapInf()
    {
        cout << " Nhap thong tin" << endl;
        getline(cin, name);
        fflush(stdin);
        getline(cin, address);
    }
    void showInf()
    {
        cout <<"=========Your Information========" << endl;
        cout << "Name: " << name<<endl;
        cout << " Age: " << age << endl;
        cout << " Address: " << address << endl;
        cout << " ID: " << id;
    }

     ~People()
{
    cout << " Goi ham huy";
}
    
};


int main()
{
    string name;
    string address;
    
    People p1();
    People p2(name,address);
    p2.nhapInf();
    
    p2.showInf();
    

   
    system("pause");
    getch();
    return 0;
}