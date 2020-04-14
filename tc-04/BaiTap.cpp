/*
Võ Khánh An - 19520007 - 10
Nguyễn Nhật Minh - 19520731 - 10
Nguyễn Thị Xuân Thủy - 19522327 - 10
Nguyễn Công Danh - 16520178 - 10
Trần Hữu Nhi - 16521761 - 10
*/

#include <iostream>
#include <cmath>
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

void createEmptylist (LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

bool IsEmpty (LIST &l)
{
    if (l.pHead == NULL)
        return true;
    return false;
}

bool ktnt (long n)
{
    if (n <= 1)
        return false;
    for (long i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
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

void AddTail (LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
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

void addAfterQ(LIST &l, NODE *q, NODE *p)
{
    if (q != NULL)
    {
        p->pNext = q->pNext;
        q->pNext = p;
        if (l.pTail == q)
        {
            l.pTail = p;
        }
    }
    else {
        AddHead(l,p);
    }
}

void InputList(LIST &l, long &n)
{
    long x;
    cout << "SO LUONG PHAN TU = ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "PHAN TU THU " << i << " = ";
        cin >> x;
        NODE *p = CreateNode(x);
        if (p!=NULL)
            AddTail (l,p);
    }
}

bool RemoveHead(LIST &l, int &x)
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

bool RemoveAfterQ (LIST &l, NODE *Q, int &x)
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

bool RemoveX(LIST &l, int x)
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

void RemoveList (LIST &l)
{
    NODE *p;
    while (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = p ->pNext;
        delete p;
    }
    l.pTail = NULL;
}

void SortList (LIST &l)
{
    for (NODE *i = l.pHead; i != l.pTail; i = i ->pNext)
        for (NODE *j = i ->pNext; j != NULL; j = j ->pNext)
            if (i -> info > j->info)
                swap (i->info, j->info);
}


long CountSnt(LIST l)
{
    long cnt = 0;
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (ktnt(p->info))
            cnt ++;
        p = p->pNext;
    }
    return cnt;
}

bool CheckChan(LIST l)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (p->info % 2 == 1)
            return false;
        p = p->pNext;
    }
    return true;
}

bool CheckTang (long n)
{
    if (n < 10)
        return false;
    else {
        while (n >= 1)
        {
            long k = n % 10;
            n = n / 10;
            if (k <= n / 10)
                return false;
        }
        return true;
    }

}

int AddNode (LIST &l)
{
    NODE *p = l.pHead;
    long x;
    cout << "Nhap gia tri x can them vao = ";
    cin >> x;
    NODE *k = CreateNode (x);
    if (k->info >= l.pTail->info)
        AddTail(l, k);
    else if (k->info <= l.pHead->info)
        AddHead(l, k);
    else 
        while (p != NULL)
        {
            if (p->info <= k->info && p->pNext->info >= k->info)
            {
                addAfterQ (l, p, k);
                return 0;
            }
            p = p->pNext;
        }
}

void SearchNodeTang(LIST l)
{
    NODE *p = l.pHead;
    bool kt = false;
    cout << "CAC SO TANG = ";
    while (p != NULL)
    {
        if (CheckTang(p->info))
        {
            cout << p->info <<" ";
            kt = true;
        }
        p = p->pNext;
    }

    if (!kt) cout << "KHONG CO SO TANG NAO TRONG DSLK";
    cout << endl;
}

void SearchNodeNhoLon(LIST l)
{
    long minc = l.pHead->info;
    long maxc = minc;
    NODE *p = l.pHead->pNext;

    while (p != NULL)
    {
        if (p->info > maxc)
            maxc = p->info;
        if (p->info < minc)
            minc = p->info;
        p = p->pNext;
    }

    cout << "NODE nho nhat = " << minc << endl;
    cout << "NODE lon nhat = " << maxc << endl;
    cout << endl;
}

void wf(LIST l)
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

void wfPosLe(LIST l)
{
    NODE *p = l.pHead;
    long cnt = 1;
    cout << endl;
    cout << "GIA TRI INFO CAC NODE O VI TRI LE TRONG DANH SACH: " << endl;
    while (p != NULL)
    {
        if (cnt % 2 == 1)
            cout << p->info << " ";
        p = p->pNext;
        cnt ++;
    }

    cout << endl;
}


int main()
{
    long n;
    LIST l;
    createEmptylist(l);
    InputList(l, n);
    wf(l);
    cout << endl;
    cout <<"SO LUONG SO NGUYEN TO TRONG DSLK = " << CountSnt(l) << endl;
    cout << endl;

    SortList(l);

    AddNode(l);
    cout << endl;

    if (CheckChan(l)) cout <<"DSLK CHUA TOAN SO CHAN" << endl;
    else cout <<"DSLK CO XUAT HIEN SO LE" << endl;
    cout << endl;

    SearchNodeTang(l);
    cout << endl;

    SearchNodeNhoLon(l);
    cout << endl;

    long x;
    cout << "GIA TRI CAN XOA TRONG DSLK = ";
    cin >> x;
    if (RemoveX(l, x)) cout <<"DA XOA THANH CONG" << endl;
    else cout << "X KHONG CO TRONG DSLK" << endl;
    cout << endl;

    wfPosLe(l);
}
