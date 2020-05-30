#include <iostream>
#include <algorithm> //sort (C++)
#include <stdlib.h> //qsort (C)
#include <time.h> // Đo thời gian

#define MAXN 1e7

using namespace std;

double a[int(MAXN)], b[int(MAXN)];

void Shift (double a[], int l, int r) {
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

void CreateHeap(double a[], int n) {
    int l = n / 2 - 1;
    while (l >= 0) {
        Shift(a, l , n - 1);
        l--;
    }
}

void HeapSort (double a[], int n) {
    CreateHeap(a, n);
    int r = n - 1;
    while (r > 0) {
        swap(a[0], a[r]);
        r--;
        if (r > 0) 
            Shift(a, 0, r);
    }
}

double GetTimeSort(double a[], int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    sort(a, a + n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int compare (const void * a, const void * b)
{
  return ( *(double*)a - *(double*)b );
}

double GetTimeQSort(double a[], int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    qsort (a, n, sizeof(int), compare);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double GetTimeHeapSort(double a[], int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    HeapSort (a, n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

void InputRandom(double a[], int &n) {
    srand(time(0));
    n = MAXN;
    for (int i = 0; i < n; i++)
        a[i] = rand() + rand() / (double)RAND_MAX;
}

void CopyArray (double a[], int n, double b[]) {
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

int main() {
    int n;

    cout << "Dataset        ";
    cout << "Heap Sort           ";
    cout << "sort\n";
    cout << "qsort\n";
    for (int i = 0; i < 15; i++) {
    InputRandom(a, n);
    CopyArray(a, n, b);
        cout << "Dataset " << i + 1 << "         "; 
        cout << GetTimeHeapSort(b, n) << "s                   ";
        cout << GetTimeSort(b, n) << "s                   ";
        cout << GetTimeQSort(a, n) << "s\n";
    }
}