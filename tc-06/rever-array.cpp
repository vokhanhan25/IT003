/*
Võ Khánh An - 19520007 - 10
Nguyễn Nhật Minh - 19520731 - 10
Nguyễn Thị Xuân Thủy - 19522327 - 10
Nguyễn Công Danh - 16520178 - 10
Trần Hữu Nhi - 16521761 - 10
*/

#include <iostream>

using namespace std;

struct NODE {
    long info;
    struct NODE *pNext;
};

struct LIST {
    NODE *pHead;
    NODE *pTail;
};

void CreateStack (LIST &s) {
    s.pHead = NULL;
    s.pTail = NULL;
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

bool IsEmpty (LIST s) {
    if (s.pHead == NULL)
        return true;
    return false;
}

void Push (LIST &s, NODE *p) {
    if (s.pHead == NULL) 
        s.pHead = s.pTail = p;
    else {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

bool Pop (LIST &s, long &trave)
{
    NODE *p;
    if (!IsEmpty(s)) {
        p = s.pHead;
        trave = p->info;
        s.pHead = s.pHead->pNext;
        if (s.pHead == NULL)
            s.pTail = NULL;
        delete p;
        return true;        
    }
    return false;
}

bool Top (LIST &s, long &trave) {
    if (!IsEmpty(s)) {
        trave = s.pHead->info;
        return true;
    }
    return false;
}

void InputStack (LIST &s, long n) {
    cout << "NHAP SO LUONG PHAN TU = ";
    cin >> n;
    long x;
    while (n > 0) {
        cout << "NHAP GIA TRI = ";
        cin >> x;
        NODE *p = CreateNode (x);
        Push (s, p);
        n--;
    }
}

void OutputStack (LIST s) {
    NODE *p = s.pHead;
    cout << "KET QUA SAU KHI DAO MANG: \n";
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

int main () {
    long n;
    LIST (s);
    CreateStack(s);
    InputStack(s, n);
    cout << endl;
    OutputStack(s);
}