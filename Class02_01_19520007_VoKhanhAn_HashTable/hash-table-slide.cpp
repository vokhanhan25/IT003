#include <iostream>
#include <stdlib.h>

using namespace std;

#define M 100

typedef struct nodes
{
    int key;
    struct nodes* next;
}NODE;

//khai bao kieu con tro chi nut
typedef NODE* PHNODE;
/* khai bao mang HASHTABLE chua M con tro dau
cua MHASHTABLE */

PHNODE HASHTABLE[M];

int HF(int key)
{
    return (key % M);
}

void InitHASHTABLE()
{
    for (int i = 0; i < M; i++)
        HASHTABLE[i] = NULL;
}

int emptyHASHTABLE(int i)
{
    return(HASHTABLE[i] == NULL ? 1 : 0);
}

int empty() {
    for (int i = 0; i < M; i++)
        if (HASHTABLE[i] != NULL)
            return 0;
    return 1;
}

void insert(int k)
{
    int i = HF(k)
        InsertList(HASHTABLE[i], k); //phép toán thêm khoá k
        //vào danh sach lien ket HASHTABLE[i]
}

void remove(int k) {
    int b;
    PHNODE q, p;
    b = HF(k);
    p = HASHTABLE(b);
    q = p;
    while (p != NULL && p->key != k)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        printf("\n khong co nut co khoa % d", k);
    else if (p == HASHTABLE[b])
        remove(b);
    else
        delafter(q);
}

NODE* SearchNode(int k) {
    PHNODE p;
    int b;
    b = HF(k);
    p = HASHTABLE[b];
    while (k != p->key && p != NULL)
        p = p->next;
    if (p == NULL || k != p->key) // khong tim thay
        return(NULL);
    else //tim thay
        return(p);
}

void traverseHASHTABLE(int b)
{
    PHNODE p;
    p = HASHTABLE[b];
    while (p != NULL)
    {
        printf(" % 3d", p->key);
        p = p->next;
    }
}

void traverse()
{
    int b;
    for (b = 0; b < M; b++)
    {
        printf("\nButket % d:", b);
        traverseHASHTABLE(b);
    }
}

int main() {

}