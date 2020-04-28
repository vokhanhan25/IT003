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


void OutputStack(STACK s) {
    cout << "STACK: ";
    for (int i = 0; i <= s.top; i++)
        cout << s.a[i] << " ";
    cout << "\n";
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
                Push(s, x);
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
                if (IsFull(s))
                    cout << "Stack day\n\n";
                else cout <<"Stack khong day\n\n";
                break;
            case 6:
                cout <<"EXIT" << endl;
                return 0;
            default:
                cout << "Ban da nhap sai, vui long nhap lai: \n\n";
        }
        OutputStack(s);
    }
}