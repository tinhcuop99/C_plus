#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
class  People
{
private:
    /* data */
public:
    string  name;
    string address;
    int age;
    int id;

    void showInf()
    {

    }

     People(/* args */);
    ~ People();
};

 People:: People(/* args */)
{
}

 People::~ People()
{
}

int main()
{
    People p1;
    p1.name = " Thanh";
    p1.age = 19;
    cout << " Tuoi: " << p1.age;
    system("pause");
    getch();
    return 0;
}