#include <iostream>
#define MAXN 10000
using namespace std;

struct STACK {
    long a[MAXN];
    long n;
};


void CreateStack(STACK &s) {
    s.n = -1;
}

bool IsEmpty (STACK s) {
    if (s.n == -1)
        return true;
    return false;
}

bool IsFull (STACK s) {
    if (s.n >= MAXN)
        return true;
    return false;
}

bool Push (STACK &s, long x) {
    if (!IsFull(s)) {
        s.n ++;
        s.a[s.n] = x;
        return true;
    }
    return false;
}

bool Pop (STACK &s, long &x) {
    if (!IsEmpty(s)) {
        x = s.a[s.n];
        s.n --;
        return true;
    }
    return false;
}

int main () {
   
}