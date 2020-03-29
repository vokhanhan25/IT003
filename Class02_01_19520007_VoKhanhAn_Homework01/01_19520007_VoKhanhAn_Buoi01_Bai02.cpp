// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 01 - Bài 02
// Ngôn ngữ: C++

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAXN 105

using namespace std;

struct str
{
    long cnt, val;
};


void cau1(long a[], long &n)
{
    cout << "n = ";
    cin >> n;
    for (long i = 0; i < n; i ++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
        
}

void cau2(long a[], long &n)
{
    srand(time(0));
    n = 10 + rand() % 40;
    for (long i = 0; i < n; i++)
    {
        a[i] = 100 + rand() % 20;
    }
}

void cau3(long a[], long n)
{
    cout << "n = " << n << endl;
    for (long i = 0; i < n; i++)
        cout << "a[" << i << "] = " << a[i] << endl;
}

void qsort(long a[], long n, long l, long r)
{
    long x = a[(l + r) / 2], i = l, j = r;
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;

        if (i <= j)
        {
            long tm = a[i];
            a[i] = a[j];
            a[j] = tm;
            i++; j--;
        }
    } while (i <= j);

    if (l < j) qsort (a, n, l, j);
    if (i < r) qsort (a, n, i, r);
}

void cau4(long a[], long n)
{
    qsort (a, n, 0 ,n - 1);

    long m = 0; str b[MAXN];
    
    b[0].val = a[0];
    b[0].cnt = 1;

    for (long i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1])
        {
            b[m].cnt++;
        }
        else {
            m++;
            b[m].val = a[i + 1];
            b[m].cnt = 1;
        }
    for (long i = 0; i <= m; i++) {
        cout << "GIA TRI = " << b[i].val << endl;
        cout << "SO LUONG = " << b[i].cnt << endl;
        cout << endl;
    }
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