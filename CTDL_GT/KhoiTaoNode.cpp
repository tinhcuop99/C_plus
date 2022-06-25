#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{       
    int data;
    Node *next;
};


int main(){
    
    Node *head = new Node();
    head ->data = 1;
    head ->next = NULL;

    Node *second = new Node();
    second ->data =2;
    second ->next= NULL;

    Node *third = new Node();
    third ->data =3;
    third ->next =NULL;

    // Liên kết các Node lại với nhau
    head ->next = second;
    second ->next =third;

    //Truy cập
    // Truy cập head

    int data = head ->data;
    cout << data << endl;

    Node *p = head;
    while (p!= NULL)            
    {
        data = p ->data;
        p = p->next;
        cout << data << " -> ";
    }
    cout << endl;

    //Node 1 chứa địa chỉ node 2, node 2 chứa địa chỉ node 3,...cuối cùng trỏ đến NULL.
    




    system("pause");
    getch();
    return 0;
}