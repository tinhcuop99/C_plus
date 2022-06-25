#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
class People
{
private:

    string  name;
    string address;
    int age;
    int id;

public:
   
    People() = default; 

    People(string , string ); // ham tao 2 tham so: name, address

    void nhapInf();
    void showInf();

    void setName(string);
    void setAge(int);
    void setAddress(string);
    void setId(int);

    string getName();
    string getAddress();

    int getAge();
    int getId();
    
};

void People :: nhapInf() // Hàm nhập thong tin
{
    cout << " Nhap ten: " ;
    getline(cin, name);

    cout << " Nhap dia chi:";
    fflush(stdin);
    getline(cin, address);

    cout << " Nhap tuoi: ";
    cin >> age;

    cout << " Nhap ID:";
    cin >> id;
}

 People :: People(string name, string address ) : name(name), address(address){
    
        cout << " Ham tao 2 tham so " << endl;
    }

    void People :: setName(string name)
    {
        this ->name = name;
    }
    void People :: setAge(int age)
    {
        this -> age = age;
    }
    void People :: setAddress(string address)
    {
        this->address = address;
    }
    void People :: setId(int id)
    {
        this -> id = id;
    }

    string People ::getName(){
        return name;
    }
    string People ::getAddress(){
        return  address;
    }

    int People ::getAge(){
        return age;
    }
    
    int People ::getId(){
        return id;

    }

void People :: showInf()
{
        cout <<"=========Your Information========" << endl;
        cout << "Name: " << name<<endl;
        cout << " Age: " << age << endl;
        cout << " Address: " << address << endl;
        cout << " ID: " << id;
}
int main()
{
    People p1;
    p1.nhapInf();
    p1.showInf();
   
    

    
    system("pause");
    getch();
    return 0;
}