#include <iostream>
#include <string>
#include <bits/stdc++.h>

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

NODE* CreateNode (char x)
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



struct QUEUE {
    NODE *pHead;
    NODE *pTail;
};

void CreateQueue (QUEUE &s) {
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

bool IsEmpty (QUEUE l) {
    if (l.pHead == NULL)
        return true;
    return false;
}


bool EnQueue (QUEUE &l, NODE *p) {
    if (IsEmpty(l))
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

bool DeQueue (QUEUE &l, char &trave) {
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


bool Front (QUEUE &l, long &trave) {
    if (!IsEmpty(l)) {
        trave = l.pHead->info;
        return true;
    }
    return false;
}

void InputStack (STACK &s, string &st) {
    for (long i = 0; i < st.length(); i++) {
        NODE *p = CreateNode (st[i]);
        Push (s, p);
    }
}

void InputQueue (QUEUE &q, string &st) {
    for (long i = 0; i < st.length(); i++) {
        NODE *p = CreateNode (st[i]);
        EnQueue(q, p);
    }
}

void InputString (string &st) {
    cout << "NHAP CHUOI CAN KIEM TRA: ";
    getline (cin, st);
    transform(st.begin(), st.end(), st.begin(), ::tolower);
}

bool Check (STACK &a, QUEUE &b) {
    char x,y;
    while (!IsEmpty(a) && !IsEmpty(b)) {
        Pop(a, x);
        DeQueue(b, y);
        if (x != y)
            return false;
    }
    return true;
}

int main () {
    string st;
    InputString(st);

    STACK a;
    CreateStack(a);
    InputStack(a, st);

    QUEUE b;
    CreateQueue(b);
    InputQueue(b, st);

    if (Check (a,b)) 
        cout << "DAY LA CHUOI PALINDROMES \n";
    else cout <<"DAY KHONG PHAI LA CHUOI PALINDROMES \n";
}