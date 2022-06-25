#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
    int data; // dữ liệu của node ==> dữ liệu mà node lưu trữ
    struct node *pLeft; // node liên kết bên trái của cây <=> cây con trái
    struct node *pRight; // node liên kết bên phải của cây <=> cây con phải
};
typedef struct  node NODE;
typedef NODE *TREE;

void KhoiTaoCay(TREE &t)
{
    t = NULL; // cây rỗng
}
// hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(TREE &t, int x)
{
    if (t == NULL) // nếu cây rỗng
    {
        NODE *p = new NODE; // khởi tạo 1 node để thêm vào cây
        p->data =x; // thêm dữ liệu x vào data
        p->pLeft =NULL;
        p->pRight = NULL;
        t =p; // node p chính là node gốc <=> x chính là node gốc
    }
    else  // cây tồn tịa phần tử
    {
        if (t->data > x) // nếu thêm phần tử mà nhỏ hơn node gốc thì thêm vào bên trái
        {
            ThemNodeVaoCay(t->pLeft, x); // duyệt qua trái dể thêm phần tử x
        }
        else if (t->data < x) //// nếu thêm phần tử mà lớn hơn node gốc thì thêm vào bên phải
        {
            ThemNodeVaoCay(t->pRight, x); // duyệt qua phải dể thêm phần tử x
        }
        
        
    }
    
}

void Duyet_NLR(TREE t) // DUYỆT CÂY NHỊ PHÂN NLR
{
    if (t!= NULL) // nếu cây cồn phần tử thì tiếp tục duyệt
    {
        cout << t->data << " "; // xuất dữ liệu trong node
        Duyet_NLR(t->pLeft); // duyệt qua trái
        Duyet_NLR(t->pRight); // duyệt qua phải
    }
    
}
void Duyet_NRL (TREE t)  // DUYỆT CÂY NHỊ PHÂN NRL
{
    if (t != NULL)
    {
        cout << t->data << " ";
        Duyet_NRL(t->pRight);
        Duyet_NRL(t->pLeft);
    }
    
}
void Duyet_LNR(TREE t) // DUYỆT CÂY NHỊ PHÂN LNR <=> sắp xếp từ bé đến lớn
{
    if (t != NULL)
    {
    Duyet_LNR(t->pLeft);
    cout << t->data << " ";
    Duyet_LNR(t->pRight);
    }
}
void Duyet_RNL(TREE t) // DUYỆT CÂY NHỊ PHÂN LNR <=> sắp xếp từ lớn ---> bé
{
    if (t != NULL)
    {
    Duyet_RNL(t->pRight);
    cout << t->data << " ";
    Duyet_RNL(t->pLeft);
    }
}
void Duyet_LRN(TREE t) 
{
    if (t != NULL)
    {
    Duyet_LRN(t->pRight);
    Duyet_LRN(t->pLeft);
    cout << t->data << " ";
    }
}
void Duyet_RLN(TREE t) 
{
    if (t != NULL)
    {
    Duyet_LRN(t->pRight);
    Duyet_LRN(t->pLeft);
    cout << t->data << " ";
    }
}
// HÀM KIỂM TRA SỐ NGUYÊN TỐ
bool KiemTraSNT(int x)
{
    if ( x < 2)         
    {
        return false;
    }
    else
    {
        if (x ==2)
        {
            return true;
        }
        else 
        {
            if (x % 2==0)
            {
                return false;
            }
            else{
                for (int i = 2; i < x; i++)
                {
                    if (x % i == 0)
                    {
                        return false;
                    }
                    
                }
                
            }
            
        }
        
    }
    return true;
    
}

// HÀM ĐẾM SỐ LƯỢNG SỐ NGUYÊN TỐ
void SoLuongSNT(TREE t, int &dem)
{
    if (t!= NULL) // nếu cây cồn phần tử thì tiếp tục duyệt
    {
        // xử lí
        if (KiemTraSNT(t->data) == true)
        {
            dem++;
        }
        
        cout << t->data << " "; // xuất dữ liệu trong node
        SoLuongSNT(t->pLeft, dem); // duyệt qua trái
        SoLuongSNT(t->pRight, dem); // duyệt qua phải
    }
    
}

// hàm nhập dữ liệu
void Menu(TREE &t)
{
    while (true)
    {
        system("cls");
        cout << "\n======================";
        cout << "\n1. Nhap du lieu";
        cout << "\n2. Xuat du lieu cay NLR";
        cout << "\n3. Xuat du lieu cay NRL";
        cout << "\n4. Xuat du lieu cay LNR";
        cout << "\n5. Xuat du lieu cay RNL";
        cout << "\n6. Xuat du lieu cay LRN";
        cout << "\n7. Xuat du lieu cay RLN";
        cout << "\n8. So luong SNT";

        cout << "\n0. Thoat";
        cout << "\n======================";

        int luachon;
        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon < 1 || luachon > 8)
        {
            cout << "\nNhap sai lua chon";
            system("pause");
        }

        else if (luachon == 1)
        {   int x;
            cout << "\nNhap so nguyen x: ";
             cin >> x;
            ThemNodeVaoCay(t,x);
        }
        else if (luachon == 2)
        {  
            cout << "\nDuyet cay theo NLR ";
        
            Duyet_NLR(t);
            system("pause");
        }
        else if (luachon == 3)
        {  
            cout << "\nDuyet cay theo NLR ";
        
            Duyet_NRL(t);
            system("pause");
        }
        else if (luachon == 4)
        {  
            cout << "\nDuyet cay theo LNR ";
        
            Duyet_LNR(t);
            system("pause");
        }
        else if (luachon == 5)
        {  
            cout << "\nDuyet cay theo RNL ";
        
            Duyet_RNL(t);
            system("pause");
        }
        else if (luachon == 6)
        {  
            cout << "\nDuyet cay theo LRN ";
        
            Duyet_LRN(t);
            system("pause");
        }
        else if (luachon == 7)
        {  
            cout << "\nDuyet cay theo RLN ";
        
            Duyet_LRN(t);
            system("pause");
        }
        else if (luachon == 8)
        {  
            int dem =0;
            SoLuongSNT(t, dem);
            cout << "\nSo luong so nguyen to  " << dem;
        
            
            system("pause");
        }
        else
        {
            break;
        }

        
        
    }
    
}



int main(){
    TREE t;
    KhoiTaoCay(t);
    Menu(t);

    system("pause");
    return 0;
}