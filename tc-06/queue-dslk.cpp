#include <iostream>

using namespace std;

struct NODE {
    long info;
    struct NODE *pNext;
};

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

bool DeQueue (QUEUE &l, long &trave) {
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

int main () {

}