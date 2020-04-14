#include <iostream>
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

bool Pop (STACK &s, long &trave)
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

void InputStack (STACK &s, long n) {
    cout << "SO TRONG HE THAP PHAN = ";
    cin >> n;
    long x;
    while (n > 0) {
        NODE *p = CreateNode (n % 2);
        n = n / 2;
        Push (s, p);
    }
}

void OutputStack (STACK s) {
    NODE *p = s.pHead;
    cout << "SO TRONG HE NHI PHAN = ";
    while (p != NULL) {
        cout << p->info;
        p = p->pNext;
    }
    cout << endl;
}

int main () {
    long n;
    STACK s;
    CreateStack(s);
    InputStack(s, n);
    OutputStack(s);
}