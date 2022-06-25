#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

// KHAI BÁO CẤU TRÚC 1 NODE

struct node
{
    string data;
    struct node *pNext;  // liên kết các node với nhau
};
typedef struct node NODE;

// KHAI BÁO CẤU TRÚC LIÊN KẾT
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

// HÀM KHỞI TẠO
void KhoiTao(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

// HAM KHOI TAO 1 NODE

NODE *KhoiTaoNode(string x)
{
    NODE *p = new NODE;
    p->data = x;
    p->pNext = NULL;
    return p;
}

void ThemVaoDau(LIST &l, NODE *p)
{
    // Kiem tra danh sach lien ket don 
    // Danh sach NULL or neu pHead = ptail = p  thi node cdau cungx la node cuoi = p
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail =p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
    
}

void ThemVaoCuoi(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail =p;
    }
    else
    {
        l.pTail ->pNext = p;
        l.pTail = p;
    }
}

// Ham xuat danh sach

void XuatDanhSach(LIST l)
{
    for(NODE *k = l.pHead; k!= NULL; k=k->pNext)
    {
        cout << k->data << " ";
    }
}


int main()
{
    LIST l;
    KhoiTao(l);
    int n;
    cout << " Nhap so luong node can them";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        string x;
        cout << "\n Enter your name ! ";
        cin >> x;
        NODE *p = KhoiTaoNode(x);
        ThemVaoDau(l,p);
    }

    cout <<" \nDanh sach lien ket don " << endl;
    XuatDanhSach(l);
    


    system("pause");
    getch();
    return 0;
}