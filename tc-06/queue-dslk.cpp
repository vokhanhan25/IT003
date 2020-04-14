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

bool IsEmpty (LIST l) {
    if (l.pHead == NULL)
        return true;
    return false;
}


bool EnQueue (LIST &l, NODE *p) {
    if (IsEmpty(l))
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

bool DeQueue (LIST &l, long &trave) {
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


bool Front (LIST &l, long &trave) {
    if (!IsEmpty(l)) {
        trave = l.pHead->info;
        return true;
    }
    return false;
}

int main () {

}