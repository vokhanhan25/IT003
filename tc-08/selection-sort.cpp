#include <iostream>
#define MAXN 10000

using namespace std;

void SelectionSort(int a[], int n) {
    int min;
    for (int i = 0;i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[i], a[min]);
    }
}

int main() {
    int n, a[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SelectionSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}