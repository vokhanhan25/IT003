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
    srand(time(0));
    n = 15 + rand() % 16;
    for (long i = 0; i < n; i++)
    {
        a[i] = 555 + rand() % 445;
    }
}

void cau2(long a[], long &n)
{
    n = 0;
    a[0] = 10 + rand ()%90;
    while (true)
    {
        n++;
        a[n] = a[n - 1] + 1 + rand()%(98 - a[n-1] + 1);
        if (a[n] == 99)
            break;
    }
    n++;
}

void cau3(long a[], long n)
{
    cout << "n = " << n << endl;
    for (long i = 0; i < n; i++)
        cout << "a[" << i << "] = " << a[i] << endl;
}


void init()
{
    cout << "NHAN 1 - CHAY CAU 1" << endl;
    cout << "NHAN 2 - CHAY CAU 2" << endl;
    cout << "NHAN 3 - CHAY CAU 3" << endl;
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
            case 5:
                cout <<"EXIT" << endl;
                return 0;
            default:
                cout << "Ban da nhap sai, vui long nhap lai: " << endl;
                cout << endl;
        }
    }
}
