/*
Võ Khánh An - 19520007 - 10
Nguyễn Nhật Minh - 19520731 - 10
Nguyễn Thị Xuân Thủy - 19522327 - 10
Nguyễn Công Danh - 16520178 - 10
Trần Hữu Nhi - 16521761 - 10
*/

#include <iostream>
#include <algorithm>
#define MAXN 100000

using namespace std;

struct NODE
{
    int info;
    struct NODE *pNext;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

NODE* CreateNode (int x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptylist (LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void AddTail (LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void Input(int a[], int b[], int &n, LIST &l) {
    cout << "SO LUONG PHAN TU = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "GIA TRI PHAN TU O VI TRI " << i << " = ";
        cin >> a[i];
        b[i] = a[i];
        NODE *p = CreateNode(a[i]);
        if (p != NULL) 
            AddTail(l, p);
    }
}

int LinearSearch (int a[], int n, int x) {
    int i = 0;
    while (i < n && a[i] != x) 
        i++;
    if (i == n)
        return -1;
    return i;
}

int LinearSearchImprove (int a[], int n, int x) {
    int i = 0; a[n] = x;
    while (a[i] != x) 
        i++;
    if (i == n)
        return -1;
    return i;
}

int BinarySearch (int a[], int n, int x) {
    int l = 0, r = n - 1, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (a[m] == x)
            return m;
        else if (a[m] < x) 
            l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int InterpolationSearch (int a[], int n, int x) {
    int l = 0, r = n - 1, m;
    while (l <= r) {
        m = l + ((r - l) * (x - a[l]) / (a[r] - a[l]));
        if (a[m] == x)
            return m;
        else if (a[m] < x) 
            l = m + 1;
        else r = m - 1;
    }
    return -1;
}

NODE* LinearSearch (LIST &l, int x) {
    NODE *p = l.pHead;
    while (p != NULL) {
        if (p->info == x)
            return p;
        p = p->pNext;
    }
    return NULL;
}

NODE* LinearSearchImprove(LIST &l, int x) {
    NODE *p = l.pHead, *t = CreateNode(x);
    if (t != NULL) {
        AddTail(l, t);
        while (p->info != x)
            p = p->pNext;
        if (p == l.pTail)
            return NULL;
        return p;
    }
    return NULL;
}

int main() {
    int n, a[MAXN], x, b[MAXN];   
    LIST l;
    CreateEmptylist(l); 
    Input(a, b, n, l);

    cout << "NHAP GIA TRI X CAN TIM KIEM = ";
    cin >> x;

    cout << "\n";

    int resArr = LinearSearch(a, n, x);
    if (resArr != -1)
        cout << "LINEAR SEARCH (ARRAY) = " << resArr << "\n";
    else cout << "LINEAR SEARCH (ARRAY): KHONG TIM THAY!\n";

    NODE *resLL = LinearSearch(l, x);
    if (resLL != NULL)
        cout << "LINEAR SEARCH (LINKED LIST) = " << resLL << "\n";
    else cout << "LINEAR SEARCH (LINKED LIST): KHONG TIM THAY!\n"; 

    resArr = LinearSearchImprove(a, n, x);
    if (resArr != -1)
        cout << "LINEAR SEARCH CAI TIEN (ARRAY) = " << resArr << "\n";
    else cout << "LINEAR SEARCH CAI TIEN (ARRAY): KHONG TIM THAY!\n";

    resLL = LinearSearchImprove(l, x);
    if (resLL != NULL)
        cout << "LINEAR SEARCH CAI TIEN (LINKED LIST) = " << resLL << "\n";
    else cout << "LINEAR SEARCH CAI TIEN (LINKED LIST): KHONG TIM THAY!\n"; 

    sort (b, b + n);
    resArr = BinarySearch(b, n, x);
    if (resArr != -1)
        cout << "BINARY SEARCH (ARRAY) = " << resArr << " (DA SAP XEP)\n";
    else cout << "BINARY SEARCH (ARRAY): KHONG TIM THAY!\n";

    resArr = InterpolationSearch(b, n, x);
    if (resArr != -1)
        cout << "INTERPOLATION SEARCH (ARRAY) = " << resArr << " (DA SAP XEP)\n";
    else cout << "INTERPOLATION SEARCH (ARRAY): KHONG TIM THAY!\n";
}