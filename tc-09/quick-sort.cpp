#include <iostream>

#define MAXN 1000

using namespace std;

void QuickSort (int a[], int l, int r) {
    int i, j, x;
    x = a[(l + r) / 2];
    i = l; j = r;
    while (i <= j) {
        while (a[i] > x) i++;
        while (a[j] < x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) 
        QuickSort(a, l, j);
    if (i < r)
        QuickSort(a, i, r);
}

int main() {
    int n, a[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    QuickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}