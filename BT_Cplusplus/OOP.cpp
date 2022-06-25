#include<iostream>
#include<conio.h>
using namespace std;
class Car
{
private:
    string name;
    int id;
public:
    Car() = default ;
    Car(string, int);   

    void nhapInf();
    void xuatInf();

    void setName(string);
    void setId(int);

    string getName();
    int getId();

};

void Car ::nhapInf()
{
    cout << " Nhap ten xe: ";
    getline(cin, name);

    cout << " Nhap ID: ";
    cin >> id;
}
Car :: Car (string name, int id) : name(name), id(id)
{
        cout << " Ham tao 2 tham so";
}
void Car :: setName(string){
    this ->name =name;
}
void Car ::setId(int){
    this ->id =id;
}

string Car :: getName(){
    return name;
}
int Car ::getId(){
    return id;
}

void Car ::xuatInf(){
    cout << "======================";
    cout << "\nTen hang o to: " << name;
    cout << "\nID hang: " << id;

}

int main()
{
    Car c1;
    c1.nhapInf();
    c1.xuatInf();

    system("pause");
    getch();
    return 0;
}