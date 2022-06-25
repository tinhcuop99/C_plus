#include<iostream>
#include<conio.h>
int n = 0; // Khai báo biến toàn cục - Chứa số lượng phần tử tron ds

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
void ThemNodeSau(LIST &l, NODE *p)
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
void ThemNodeTruoc(LIST &l, NODE *p) // Thêm node p vào trước node q
{
        int x;
        cout << "\n Nhap gia tri node q: ";
        cin >> x;
        NODE *q = KhoiTaoNODE(x); // Khởi tạo 1 node q
        // Nếu danh sách chỉ có 1 phần tử --> Thêm vào đầu danh sách
        if (q->data ==l.pHead->data && l.pHead->pNext == NULL)
        {
            ThemVaoDau(l,p); /// Thêm node p vào đầu danh sách
        }
        else
        { /* CÁCH 1: Trong danh sách chỉ tồn tại 1 node q
            NODE *g = new NODE; // Node g là node giữ nối liên kết với các node nằm trước
            for(NODE *k = l.pHead; k!= NULL; k=k->pNext)
            {
                // Phát heienj node q tồn tại trong ds thì bắt đầu thêm node p vào trước node q
                if (q->data == k->data)
                {
                    p->pNext = k; // B1: Cho Node q trỏ( liên kết ) đến node k
                    g->pNext = p; // B2: Cho node g trỏ đến node p
                }
                g = k; // giữ liên kết với node nàm trước q trong danh sách
            }
            */
            // CÁCH 2: Trong sanh sách tồn tại 2 node q trở lên
            NODE *g = new NODE; // node g chính lafnode giữ liên kết với node nằm trước node q 
            // duyệt danh sách từ đâu đến cuối để tìm node q
            for(NODE *k = l.pHead; k!= NULL; k=k->pNext)
            {
                // phát hiện node q có tồn tại  trong danh sách thì bắ đầu thêm node p vào trước node q
                if (q->data == k->data)
                {
                    NODE *h = KhoiTaoNODE(p->data); // mỗi lần phát hiện node p mới <=> khởi tạo node

                    h->pNext = k;
                    g->pNext = h;
                }
                g=k;
                
            }
        }
        
}
///=====Thêm node vào vị trí bất kì=====
// Duyệt danh sách từ đầu đến cuối
// Phát hiện vị trí đúng vị trí cần thêm
// Giống phương pháp thêm Node trước Node khác ( đã học )
// nên đặt điều kiện "vitri" tranh chương tình bị lỗi
// CÁCH 1
/*
void ThemNodeVao_ViTriBatKi(LIST &l, NODE *p, int vt, int n)
{
    
    
    // Kiểm tra danh sách đang rỗng
    if (l.pHead == NULL || vt ==1)
    {
        // Thêm node p vào đầu danh sách 
        ThemVaoDau(l,p);
    }
    else if (vt == n+1)
    {
        ThemVaoCuoi(l,p);
    }
    else {
        int dem =0; // xác định vị trí cần thêm
        NODE *g = new NODE; // node g chính lafnode giữ liên kết với node nằm trước node q 
            // duyệt danh sách từ đâu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào
            for(NODE *k = l.pHead; k!= NULL; k=k->pNext)
            {
                dem++;
                // tìm vị trí vt cần thêm
                if (dem == vt)
                {
                    NODE *h = KhoiTaoNODE(p->data); // mỗi lần phát hiện node p mới <=> khởi tạo node

                    h->pNext = k;
                    g->pNext = h;
                    break;
                }
                g=k;
                
            }
    }
    
    
} 
*/
// CÁCH 2: DÙN BIẾN TOÀN CỤC CHO BIẾN n
void ThemNodeVao_ViTriBatKi(LIST &l, NODE *p, int vt)
{
    
    
    // Kiểm tra danh sách đang rỗng
    if (l.pHead == NULL || vt ==1)
    {
        // Thêm node p vào đầu danh sách 
        ThemVaoDau(l,p);
    }
    else if (vt == n+1)
    {
        ThemVaoCuoi(l,p);
    }
    else {
        int dem =0; // xác định vị trí cần thêm
        NODE *g = new NODE; // node g chính lafnode giữ liên kết với node nằm trước node q 
            // duyệt danh sách từ đâu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào
            for(NODE *k = l.pHead; k!= NULL; k=k->pNext)
            {
                dem++;
                // tìm vị trí vt cần thêm
                if (dem == vt)
                {
                    NODE *h = KhoiTaoNODE(p->data); // mỗi lần phát hiện node p mới <=> khởi tạo node

                    h->pNext = k;
                    g->pNext = h;
                    break;
                }
                g=k;
                
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
        cout << "\n\t3.Them Node p vao sau node q trong danh sach";
        cout << "\n\t4.Them Node p vao truoc node q trong danh sach";
        cout << "\n\t5.Them Node p vao vi tri bât ki trong danh sach";
        cout << "\n\t0. Thoat man hinh";
        cout << "\n\n\t\t==============END==============";
        cout << endl;

        cout << "Nhap lua chon : ";
        cin >>luachon;

        if (luachon < 0 || luachon > 5)
        {
            cout << " Nhap sai. Moi ban kiem tra lai";
            system("pause");
        }
        else if(luachon ==1)
        {   n++; // cách 2
            int x;
            cout << "Nhap gia tri so nguyen: ";
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
            cout << " Nhap gia tri node p can them vao sau:";
            cin >> x;
            NODE *p = KhoiTaoNODE(x);
            ThemNodeSau(l,p); // Thêm node vào sau

        }
        else if (luachon == 4)
        {
            int x;
            cout << " Nhap gia tri node p can them vao truoc:";
            cin >> x;
            NODE *p = KhoiTaoNODE(x);
            ThemNodeTruoc(l,p); // Thêm node vào truoc
        }
        else if (luachon == 5)
        {    /* CÁCH 1
            int n=0;
            //vòng lặp lấy số lượng node trong danh sách
            for(NODE *k = l.pHead; k!= NULL; k =k->pNext)
            {
                n++;
            }
            */
           
            // Khởi tạo giá trị cho node p
            int x;
            cout << " \nNhap gia tri node p: ";
            cin >> x;
            NODE *p = KhoiTaoNODE(x);
            // Nhạp vị trí cần thêm cho node p ===> Kiểm tra điều kiện vào

            int vt;
            do
            {
                cout << " Nhap vi tri can them node p: ";
                cin >>  vt;
                if ( vt < 1 || vt > n+1 )
                {
                    cout << "\nVi tri can them phai nam trong doan[1; "<< n+1 << "]";
                    system("pause");
                }
                
            } while (vt<1 || vt > n+1);
                //ThemNodeVao_ViTriBatKi(l,p,vt,n);  CÁCH 1 
                ThemNodeVao_ViTriBatKi(l,p,vt); // CÁCH 2
                    
            
        }
        else {
            break;
        }
        
    }

}

/*
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
*/
int main(){
   LIST l;
   KhoiTao(l);
   Menu(l);
    
    
    system("pause");
    getch();
    return 0;
}