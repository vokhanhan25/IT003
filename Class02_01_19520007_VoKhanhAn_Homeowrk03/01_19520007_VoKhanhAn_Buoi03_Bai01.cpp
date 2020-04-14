// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 02 - Bài 03
// Ngôn ngữ: C++

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAXN 105

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

void Cau1 (LIST &l) {
    srand(time(0));
    //long x;
   // cout << "SO LUONG PHAN TU = ";
   // cin >> n;
    //for (int i = 1; i <= n; i++)
    // while (true) {
    //     cout << "PHAN TU THU " << i << " = ";
    //     cin >> x;
    //     NODE *p = CreateNode(x);
    //     if (p!=NULL)
    //         AddTail (l,p);
    // }
}

void Cau2 (LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void Cau3 (LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void Cau3(LIST l)
{
    NODE *p = l.pHead;
    cout << endl;
    cout << "CAC GIA TRI CUA DSLK HIEN TAI LA: " << endl;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }

    cout << endl;
}

void Cau4(LIST l)
{
    NODE *p = l.pHead;
    cout << endl;
    cout << "CAC GIA TRI CUA DSLK HIEN TAI LA: " << endl;
    while (p != NULL)
    {
        cout << p << " ";
        p = p->pNext;
    }

    cout << endl;
}

bool Cau6(LIST l, long x)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (x == p->info)
            return true;
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

bool Cau6(LIST &l, long x)
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

bool Cau7(LIST l, long x)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (x == p->info)
            return true;
        p = p->pNext;
    }
    return false;
}

void init()
{
    cout << "NHAN 1 - CHAY CAU 1" << endl;
    cout << "NHAN 2 - CHAY CAU 2" << endl;
    cout << "NHAN 3 - CHAY CAU 3" << endl;
    cout << "NHAN 4 - CHAY CAU 4" << endl;
    cout << "NHAN 5 - CHAY CAU 4" << endl;
    cout << "NHAN 6 - CHAY CAU 4" << endl;
    cout << "NHAN 7 - CHAY CAU 4" << endl;
    cout << "NHAN 8 - THOAT KHOI CHUONG TRINH" << endl;
    cout << "-------------------" << endl;
    cout << endl;
}

int main()
{
    long n, a[MAXN];
    int res;
    while (true)
    {
        init ();
        cin >> res;
        switch (res)
        {
            case 1:
             //   Cau1(a, n);
                cout << endl;
                break;
            case 2:
               // cau2(a, n);
                cout << endl;
                break;
            case 3:
              //  cau3(a, n);
                cout << endl;
                break;
            case 4:
             //   cau4(a, n);
                cout << endl;
                break;
            case 5:
                cout <<"EXIT" << endl;
                return 0;
            default:
                cout << "Ban da nhap sai, vui long nhap lai: " << endl;
                cout << endl;
        }
    }
}
