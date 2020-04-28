#include <iostream>

using namespace std;

struct NODE {
    int info;
    struct NODE *pNext;
};

struct STACK {
    NODE *pHead;
    NODE *pTail;
};

void CreateStack (STACK &s) {
    s.pHead = NULL;
    s.pTail = NULL;
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

bool IsEmpty (STACK s) {
    if (s.pHead == NULL)
        return true;
    return false;
}

void Push (STACK &s, NODE *p) {
    if (s.pHead == NULL) 
        s.pHead = s.pTail = p;
    else {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

bool Pop (STACK &s, int &trave)
{
    NODE *p;
    if (!IsEmpty(s)) {
        p = s.pHead;
        trave = p->info;
        s.pHead = s.pHead->pNext;
        if (s.pHead == NULL)
            s.pTail = NULL;
        delete p;
        return true;        
    }
    return false;
}

bool Top (STACK &s, int &trave) {
    if (!IsEmpty(s)) {
        trave = s.pHead->info;
        return true;
    }
    return false;
}

void InputStack (STACK &s, int n) {
    cin >> n;
    int x;
    while (n > 0) {
        cin >> x;
        NODE *p = CreateNode (x);
        Push (s, p);
        n--;
    }
}

void OutputStack (STACK s) {
    NODE *p = s.pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

void init()
{
    cout << "1 - Push" << endl;
    cout << "2 - Pop" << endl;
    cout << "3 - Top" << endl;
    cout << "4 - Checking Empty" << endl;
    cout << "5 - Checking Full" << endl;
    cout << "-------------------" << endl;
    cout << endl;
}

int main () {
    STACK s;
    CreateStack(s);
    int res, x;
    while (true)
    {
        init ();
        cin >> res;
        switch (res)
        {
            case 1:
                cin >> x;
                NODE *p = CreateNode(x);
                Push(s, p);
                cout << "\n";
                break;
            case 2:
                Pop(s, x);
                cout << "\n";
                break;
            case 3:
                cout << "\n";
                break;
            case 4:
                if (IsEmpty(s))
                    cout <<"Stack rong\n\n";
                else cout <<"Stack khong rong\n\n";
                break;
            case 5:
              //  if (IsFull(s))
               //     cout << "Stack day\n\n";
              //  else cout <<"Stack khong day\n\n";
                break;
            case 6:
                cout <<"EXIT" << endl;
                return 0;
            default:
                cout << "Ban da nhap sai, vui int nhap lai: \n\n";
        }
        OutputStack(s);
    }
}