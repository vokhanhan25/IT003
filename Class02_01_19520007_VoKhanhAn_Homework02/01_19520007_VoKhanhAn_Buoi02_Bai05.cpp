// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 02 - Bài 05
// Ngôn ngữ: C++

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#define MAXN 55
#define ll long long 

using namespace std;

void cau1(ll a[], long &n)
{
    srand(time(0));
    n = 10 + rand() % 41;
    a[0] = 1; a[1] = 1;
    for (long i = 2; i < n; i++)
        a[i] = a[i - 1] + a[i - 2];
}


void cau2(ll a[], long n)
{
    cout << "n = " << n << endl;
    for (long i = 0; i < n; i++)
        cout << "a[" << i << "] = " << a[i] << endl;
}

void cau3(ll a[], long n)
{
    long x;
    cout << "NHAP PHAN TU O VI TRI THU X MUON XEM TRONG DAY FIBO: ";
    cin >> x;
    cout << "PHAN TU O VI TRI THU X CO GIA TRI = " << a[x - 1] << endl;
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
    long n;
    ll a[MAXN];
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
                cout <<"EXIT" << endl;
                return 0;
            default:
                cout << "Ban da nhap sai, vui long nhap lai: " << endl;
                cout << endl;
        }
    }
}
