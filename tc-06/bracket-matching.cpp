/*
Võ Khánh An - 19520007 - 10
Nguyễn Nhật Minh - 19520731 - 10
Nguyễn Thị Xuân Thủy - 19522327 - 10
Nguyễn Công Danh - 16520178 - 10
Trần Hữu Nhi - 16521761 - 10
*/

#include <iostream>
#include <string>
#define MAXN 10005

using namespace std;

struct NODE {
    long info;
    struct NODE *pNext;
};

struct STACK {
    NODE *pHead;
    NODE *pTail;
};

void CreateStack (STACK &s) {
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

bool IsEmpty (STACK s) {
    if (s.pHead == NULL)
        return true;
    return false;
}

void Push (STACK &s, NODE *p) {
    if (s.pHead == NULL) 
        s.pHead = s.pTail = p;
    else {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

bool Pop (STACK &s, char &trave)
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

bool Top (STACK &s, long &trave) {
    if (!IsEmpty(s)) {
        trave = s.pHead->info;
        return true;
    }
    return false;
}

bool InputStack (STACK &s, string &a) {
    cout << "NHAP BIEU THUC: ";
    getline (cin, a);
    long n = a.length();
    for (long i = 0; i < n; i++)
        if (a[i] == '(') {
            NODE *p = CreateNode (a[i]);
            Push (s, p);
        }
        else if (a[i] == ')') {
            if (IsEmpty(s))
                return false;
            char tm;
            Pop(s, tm);
        }
    if (!IsEmpty(s))
        return false;
    return true;
}

int main () {
    long n;
    string a;
    STACK s;
    CreateStack(s);
    if (InputStack(s, a))
        cout << "BIEU THUC NGOAC DUNG \n";
    else
        cout << "BIEU THUC NGOAC SAI \n";
}