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
}

int main () {
    STACK s;
    CreateStack(s);
    Push(s, 5);
    Push(s, 3);
    OutputStack(s);
}