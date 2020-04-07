#include <iostream>

using namespace std;

struct DNode
{
    long info;
    DNode *next;
    DNode *pre;
};

struct DList
{
    DNode *head;
    DNode *tail;
};

DNode *CreateDNode (long x)
{
    DNode *p = new DNode;
    if (p == NULL) return NULL;
    p->info = x;
    p->next = NULL;
    p->pre = NULL;
    return p;
}

void CreateEmptyList (DList &l)
{
    l.head = NULL;
    l.tail = NULL;
}

void AddHead (DList &l, DNode *p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head->pre = p;
        l.head = p;
    }
}

void AddTail (DList &l, DNode *p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->pre = l.tail;
        l.tail->next = p;
        l.tail = p;
    }
}

void AddAfterQ (DList &l, DNode *q, DNode *p)
{
    if (q != NULL)
    {
        p->next = q->next;
        p->pre = q;

        q->next = p;
        if (q->next != NULL)
            q->next->pre = p;

        if (l.tail == q)
            l.tail = p;
    }
    else
    {
        AddHead(l, p);
    }
}

void AddBeforeQ (DList &l, DNode *q, DNode *p)
{
    if (q != NULL)
    {
        p->next = q;
        p->pre = q->pre;

        if (q->pre != NULL)
            q->pre->next = p;
        q->pre = p;

        if (l.head == q)
            l.head = p;
    }
    else
    {
        AddTail(l, p);
    }
}

void DelHead (DList &l)
{
    DNode *p;
    if (l.head != NULL)
    {
        p = l.head;
        l.head = l.head->next;
        l.head->pre = NULL;
        delete p;
        if (l.head == NULL)
            l.tail = NULL;
    }
}

void DelTail (DList &l)
{
    DNode *p;
    if (l.head != NULL)
    {
        p = l.tail;
        l.tail = l.tail->pre;
        l.tail->next = NULL;
        delete p;
        if (l.tail == NULL)
            l.head = NULL;
    }
}

void DelAfterQ (DList &l, DNode *q)
{
    DNode *p;
    if (q != NULL)
    {
        p = q->next;
        if (p != NULL)
        {
            q->next = p->next;
            if (p==l.tail)
                l.tail = q;
            else
                p->next->pre = q;
            delete p;
        }
    }
    else
        DelHead(l);
}

void DelBeforeQ (DList &l, DNode *q)
{
    DNode *p;
    if (q != NULL)
    {
        p = q->pre;
        if (q != NULL)
        {
            q->pre = p->pre;
            if (p == l.head)
                l.head = q;
            else
                p->pre->next = q;
            delete p;
        }
    }
    else
        DelTail(l);
}

bool DelX(DList &l, long x)
{
    DNode *p;
    DNode *q;
    q = NULL;
    p = l.head;
    while (p != NULL)
    {
        if (p->info == x)
            break;
        q = p;
        p = p->next;
    }
    if (p == NULL) return false;
    if (q != NULL)
    {
        DelAfterQ(l, q);
    }
    else {
        DelHead(l);
    }
    return true;
}


int main()
{

}
