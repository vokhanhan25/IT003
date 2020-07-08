#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define M 10
#define MAXC 1000000000

using namespace std;

struct NODE {
    double value;
    struct NODE *pNext;
};

struct LIST {
    NODE *pHead;
    NODE *pTail;
};

void CreateEmptyList (LIST &l){
    l.pHead = l.pTail = NULL;
}

NODE* CreateNode (double x) {
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->value = x;
    p->pNext = NULL;
    return p;
}

bool IsEmpty(LIST &l) {
    if (l.pHead == NULL)
        return true;
    return false;
}

void AddHead(LIST &l, NODE *p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail(LIST &l, NODE *p) {
    if (l.pHead == NULL) 
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

int HashFunction (double key) {
    return int(key) % M;
}

void InitBucket(LIST bucket[]) {
    for (int i = 0; i < M; i++)
        CreateEmptyList(bucket[i]);
}

void Insert(LIST bucket[], double key) {
    int tableIndex = HashFunction(key);
    NODE *p = CreateNode(key);
    AddTail(bucket[tableIndex], p);
}

void OutputList(LIST l) {
    NODE *p = l.pHead;
    while (p != NULL) {
        p = p->pNext;
    }
}

void OutputTable(LIST bucket[]) {
    for (int i = 0; i < M; i++) {
        OutputList(bucket[i]);
        cout << "\n";
    }
}




