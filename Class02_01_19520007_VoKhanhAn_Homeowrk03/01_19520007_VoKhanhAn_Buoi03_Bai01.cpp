// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 03 - Bài 01
// Ngôn ngữ: C++

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct NODE
{
    long info;
    struct NODE *pNext;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

void CreateEmptylist (LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE* CreateNode (long x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

bool IsEmpty (LIST &l)
{
    if (l.pHead == NULL)
        return true;
    return false;
}

void AddHead (LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail (LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void InputList(LIST &l, long &n)
{
    int x; NODE *p;
    cout << "NHAP THU CONG: \n";
    cout << "SO LUONG PHAN TU = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "NHAP PHAN TU THU " << i + 1 << " : ";
        cin >> x;
        p = CreateNode(x);
        if (p != NULL)
            AddTail (l,p);
    }
    
    cout << endl;

    long m = 39 + rand () % 21;
    n = n + m;
    while (m > 0) {
        x = -99 + rand() % 199;
        p = CreateNode (x);
        if (p != NULL)
            AddHead(l, p);
        m--;
    }
    cout <<"DA NHAP TU DONG XONG! \n";
}

void OutputListP(LIST l)
{
    NODE *p = l.pHead;
    cout << endl;
    cout << "CAC GIA TRI & DIA CHI NODE CUA DSLK HIEN TAI LA: " << endl;
    while (p != NULL)
    {
        cout << p->info << " " << p << endl;
        p = p->pNext;
        cout << endl;
    }
    cout << endl;
}

void OutputListV(LIST l)
{
    NODE *p = l.pHead;
    cout << "CAC GIA TRI CUA DSLK HIEN TAI LA: " << endl;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

bool SearchNode(LIST l, long x, NODE *k)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (x == p->info) {
            k = p;
            return true;
        }
        p = p->pNext;
    }
    return false;
}

bool RemoveHead(LIST &l, long &x)
{
    NODE *p;
    if (l.pHead != NULL)
    {
        x = l.pHead -> info;
        p = l.pHead;
        l.pHead = l.pHead -> pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
        delete p;
        return true;
    }
    return false;
}

bool RemoveAfterQ (LIST &l, NODE *Q, long &x)
{
    NODE *p;
    if (Q != NULL) {
        NODE *p = Q -> pNext;
        Q -> pNext = p -> pNext;
        x = p -> info;
        if (p == l.pTail)
            l.pTail = Q;
        delete p;
        return true;
    }
    return false;
}

bool RemoveX(LIST &l, long x)
{
    NODE *Q = NULL, *p = l.pHead;
    while (p != NULL && p->info != x)
    {
        Q = p;
        p = p -> pNext;
    }

    if (p == NULL) return false;
    if (Q != NULL) RemoveAfterQ(l, Q, x);
    else RemoveHead(l, x);

    return true;
}

bool SetX(LIST &l, long y, long x)
{
    NODE *p = l.pHead;
    bool ok = false;
    while (p != NULL)
    {
        if (y == p->info) {
            p->info = x;
            ok = true;
        }
        p = p->pNext;
    }
    if (ok) return true;
    return false;
}

void Init()
{
    cout << "NHAN 1 - NHAP DSLK THU CONG & TU DONG" << endl;
    cout << "NHAN 2 - ADD HEAD" << endl;
    cout << "NHAN 3 - ADD TAIL" << endl;
    cout << "NHAN 4 - IN CAC GIA TRI TRONG DANH SACH" << endl;
    cout << "NHAN 5 - IN CAC GIA TRI & DIA CHI NODE TRONG DANH SACH" << endl;
    cout << "NHAN 6 - TIM KIEM GIA TRI X TRONG DANH SACH" << endl;
    cout << "NHAN 7 - XOA MOT GIA TRI TRONG DANH SACH" << endl;
    cout << "NHAN 8 - CAP NHAT MOT GIA TRI TRONG DANH SACH" << endl;
    cout << "NHAN 9 - THOAT KHOI CHUONG TRINH" << endl;
    cout << "-------------------" << endl;
    cout << endl;
}

int main()
{
    LIST l;
    long n, choose, x;
    NODE *p;
    CreateEmptylist(l);

    while (true) {
        cout << endl;
        Init ();
        cin >> choose;
        switch (choose) {
            case 1:
                InputList(l, n);
                break;          
            case 2: 
                cout << "NHAP GIA TRI PHAN TU CAN CHEN DAU: ";
                cin >> x;
                p = CreateNode(x);
                if (p != NULL)
                    AddHead(l, p);
                break;
            case 3:
                cout << "NHAP GIA TRI PHAN TU CAN CHEN CUOI: ";
                    cin >> x;
                    p = CreateNode(x);
                    if (p != NULL)
                        AddTail(l, p);
            case 4:
                OutputListV(l);
                break;
            case 5:
                OutputListP(l);
                break;
            case 6:
                cout << "NHAP GIA TRI X CAN TIM KIEM = ";
                cin >> x;
                if (SearchNode(l, x, p))
                    cout << "X NAM TRONG DSLK O DIA CHI " << p << endl;
                else cout << "X KHONG NAM TRONG DSLK" << endl;
                break;
            case 7:
                cout << "NHAP GIA TRI X CAN XOA = ";
                cin >> x;
                if (RemoveX(l, x))
                    cout << "X DA DUOC XOA KHOI DSLK " << endl;
                else cout << "X KHONG NAM TRONG DSLK" << endl;
                break;
            case 8:
                long y;
                cout << "NHAP GIA TRI PHAN TU CAN CAP NHAT TRONG DANH SACH = ";
                cin >> y;
                cout << "NHAP GIA X SE CAP NHAT CHO PHAN TU TRONG DANH SACH = ";
                cin >> x;
                if (SetX(l, y, x)) 
                    cout << "CAP NHAT GIA TRI X CHO PHAN TU TRONG DANH SACH THANH CONG \n";
                else cout << "PHAN TU DUOC NHAP KHONG NAM TRONG DANH SACH \n";
                break;
            case 9:
                cout <<"EXIT" << endl;
                return 0;
            default:
                cout << "Ban da nhap sai, vui long nhap lai: " << endl;
                cout << endl;
        }
    }
}
