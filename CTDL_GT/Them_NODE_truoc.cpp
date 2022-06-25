#include<iostream>
#include<conio.h>

using namespace std;
// Nhập danh sách liên kết đơn các số nguyên. Tìm MAX trong danh sách
//KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN
// Khai báo cấu trúc 1 node
struct node
{
    int data; // Dữ liệu chứa trong 1 node
    struct node *pNext; // Con trỏ dùng để lien kết giữa các node với nhau
};
typedef struct node NODE; // Thay thế struct node thành NODE...C, C++

// Khai báo cấu trúc danh sách liên kết
struct list
{
    NODE *pHead; // Node quản lí đầu danh sách
    NODE *pTail; // Node quản lí cuối danh sách
};
typedef struct list LIST; // thay thế struct list thành LIST

// KHỞI TẠO CẤU TRÚC DSLKĐ CÁC SỐ NGUYÊN

void KhoiTao(LIST &l)
{
    // Cho 2 node trỏ đến NULL vì danh sách chưa có phần tử nào
    l.pHead = NULL;
    l.pTail = NULL;
}

// Hàm khởi tạo 1 node
NODE *KhoiTaoNODE(int x)
{
    NODE *p =new NODE ;// Cấp phát vùng nhớ cho NODE p
    // Không cần thiết, chỉ là tìm hiểu thêm
    if ( p ==NULL)
    {
        cout << " Bo nho day ";
        return NULL;
    }
     // 
    
    p->data = x; // Truyền giá trị x cho data
    p ->pNext = NULL; // khơi báo NODE thì node đó chưa có liên kết nào ---> con trỏ trỏ đến NULL
    return p; // Trả về NODE p vừa khởi tạo

}
    // Hàm thêm NODE vào đầu danh sách LK
void ThemVaoDau(LIST &l, NODE *p)
{
    if (l.pHead == NULL ) // Danh sách đang rỗng
    {
        l.pHead = l.pTail = p; // NODE đầu cũng chính là NODE cuối và là p
    }
    else {
        p -> pNext = l.pHead ;  // cho con trỏ của node cần thêm là node p liên kết đến node đầu p Head
        l.pHead = p; // cập nhật lại pHead chính là Node p
    }
    
}
 // Hàm thêm NODE vào cuối danh sách LK
void ThemVaoCuoi(LIST &l, NODE *p)
{
    if (l.pHead == NULL ) // Danh sách đang rỗng
    {
        l.pHead = l.pTail = p; // NODE đầu cũng chính là NODE cuối và là p
    }
    else {
        l.pTail ->pNext = p; // cho con trỏ của pTail liên kết với node p
        l.pTail = p; // cập nhật lại p là node PTail 
        
    }
    
}
// hàm xuất DSLKĐ
void XuatDanhSach(LIST l)
{
    for (NODE *k = l.pHead; k!= NULL; k = k ->pNext)
    {
        cout << k ->data << " " ;
    }
    
}
void ThemNode(LIST &l, NODE *p)
{
    int x;
    cout << "\nNhap gia tri NODE";
    cin >> x;
    NODE *q = KhoiTaoNODE(x);

    // Nếu danh sách chỉ có 1 phần tử và chính là NODE q ---> kĩ thuật thêm vào cuối
    if(q->data == l.pHead->data && l.pHead->pNext == NULL)
    {
        ThemVaoCuoi(l,p);
    }
    else
    {
    // Duyệt từ đầu để tìm node q
            for(NODE *k = l.pHead; k!= NULL; k= k->pNext)
            {
                // nếu q tồn tại
                if ( q->data == k->data)
                {
                    // Cho node g trỏ đến node nằm sau node q
                    NODE *h =KhoiTaoNODE(p->data); // Khởi tạo node h mới để thêm vào sau node q
                    NODE *g = k->pNext;  
                    p -> pNext = g; // B1: Tạo mối liên kết từ node h đến g , tạo mối liên kết từ node h đến node nằm sau node q 
                    k->pNext = p; // B2: tạo mối liến kết từ node q đến h <=> chính là node k đến h
                }
                
            }
    }
}
void Menu(LIST &l)
{
    int luachon;
    while (69)
    {
        system("cls");
        cout << "\n\n\t\t=============MENU=============";
        cout << "\n\t1.Them Node vao danh sach";
        cout << "\n\t2.Xuat danh sach lien ket don";
        cout << "\n\t3.Them Node";
        cout << "\n\t0. Thoat man hinh";
        cout << "\n\n\t\t==============END==============";
        cout << endl;

        cout << " Nhap lua chon";
        cin >>luachon;

        if (luachon < 0 || luachon >3)
        {
            cout << " Nhap sai. Moi ban kiem tra lai";
            system("pause");
        }
        else if(luachon ==1)
        {
            int x;
            cout << "Nhap gia tri so nguyen";
            cin >> x;
            NODE *p = KhoiTaoNODE(x);
            ThemVaoCuoi(l,p);
        }
        else if (luachon == 2)
        
        {
           XuatDanhSach(l);
           system("pause");
        }

        else if (luachon == 3)
        {
            int x;
            cout << " Nhap gia tri can them";
            cin >> x;
            NODE *p = KhoiTaoNODE(x);
            ThemNode(l,p); // Thêm node vào sau

        }
        else {
            break;
        }
        
    }

}


int main(){
   LIST l;
   KhoiTao(l);
   Menu(l);
    
    
    system("pause");
    getch();
    return 0;
}