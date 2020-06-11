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

NODE* SearchNode(LIST bucket[], int value) {
    int tableIndex = HashFunction(value);
    NODE *p = bucket[tableIndex].pHead;
    while (p != NULL) {
        if (p->info == value)
            return p;
        p = p->pNext;
    }
    return NULL;
}

void IsEmptyBucket(LIST bucket[]) {
    for (int i = 0; i < M; i++)
        if (IsEmpty(bucket[i]))
            cout << "[BUCKET #" << i << "] " << "is empty\n";
}

bool IsEmptyTable(LIST bucket[]) {
    for (int i = 0; i < M; i++)
        if (!IsEmpty(bucket[i]))
            return false;
    return true;
}

bool DeleteAfterQ (LIST &l, NODE *Q, long &x)
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

bool DeleteHead(LIST &l, long &x)
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


bool DeleteX(LIST &l, long x)
{
    NODE *Q = NULL, *p = l.pHead;
    while (p != NULL && p->info != x)
    {
        Q = p;
        p = p -> pNext;
    }

    if (p == NULL) return false;
    if (Q != NULL) DeleteAfterQ(l, Q, x);
    else DeleteHead(l, x);

    return true;
}

void InputManual(LIST bucket[]) {
    int value, req;
    do {
        cout << "Nhap gia tri can chen: ";
        cin >> value;
        Insert(bucket, value);
        cout << "Ban co muon tiep tuc chen khong? (1/0): ";
        cin >> req;
    } while (req == 1);
}

void DeleteHashTable(LIST bucket[]) {
    int key;
    cout << "Nhap gia tri can xoa trong bang bam: ";
    cin >> key;

    int tableIndex = HashFunction(key);
    if (DeleteX(bucket[tableIndex], key))
        cout << "Da xoa thanh cong!\n";
    else
        cout << "Gia tri nhap vao khong co trong Hash Table!\n";
}

void Init() {
    cout << "1: Insert Random\n";
    cout << "2: Insert Manual\n";
    cout << "3: Output\n";
    cout << "4: Delete\n";
    cout << "5: Search Node\n";
    cout << "6: Hash Table Is Empty?\n";
    cout << "7: Thoat khoi chuong trinh!\n";
    cout << "\n";
}

int main() {
    LIST bucket [M];
    InitBucket(bucket);
    int option, key;

    while (true) {
        Init();
        cout << "Nhap lua chon: ";
        cin >> option;
        switch(option) {
            case 1:
                break;
            case 2:
                InputManual(bucket);
                break;
            case 3:
                OutputHashTable(bucket);
                break;
            case 4:
                DeleteHashTable(bucket);
                break;
            case 5:
                cout << "Nhap gia tri can tim kiem: ";
                cin >> key;
                if (SearchNode(bucket, key) != NULL) 
                    cout << "Dia chi Node can tim kiem: " << SearchNode(bucket, key) << "\n";
                else 
                    cout << "Gia tri can tim kiem KHONG co trong Hash Table\n";
                break;
            case 6:
                 IsEmptyBucket(bucket);
                if (IsEmptyTable(bucket))
                    cout << "Hash Table is empty\n";
                else 
                    cout << "Hash Table NOT is empty\n";
                break;
            case 7:
                cout << "EXIT!\n";
                return 0;
            default:
                cout << "Khong hop le, vui long nhap lai!\n";
        }
    }
    
    // Insert(bucket, 76);
    // Insert(bucket, 93);
    // Insert(bucket, 40);
    // Insert(bucket, 47);
    // Insert(bucket, 10);
    // Insert(bucket, 55);
   
}