// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 02 - Bài 03
// Ngôn ngữ: C++

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAXN 105

using namespace std;

void cau1(long a[], long &n)
{
    srand(time(0));
    n = 15 + rand() % 16;
    for (long i = 0; i < n; i++)
    {
        a[i] = 555 + rand() % 445;
    }
}

void cau2(long a[], long &n)
{
    n = 1;
    a[0] = 10 + rand ()%90;
    while (a[n - 1] < 99)
    {
        a[n] = a[n - 1] + 1 + rand()%(99 - a[n-1]);
        n++;
    }
}

void cau3(long a[], long n)
{
    cout << "n = " << n << endl;
    for (long i = 0; i < n; i++)
        cout << "a[" << i << "] = " << a[i] << endl;
}

void qsort(long a[], long l, long r)
{
    long x = a[(l + r) / 2], i = l, j = r;
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;

        if (i <= j)
        {
            swap (a[i], a[j]);
            i++; j--;
        }
    } while (i <= j);

    if (l < j) qsort (a, l, j);
    if (i < r) qsort (a, i, r);
}

long bs (long a[], long n, long x)
{
    long l = 0, r = n - 1, m;
    while (l <= r)
    {
        m = l + ((r - l) / 2);
        if (x == a[m])
            return m;
        if (x < a[m])
            r = m - 1;
        else l = m + 1;
    }
    return -1;
}

void cau4(long a[], long n)
{
    long x;
    cout << "NHAP X = ";
    cin >> x;
    qsort (a, 0, n - 1);
    long res = bs(a, n, x);
    if (res != -1)
        cout << "PHAN TU X CO XUAT HIEN TRONG DANH SACH" << endl;
    else cout << "PHAN TU X KHONG CO TRONG DANH SACH" << endl;
}

void init()
{
    cout << "NHAN 1 - CHAY CAU 1" << endl;
    cout << "NHAN 2 - CHAY CAU 2" << endl;
    cout << "NHAN 3 - CHAY CAU 3" << endl;
    cout << "NHAN 4 - CHAY CAU 4" << endl;
    cout << "NHAN 5 - THOAT KHOI CHUONG TRINH" << endl;
    cout << "-------------------" << endl;
    cout << endl;
}

int main()
{
    long n, a[MAXN];
    int res;
    while (true)
    {
        init ();
        cin >> res;
        switch (res)
        {
            case 1:
                cau1(a, n);
                cout << endl;
                break;
            case 2:
                cau2(a, n);
                cout << endl;
                break;
            case 3:
                cau3(a, n);
                cout << endl;
                break;
            case 4:
                cau4(a, n);
                cout << endl;
                break;
            case 5:
                cout <<"EXIT" << endl;
                return 0;
            default:
                cout << "Ban da nhap sai, vui long nhap lai: " << endl;
                cout << endl;
        }
    }
}
