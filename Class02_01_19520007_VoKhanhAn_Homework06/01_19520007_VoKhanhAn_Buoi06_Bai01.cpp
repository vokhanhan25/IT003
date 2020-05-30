// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 06 - Bài 01
// Ngôn ngữ: C++

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>

#define MAXN 1e5

using namespace std;

void InputRandom(double a[], int &n) {
    srand(time(0));
    n = MAXN;
    for (int i = 0; i < n; i++)
        a[i] = rand() + rand() / (double)RAND_MAX;
}

void SelectionSort(double a[], int n) {
    int min;
    for (int i = 0;i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[i], a[min]);
    }
}

void InsertionSort(double a[], int n) {
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

double GetTimeSelectionSort(double a[], int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    SelectionSort(a, n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double GetTimeInsertionSort(double a[], int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    InsertionSort(a, n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

void Output (double a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i <<"] = " << a[i] << "\n";
    }
    cout << "\n\n";
}

void CopyArray (double a[], int n, double b[]) {
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}


void Init()
{
    cout << "1: Tao mang tu dong\n";
    cout << "2: Sap xep mang & Dem thoi gian - Selection Sort\n";
    cout << "3: Sap xep mang & Dem thoi gian - Insertion Sort\n";
    cout << "4: So sanh - 15 testcase\n";
    cout << "5: Xuat mang\n";
    cout << "6: Thoat khoi chuong trinh!\n";
    cout << "------------------\n\n";
}

int main() {
    int n, choose;
    double a[int(1e5)], b[int(1e5)];
    
    while (true) {
        Init();
        cin >> choose;
        switch (choose) {
            case 1:
                InputRandom(a, n);
                cout << "Da nhap tu xong!\n\n";
                break;
            
            case 2:
                cout << "Thoi gian thuc hien Selection Sort =  " << GetTimeSelectionSort(a, n) << "s" << "\n\n";
                break;

            case 3:
                cout << "Thoi gian thuc hien Insertion Sort =  " << GetTimeInsertionSort(a, n) << "s" << "\n\n";
                break;

            case 4:
                cout << "Dataset        ";
                cout << "Selection Sort           ";
                cout << "Insertion Sort\n";
                for (int i = 0; i < 15; i++) {
                    InputRandom(a, n);
                    CopyArray(a, n, b);
                    cout << "Dataset " << i + 1 << "         "; 
                    cout << GetTimeSelectionSort(b, n) << "s                   ";
                    cout << GetTimeInsertionSort(a, n) << "s\n";
                }
                break;
            case 5:
                Output(a, n);
                break;
            case 6:
                cout <<"EXIT\n";
                return 0;
            default:
                cout << "Lua chon khong hop le, vui long nhap lai:\n";
        }
    }
}