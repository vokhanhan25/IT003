#include <iostream>
#define MAXN 10000
using namespace std;

struct STACK {
    int a[MAXN];
    int top;
};


void CreateStack(STACK &s) {
    s.top = -1;
}

bool IsEmpty (STACK s) {
    if (s.top == -1)
        return true;
    return false;
}

bool IsFull (STACK s) {
    if (s.top >= MAXN)
        return true;
    return false;
}

bool Push (STACK &s, int x) {
    if (!IsFull(s)) {
        s.top ++;
        s.a[s.top] = x;
        return true;
    }
    return false;
}


bool Pop (STACK &s, int &x) {
    if (!IsEmpty(s)) {
        x = s.a[s.top];
        s.top --;
        return true;
    }
    return false;
}

bool Top (STACK &s, int &x) {
    if (!IsEmpty(s)) {
        x = s.a[s.top];
        return true;
    }
    return false;
}

void OutputStack(STACK s) {
    cout << "STACK = <\t";
    for (int i = 0; i <= s.top; i++)
        cout << s.a[i] << "\t";
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

    for (int i = choose; i > 0; i--) 
        Push(a, i);
}

bool Check(STACK s, int choose) {
    int i = 0;
    while (i < s.top && s.a[i] > s.a[i + 1])
        i++;
    if (i + 1 == choose)
        return true;
    return false;
}

bool Move(STACK &a, STACK &b) {
    int x, y, z;
    if (!Top(a, x))
        return false;
    Top(b, y);
    if (x < y || !IsEmpty(b)) {
        Pop(a, z);
        Push(b, z);
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
    cout <<"CHUC MUNG! BAN DA CHIEN THANG TRO CHOI";
}