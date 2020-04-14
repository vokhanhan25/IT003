/*
Võ Khánh An - 19520007 - 10
Nguyễn Nhật Minh - 19520731 - 10
Nguyễn Thị Xuân Thủy - 19522327 - 10
Nguyễn Công Danh - 16520178 - 10
Trần Hữu Nhi - 16521761 - 10
*/

#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

struct ROOM
{
    long num, stt;
    char type;
};

struct NODE
{
    ROOM info;
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

NODE* CreateNode (ROOM x)
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

void InputList(LIST &l, long &n)
{
    ROOM x;
    cout << "SO LUONG PHONG = ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "NHAP THONG TIN PHONG THU " << i << endl;
        cout << "SO PHONG: ";
        cin >> x.num;
        cout << "LOAI PHONG (A = PHONG DON, B = PHONG DOI): ";
        cin >> x.type;
        cout << "TRANG THAI PHONG (1 = DA CO KHACH, 0 = TRONG): ";
        cin >> x.stt;
        cout << endl;
        NODE *p = CreateNode(x);
        if (p!=NULL)
            AddTail (l,p);
    }
}

void OutputList(LIST l)
{
    NODE *p = l.pHead;
    cout << endl;
    cout << "DANH SACH PHONG HIEN TAI: " << endl;
    long i = 1;
    while (p != NULL)
    {
        cout <<"THONG TIN PHONG THU " << i << endl;
        cout <<"SO PHONG: " << p->info.num << endl;

        cout <<"LOAI PHONG: ";
        if (p->info.type == 'A') 
            cout << "A - PHONG DON" << endl;
        else cout << "B- PHONG DOI" << endl;

        cout <<"TRANG THAI PHONG: ";
        if (p->info.stt == 1)
            cout << "1 - DA CO KHACH" << endl;
        else cout << "0 - TRONG" << endl;
        cout << endl;
        p = p->pNext;
        i++;
    }

    cout << endl;
}

void ThongKeStt (LIST l)
{
    NODE *p = l.pHead;
    cout << endl;
    cout << "THONG KE SO LUONG PHONG THEO TINH TRANG: " << endl;
    long cnt1 = 0, cnt0 = 0;
    while (p != NULL)
    {
        if (p->info.stt == 1)
            cnt1++;
        else cnt0++;
        p = p->pNext;
    }

    cout << "SO PHONG TINH TRANG 1 - DA CO KHACH = " << cnt1 << endl;
    cout << "SO PHONG TINH TRANG 0 - TRONG = " << cnt0 << endl;
}

void ThongKeType (LIST l)
{
    NODE *p = l.pHead;
    cout << endl;
    cout << "THONG KE SO LUONG PHONG THEO LOAI PHONG: " << endl;
    long cntA = 0, cntB = 0;
    while (p != NULL)
    {
        if (p->info.type == 'A')
            cntA++;
        else cntB++;
        p = p->pNext;
    }

    cout << "SO PHONG LOAI A - PHONG DON = " << cntA << endl;
    cout << "SO PHONG LOAI B - PHONG DOI = " << cntB << endl;
    cout << endl;
}

long TinhDoanhThu (LIST l)
{
    NODE *p = l.pHead;
    long res = 0;
    while (p != NULL)
    {
        if (p->info.stt == 1)
        {
            if (p->info.type == 'A')
                res = res + 200;
            else res = res + 350;
        }
        p = p->pNext;
    }
    return res;
}

void SortList (LIST &l)
{
    for (NODE *i = l.pHead; i != l.pTail; i = i ->pNext)
        for (NODE *j = i ->pNext; j != NULL; j = j ->pNext)
            if (i -> info.num > j->info.num)
                swap (i->info, j->info);
}

bool RemoveHead(LIST &l, long &x)
{
    NODE *p;
    if (l.pHead != NULL)
    {
        x = l.pHead -> info.num;
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
        x = p -> info.num;
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
    while (p != NULL && p->info.num != x)
    {
        Q = p;
        p = p -> pNext;
    }

    if (p == NULL) return false;
    if (Q != NULL) RemoveAfterQ(l, Q, x);
    else RemoveHead(l, x);

    return true;
}

void Remove (LIST l)
{
    long x;
    cout << "NHAP SO PHONG CAN XOA: ";
    cin >> x;
    if (RemoveX(l, x)) 
        cout << "DA XOA THANH CONG" << endl;
    else cout << "PHONG CAN XOA KHONG CO TRONG DANH SACH" << endl;
}

int main()
{
    long n;
    LIST l;
    createEmptylist(l);
    InputList(l, n);
    OutputList(l);
    ThongKeStt(l);
    ThongKeType(l);
    cout << "TONG DOANH THU = " << TinhDoanhThu(l) << "d" << endl;
    SortList(l);
    Remove(l);
}
