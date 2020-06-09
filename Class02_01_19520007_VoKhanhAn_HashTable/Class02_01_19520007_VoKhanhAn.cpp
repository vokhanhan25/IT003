// STT: 01
// Họ và tên: Võ Khánh An
// Ghi chú: Hash Table

#include <iostream>

#define M 10

using namespace std;

struct NODE {
    int info;
    struct NODE *pNext;
};

struct LIST {
    NODE *pHead;
    NODE *pTail;
};

void CreateEmptylist (LIST &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE* CreateNode (int x) {
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

bool IsEmpty (LIST &l) {
    if (l.pHead == NULL)
        return true;
    return false;
}

void AddHead (LIST &l, NODE *p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail (LIST &l, NODE *p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void OutputList(LIST l) {
    NODE *p = l.pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
}

int HashFunction(int key) {
    return key % M;
}

void InitBucket(LIST bucket[]) {
    for (int i = 0; i < M; i++)
        CreateEmptylist(bucket[i]);
}

void Insert(LIST bucket[], int key) {
    int tableIndex = HashFunction(key);
    NODE *p = CreateNode(key);
    AddTail(bucket[tableIndex], p);
}

void OutputHashTable(LIST bucket[]) {
    for (int i = 0; i < M; i++) {
        cout << "[BUCKET #" << i << "]: ";
        OutputList(bucket[i]);
        cout << "\n";
    }
}

int main() {
    LIST bucket [M];
    InitBucket(bucket);
    Insert(bucket, 76);
    Insert(bucket, 93);
    Insert(bucket, 40);
    Insert(bucket, 47);
    Insert(bucket, 10);
    Insert(bucket, 55);
    OutputHashTable(bucket);
}