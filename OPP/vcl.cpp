#include<iostream>
#include<conio.h>

using namespace std;
class ConNguoi
{
private:
    string name;
    string diachi;
    int id;
    int age;
    float chieucao;
    float cannang;

public:
   // ConNguoi() =default;
    ConNguoi(string name, string diachi, int id, int age, float chieucao, float cannang) {
        this->name=name;

    }
    string getname(){
        return name;
    }
    string getdiachi(){
        return diachi;
    }
    int getid(){
        return id;
    }
    int getage(){
        return age;
    }
    float getchieucao(){
        return chieucao;
    }
    float getcannang(){
        return cannang;
    }

    
};


int main()
{
    ConNguoi p("Tran Dang Thanh", "Nghe An",2002,19, 1.7,55.6);

    cout << "Name:" << p.getname() << endl;
    system("pause");
    getch();
    return 0;
}