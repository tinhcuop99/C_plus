#include<iostream>
#include<string.h>
#include<conio.h>
#include<string.h>

using namespace std;
struct  thongtin
{
    string name;
    int age;
    float height;
    float weight;
};

string chiso_bmi(thongtin n1)
{
    float bmi = n1.weight / ( n1.height*n1.height);
    cout << " Chi so BMI cua ban " << n1.name << " " << bmi << endl;

    string ket_qua ;
    if(bmi < 15)
    {
        ket_qua = " Gay vl";
    }
    else if(bmi > 25 )
    {
        ket_qua = " Beo vl";
    }
    else
    {
        ket_qua = " Dep trai";
    }
    //cout << " Chi so BMI :" << ket_qua;
    return ket_qua;
}
void thoi_gian( thongtin n1, int nam_troi)
{
    for (int i = 0; i < nam_troi; i++)
    {
        n1.weight += 1;
    }
    string ket_qua = chiso_bmi(n1);
    cout << " Ban " << n1.name << nam_troi << " nam troi qua se " << ket_qua;
}

int main()
{
    thongtin n1;
     
   
    cout << " Enter your name: ";
    getline(cin, n1.name);
    
    cout << " Enter your weight";
    cin >> n1.weight;
    cout << " Enter your height";
    cin >> n1.height;
    
   //chiso_bmi(n1);
   thoi_gian(n1, 20);
    thongtin *pointer = &n1;
    

    system("pause");
    getch();

}