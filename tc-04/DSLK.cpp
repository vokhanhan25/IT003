#include <iostream>

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

void CreateEmptylist (LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

bool IsEmpty (LIST &l)
{
    if (l.pHead == NULL)
        return true;
    return false;
}

NODE* CreateNode (int x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
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

void AddHead (LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddAfterQ(LIST &l, NODE *q, NODE *p)
{
    if (q != NULL)
    {
        p->pNext = q->pNext;
        q->pNext = p;
        if (l.pTail == q)
        {
            l.pTail = p;
        }
    }
    else {
        AddHead(l,p);
    }
}

void InputList(LIST &l, int &n)
{
    int x;
    cout << "n = ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "x = ";
        cin >> x;
        NODE *p = CreateNode(x);
        if (p!=NULL)
            AddTail (l,p);
    }
}

bool RemoveHead(LIST &l, int &x)
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

bool RemoveAfterQ (LIST &l, NODE *Q, int &x)
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

bool RemoveX(LIST &l, int x)
{
    NODE *Q = NULL, *p = l.pHead;
    while (p != NULL && p->info != x)
    {
        Q = p;
        p = p -> pNext;
    }

    if (p == NULL) return false;
    if (Q != NULL) RemoveAfterQ(l, Q, x);
    else RemoveHead(l, x);

    return true;
}

void RemoveList (LIST &l)
{
    NODE *p;
    while (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = p ->pNext;
        delete p;
    }
    l.pTail = NULL;
}

void SortList (LIST &l)
{
    for (NODE *i = l.pHead; i != l.pTail; i = i ->pNext)
        for (NODE *j = i ->pNext; j != NULL; j = j ->pNext)
            if (i -> info > j->info)
                swap (i->info, j->info);
}

bool SearchNode(LIST l)
{
    int x;
    cout << "NHAP GIA TRI CAN TIM KIEM TRONG DSLK = ";
    cin >> x;
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (x == p->info)
            return true;
        p = p->pNext;
    }
    return false;
}

void OutputList(LIST l)
{
    NODE *p = l.pHead;
    cout << endl;
    cout << "DANH SACH LIEN KET DA NHAP LA: " << endl;
    while (p != NULL)
    {
        cout << p->info << endl;
        p = p->pNext;
    }

    cout << endl;
}


int main()
{
    int n;
    LIST l;
    CreateEmptylist(l);
    InputList(l, n);
    OutputList(l);
    if (SearchNode(l))
        cout <<"GIA TRI CAN TIM Co XUAT HIEN TRONG DANH SACH" << endl;
    else cout <<"GIA TRI Khong XUAT HIEN TRONG DANH SACH";
}
