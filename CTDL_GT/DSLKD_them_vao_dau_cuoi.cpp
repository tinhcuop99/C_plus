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

// Hàm tìm MAX
int TimMax(LIST l)
{
    int max = l.pHead->data; //  giả sử Node đầu là MAX
    // Duyệt từ node 2 để check
    for (NODE *k = l.pHead ->pNext; k != NULL; k = k->pNext)
    {
        if (max < k ->data)
        {
            max = k ->data; // cập nhật lại MAX
        }
        
    }
    return max;
    
}

int main(){
    LIST l;
    KhoiTao(l); // Khởi tạo DSLKĐ
    int n;
    cout << " Nhap so luong NODE can them";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "  \nNhap gia tri so nguyen ";
        cin >> x;
        NODE *p =KhoiTaoNODE(x); // Khởi tạo 1 cái node sô ngueyen
        ThemVaoCuoi(l, p); // Thêm node p vào đầu danh sách liên kết đơn  !!!NOTE
    }
    cout << "\n DANH SACH LKD" << endl;
    XuatDanhSach(l);

    cout << " TIM MAX " << TimMax(l);
    

    system("pause");
    getch();
    return 0;
}