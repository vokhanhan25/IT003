#include <iostream>
#define MAXN 10000

using namespace std;

void InsertionSort(int a[], int n) {
    int pos, x;
    for (int i = 0;i < n; i++) {
        x = a[i]; pos = i - 1;
        while (pos >= 0 && a[pos] > x) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

int main() {
    int n, a[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    InsertionSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}