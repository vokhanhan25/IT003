// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 04 - Bài 01
// Ngôn ngữ: C++ / Cài đặt bằng Danh sách liên kết đơn

#include <iostream>
#define MAXN 10000
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

void OutputStack (STACK s) {
    cout << "STACK: TOP<\t";
    NODE *p = s.pHead;
    while (p != NULL) {
        cout << p->info << "\t";
        p = p->pNext;
    }
    cout << ">\n";
}

void Init()
{
    cout << "0: Creating Tower\n"; 
    cout << "1: A -> B\n";
    cout << "2: B -> A\n"; 
    cout << "3: B -> C\n";
    cout << "4: C -> B\n";
    cout << "5: C -> A\n";
    cout << "6: A -> C\n";
    cout << "7: Thoat khoi tro choi!\n";
    cout << "------------------\n\n";
}

void CreatingTower(STACK &a, int choose) {

    NODE *p;
    for (int i = choose; i > 0; i--)  {
        p = CreateNode(i);
        Push(a, p);
    }
}

bool Check(STACK s, int choose) {
    NODE *p = s.pHead; int i = 0;
    while (p != s.pTail && p->info < p->pNext->info) {
        p = p->pNext;
        i++;
    }
    if (i + 1 == choose)
        return true;
    return false;
}

bool Move(STACK &a, STACK &b) {
    int x, y, z;
    NODE *p;
    if (!Top(a, x))
        return false;
    Top(b, y);
    if (x < y || !IsEmpty(b)) {
        Pop(a, z);
        p = CreateNode(z);
        Push(b, p);
        return true;
    }
    return false;
}

void Output(STACK a, STACK b, STACK c) {
    cout << "A Tower\n";
    OutputStack(a);
    cout << "============================\n";

    cout << "B Tower\n";
    OutputStack(b);
    cout << "============================\n";


    cout << "C Tower\n";
    OutputStack(c);
    cout << "============================\n";
}

int main () {
    STACK a, b, c;
    NODE *p;
    CreateStack(a);
    CreateStack(b);
    CreateStack(c);
    int res, choose, x, y;
    do {
        cout << "Nhap so luong thap: ";
        cin >> choose;
        cout << "\n";
    } while (choose != 3 && choose != 4);
  
    while (!Check(c, choose)) {
        Init();
        Output(a, b, c);
        cout << "Nhap lua chon cua ban: ";
        cin >> res;
        cout << "\n";
        switch (res) {
            case 0:
                CreatingTower(a, choose);
                break;
            case 1:
                if (!Move(a, b)) {
                    cout << "Khong hop le, vui long nhap lai!\n\n";
                    continue;
                }
                break;
            case 2:
                if (!Move(b, a)) {
                    cout << "Khong hop le, vui long nhap lai!\n\n";
                    continue;
                }
                break;
            case 3:
                if (!Move(b, c)) {
                    cout << "Khong hop le, vui long nhap lai!\n\n";
                    continue;
                }
                break;
            case 4:
                if (!Move(c, b)) {
                    cout << "Khong hop le, vui long nhap lai!\n\n";
                    continue;
                }
                break;
            case 5:
                if (!Move(c, a)) {
                    cout << "Khong hop le, vui long nhap lai!\n\n";
                    continue;
                }
                break;
            case 6:
                if (!Move(a, c)) {
                    cout << "Khong hop le, vui long nhap lai!\n\n";
                    continue;
                }
                break;
            case 7:
                cout <<"EXIT\n";
                return 0;
            default:
                cout << "Lua chon khong hop le, vui long nhap lai:\n";
        }
    }
    cout <<"\n";
    Output(a, b, c);
    cout <<"CHUC MUNG! BAN DA CHIEN THANG TRO CHOI";
}