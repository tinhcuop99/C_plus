#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
class Student
{
private:
    int id;
    int age;
    int score;
    string name;
    string address;
public:
    Student() =default;

    void nhap();
    void xuat();

    void setid(int);
    void setage(int);
    void setscore(int);
    void setname(string);
    void setaddress(string);

    int getid();
    int getage();
    int getscore();
    string getname();
    string getaddress();
    
};


void Student ::nhap()
{
     cout << " Nhap ten: " ;
     fflush(stdin);
    getline(cin, name);

    cout << " Nhap dia chi:";
    fflush(stdin);
    getline(cin, address);

    cout << " Nhap tuoi: ";
    cin >> age;

    cout << " Nhap ID:";
    cin >> id;

    cout << " Nhap diem:";
    cin >> score;
}

void Student :: setname(string name)
{
    this ->name=name;
}
void Student :: setage(int age)
{
    this ->age =age;
}
void Student :: setid(int id)
{
    this ->id = id;
}
void Student :: setaddress(string address)
{
    this ->address=address;
}
void Student :: setscore(int score)
{
    this ->score=score;
}


string Student :: getname()
{
    return name;
}
int Student :: getage()
{
    return age;
}
int Student :: getid()
{
    return id;
}
string Student :: getaddress()
{
    return address;
}
int Student :: getscore()
{
    return score;
}

void Student :: xuat()
{
        cout <<"=========Your Information========" << endl;
        cout << "Name: " << name<<endl;
        cout << " Age: " << age << endl;
        cout << " Address: " << address << endl;
        cout << " ID: " << id << endl;
        cout << " Score: " << score << endl;
}

int main()
{
    Student p1;
    Student p2;

    p1.nhap();
    p1.xuat();
    
    cout << " ===================================" << endl;

    p2.nhap();
    p2.xuat();


    system("pause");
    getch();
    return 0;
}