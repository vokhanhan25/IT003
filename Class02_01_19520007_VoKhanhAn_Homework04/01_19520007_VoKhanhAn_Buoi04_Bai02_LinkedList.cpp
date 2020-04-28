// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 04 - Bài 02
// Ngôn ngữ: C++ / Cài đặt bằng Danh sách liên kết

#include <iostream>
#include <cmath>
#define MAXN 10000

using namespace std;

struct DATA{
    double coefficient, exponent;
};

struct NODE {
    DATA info;
    struct NODE *pNext;
};

struct QUEUE {
    NODE *pHead;
    NODE *pTail;
};

void CreateQueue (QUEUE &q) {
    q.pHead = NULL;
    q.pTail = NULL;
}

NODE* CreateNode (DATA x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

bool IsEmpty (QUEUE q) {
    if (q.pHead == NULL)
        return true;
    return false;
}


bool EnQueue (QUEUE &q, NODE *p) {
    if (IsEmpty(q))
        q.pHead = q.pTail = p;
    else {
        q.pTail->pNext = p;
        q.pTail = p;
    }
}

bool Front (QUEUE &q, DATA &trave) {
    if (!IsEmpty(q)) {
        trave = q.pHead->info;
        return true;
    }
    return false;
}

bool DeQueue (QUEUE &l, DATA &trave) {
    NODE *p;
    if (!IsEmpty(l)) {
        p = l.pHead;
        trave = p->info;
        l.pHead = l.pHead->pNext;
        if (IsEmpty(l)) 
            l.pTail == NULL;
        delete p;
        return true;
    }
    return false;
}

bool Rear (QUEUE &q, DATA &trave) {
    if (!IsEmpty(q)) {
        trave = q.pTail->info;
        return true;
    }
    return false;
}

void OutputQueue(QUEUE q) {
    cout << "QUEUE: FRONT<\t";
    NODE *p = q.pHead;
    while (p != NULL) {
        if (p != q.pHead  && p->info.coefficient >= 0)
            cout << "+ ";
         cout << p->info.coefficient << "x^" << p->info.exponent << " ";
        p = p->pNext;
    }
    cout << ">REAR\n\n";
}

void Init()
{
    cout << "1: EnQueue\n";
    cout << "2: DeQueue\n"; 
    cout << "3: Front\n";
    cout << "4: Rear\n";
    cout << "5: \n";
    cout << "6: IsEmpty\n";
    cout << "7: Thoat khoi chuong trinh!\n";
    cout << "------------------\n\n";
}


int main () {
    QUEUE q; int choose, tm;
    DATA x; double res = 0, xx;
    NODE *p;
    CreateQueue(q);

    while (true) {
        Init();
        if (!IsEmpty(q))
            OutputQueue(q);
        cin >> choose;
        switch (choose) {
            case 1:
                do {
                    cout << "Nhap he so = ";
                    cin >> x.coefficient;
                    cout << "Nhap mu so = ";
                    cin >> x.exponent;
                    p = CreateNode(x);
                    EnQueue(q, p);
                    cout << "Nhan 0 de dung nhap, nhan 1 de tiep tuc!\n";
                    cin >> tm;
                } while (tm != 0);
                cout << "Nhap gia tri x = ";
                cin >> xx;
                cout << "\n";
                break;
            case 2:
                if (!IsEmpty(q)) {
                    DeQueue(q, x);
                    res += x.coefficient * pow(xx, x.exponent);
                    cout << "TONG CUA DA THUC DUOC LAY RA HIEN TAI = " << res << "\n";
                }
                else cout << "Danh sach rong!\n";
                break;
            case 3:
                if (!IsEmpty(q)) {
                    Front(q, x);
                    cout << "Don thuc nam o dau Queue la: ";
                    cout << x.coefficient << "x^" << x.exponent << "\n\n";
                }
                else cout << "Danh sach rong!\n";
                break;
            case 4:
                if (!IsEmpty(q)) {
                    Rear(q, x);
                    cout << "Don thuc nam o cuoi Queue la: ";
                    cout << x.coefficient << "x^" << x.exponent << "\n\n";
                }
                else cout << "Danh sach rong!\n";
                break;
            case 5:
            
                break;
            case 6:
                if (IsEmpty(q))
                    cout << "Queue bi rong!\n\n";
                else cout << "Queue KHONG rong!\n\n";
                break;
            case 7:
                cout <<"EXIT\n";
                return 0;
            default:
                cout << "Lua chon khong hop le, vui long nhap lai:\n";
        }
    }
}