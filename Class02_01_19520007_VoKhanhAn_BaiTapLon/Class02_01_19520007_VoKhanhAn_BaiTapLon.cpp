#include <iostream>
#include <algorithm> //sort (C++)
#include <stdlib.h> //qsort (C)
#include <time.h> // Đo thời gian

#define MAXN 1e7
#define space 11
#define space2 13

using namespace std;

double a[int(MAXN)], b[int(MAXN)], L[int(MAXN)], R[int(MAXN)]; 

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

void QuickSort (double a[], int l, int r) {
    int i, j;
    srand(time(NULL));
    double x = a[l + rand() % (r - l + 1)];
    i = l; j = r;
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
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

void Merge(double a[], int l, int m, int r)  { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
  
    i = 0;  
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            a[k] = L[i]; 
            i++; 
        } 
        else { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void MergeSort(double a[], int l, int r) 
{ 
    if (l < r) {
        int m = l+(r-l)/2; 
        MergeSort(a, l, m); 
        MergeSort(a, m+1, r);
        Merge(a, l, m, r); 
    } 
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

double GetTimeQuickSort(double a[], int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    QuickSort (a, 0, n - 1);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double GetTimeMergeSort(double a[], int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    MergeSort (a, 0, n - 1);

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

void Format (int n) {
    while (n--) 
        cout << " ";
}

int main() {
    int n;

    cout << "Dataset";
    Format(space);

    cout << "Heap Sort";
    Format(space);

    cout << "Quick Sort";
    Format(space);

    cout << "Merge Sort";
    Format(space);
    cout << "sort";

    Format(space);
    cout << "qsort\n";


    for (int i = 0; i < 15; i++) {
        InputRandom(a, n);
        CopyArray(a, n, b);
        cout << "Dataset " << i + 1;
        Format(space);

        CopyArray(a, n, b);
        cout << GetTimeHeapSort(b, n) << "s";
        Format(space2);

        CopyArray(a, n, b);
        cout << GetTimeQuickSort(b, n) << "s";
        Format(space2);

        CopyArray(a, n, b);
        cout << GetTimeMergeSort(b, n) << "s";
        Format(space2);

        CopyArray(a, n, b);
        cout << GetTimeSort(b, n) << "s";
        Format(space2);

        CopyArray(a, n, b);
        cout << GetTimeQSort(b, n) << "s";
        Format(space2);

        cout << "\n";
    }
}