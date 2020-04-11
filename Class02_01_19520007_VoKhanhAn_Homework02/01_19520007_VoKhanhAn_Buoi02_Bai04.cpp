// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 02 - Bài 04
// Ngôn ngữ: C++

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#define MAXN 105
#define MAXI 1000000000
#define ll long long

using namespace std;

void cau1(long a[], long &n)
{
    srand(time(0));
    n = 5 + rand() % 6;
    for (long i = 0; i < n; i++)
        a[i] = -10 + rand() % 21;
}


void cau2(long a[], long n)
{
    cout << "n = " << n << endl;
    for (long i = 0; i < n; i++)
        cout << "a[" << i << "] = " << a[i] << endl;
}

ll cau3(long a[], long n)
{
    long cnt0 = 0, cntNeg = 0, maxNeg = -MAXI;
    ll product = 1;

    for (long i = 0; i < n; i++)
        if (a[i] == 0) cnt0++;
        else { 
            if (a[i] < 0) {
                cntNeg++;
                maxNeg = max(maxNeg, a[i]);
            }
            product = product * a[i];
        }
    if (cnt0 == n || (cntNeg == 1 && cnt0 == n - 1))
        return 0;

    if (cntNeg % 2 == 1)
        product = product / maxNeg;
    return product;
}

void init()
{
    cout << "NHAN 1 - CHAY CAU 1" << endl;
    cout << "NHAN 2 - CHAY CAU 2" << endl;
    cout << "NHAN 3 - CHAY CAU 3" << endl;
    cout << "NHAN 4 - THOAT KHOI CHUONG TRINH" << endl;
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
                cout << "TICH LON NHAT CUA TAP CON = " << cau3(a, n) << endl;
                cout << endl;
                break;
            case 4:
                cout <<"EXIT" << endl;
                return 0;
            default:
                cout << "Ban da nhap sai, vui long nhap lai: " << endl;
                cout << endl;
        }
    }
}
