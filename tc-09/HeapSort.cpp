#include <iostream>
#define MAXN 10005

using namespace std;

void Shift (int a[], int l, int r) {
    int i ,j;
    i = l;
    j = 2 * i + 1;
    while (j <= r) {
        if (j < r && a[j] < a[j + 1])
            j++;
        if (a[j] <= a[i])
            return;
        swap(a[i], a[j]);
        i = j;
        j = 2 * i + 1;
    }
}

void CreateHeap(int a[], int n) {
    int l = n / 2 - 1;
    while (l >= 0) {
        Shift(a, l , n - 1);
        l--;
    }
}

void HeapSort (int a[], int n) {
    CreateHeap(a, n);
    int r = n - 1;
    while (r > 0) {
        swap(a[0], a[r]);
        r--;
        if (r > 0) 
            Shift(a, 0, r);
    }
}

int main() {
    int n, a[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    HeapSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}