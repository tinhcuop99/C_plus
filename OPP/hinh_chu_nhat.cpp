#include<iostream>
#include<conio.h>

using namespace std;
class Hcn
{
private:
    int cd;
    int cr; 

public:
Hcn()= default;
    Hcn(int, int);

    void nhap();
    void xuat();

    void setCd(int);
    void setCr(int);

   int getCd();
    int getCr();

    int getDt();
    int getCv();
};

void Hcn :: nhap(){
    cout << " Nhap chieu dai";
    cin >> cd;

    cout << " Nhap chieu rong";
    cin >> cr;
}

void Hcn :: setCd(int cd)
{
    this->cd = cd;

}
void Hcn ::setCr(int cr){
    this->cr = cr;
}

int Hcn ::getCd(){
    return cd;
}

int Hcn :: getCr(){
    return cr;
}

int Hcn ::getDt()
{
    return cd*cr;
}
int Hcn ::getCv()
{
    return (cd+cr)*2;
}
void Hcn::xuat()
{
    cout << " Chieu dai" << cd << endl;
    cout << " Chieu rong" << cr << endl;
    cout << " Dien tich:" << getDt() << endl;
    cout << " Chu vi: " << getCv();
}
int main(){

    Hcn h;
    h.nhap();
    h.xuat();




    system("pause");
    getch();
    return 0;
}