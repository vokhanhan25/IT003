// STT: 01
// Họ và tên: Võ Khánh An
// Ghi chú: Đề thi thử số 1

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define M 10
#define MAXC 1000000000

using namespace std;

struct NODE {
    double info;
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

NODE* CreateNode (double x) {
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

//Câu 1: Hàm băm theo phương pháp chia
int HashFunction(double key) {
    return int(key) % M;
}

void InitBucket(LIST bucket[]) {
    for (int i = 0; i < M; i++)
        CreateEmptylist(bucket[i]);
}

void Insert(LIST bucket[], double key) {
    int tableIndex = HashFunction(key);
    NODE *p = CreateNode(key);
    AddTail(bucket[tableIndex], p);
}

void OutputList(LIST l) {
    NODE *p = l.pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void OutputHashTable(LIST bucket[]) {
    for (int i = 0; i < M; i++) {
        cout << "[BUCKET #" << i << "]: ";
        OutputList(bucket[i]);
        cout << "\n";
    }
}

int CountValueList(LIST l) {
    NODE *p = l.pHead;
    int cnt = 0;
    while (p != NULL) {
        cnt++;
        p = p->pNext;
    }
    return cnt;
}

int CountValueHashTable(LIST bucket[]) {
    int cnt = 0;
    for (int i = 0; i < M; i++) 
        cnt += CountValueList(bucket[i]);
    return cnt;
}

double Max(double a, double b) {
    if (a > b)
        return a;
    return b;
}

double Min(double a, double b) {
    if (a < b)
        return a;
    return b;
}

void FindMaxMinList(LIST l, double &maxc, double &minc) {
    NODE *p = l.pHead;
    maxc = -MAXC;
    minc = MAXC;
    while (p != NULL) {
        maxc = Max(maxc, p->info);
        minc = Min(minc, p->info);
        p = p->pNext;
    } 
}


void FindMaxMinHashTable(LIST bucket[], double &maxc, double &minc) {
    maxc = -MAXC; 
    minc = MAXC;
    double maxl, minl;
    for (int i = 0; i < M; i++) {
        FindMaxMinList(bucket[i], maxl, minl);
        maxc = Max(maxc, maxl);
        minc = Min(minc, minl);
    }
}

void CountEvenOddList(LIST l, int &even, int &odd) {
    NODE *p = l.pHead;
    even = 0; 
    odd = 0;
    while (p != NULL) {
        if (int(p->info) % 2 == 0)
            even++;
        else 
            odd++;
        p = p->pNext;
    } 
}

string CountMaxMinHashTable(LIST bucket[]) {
    int odd = 0, int even = 0, oddl, evenl;
    for (int i = 0; i < M; i++) {
        CountEvenOddList(bucket[i], evenl, oddl);
        odd += oddl;
        even += evenl;
    }
    if (even < odd)
        return "True";
    if (even == odd)
        return "1";
    return "False";
}

bool SearchNode(LIST bucket[], double value) {
    int tableIndex = HashFunction(value);
    NODE *p = bucket[tableIndex].pHead;
    while (p != NULL) {
        if (p->info == value)
            return true;
        p = p->pNext;
    }
    return false;
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

void InputArr(LIST bucket[]) {
    int n;
    double a[10000];
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap a[ " << i << "] = " ;
        cin >> a[i];
        Insert(bucket, a[i]);
    };
}

void InputManual(LIST bucket[]) {
    int req;
    double value;
    do {
        cout << "Nhap gia tri can chen: ";
        cin >> value;
        Insert(bucket, value);
        cout << "Ban co muon tiep tuc chen khong? (1/0): ";
        cin >> req;
    } while (req == 1);
}

void InputRandom(LIST bucket[]) {
    srand(time(0));
    int n = 45 + rand() % (51);
    int value;
    for (int i = 0; i < n; i++) {
        value = rand() + rand() / (double)RAND_MAX;
        Insert(bucket, value);
    }
    cout << "Da nhap tu dong xong!\n";
}

void Init() {
    cout << "2: Insert Random\n";
    cout << "3: Input Array\n";
    cout << "4: Inpurt Manuel\n";
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
                InputRandom(bucket);
                break;
            case 3:
                InputArr(bucket);
                break;
            case 4:
                InputManual(bucket);
                break;
            case 5:
                 IsEmptyBucket(bucket);
                if (IsEmptyTable(bucket))
                    cout << "Hash Table is empty\n";
                else 
                    cout << "Hash Table NOT is empty\n";
                break;
            case 6:
                cout << "So cac gia tri duoc luu tru trong Hash Table = " << CountValueHashTable(bucket) << "\n";
                break;
            case 7:
                cout << "Nhap gia tri can tim kiem: ";
                cin >> key;
                if (SearchNode(bucket, key)) 
                    cout << "Gia tri can tim kiem co trong Hash Table \n";
                else 
                    cout << "Gia tri can tim kiem KHONG co trong Hash Table\n";
                break;
            case 8:
                break;
            case 9:
                break;
                
            case 10:
                cout << "EXIT!\n";
                return 0;
            default:
                cout << "Khong hop le, vui long nhap lai!\n";
        }
    }
}