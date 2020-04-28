// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 01 - Bài 01
// Ngôn ngữ: C++

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#define MAXN 10000
#define ll long long

using namespace std;

struct DT
{
    float he;
    long mu;
};

void cau1 (DT a[], long &n)
{
    cout << "SO LUONG DON THUC = ";
    cin >> n;
    for (long i = 0; i < n; i++)
    {
        cout << "HE SO THU " << i + 1 << " = ";
        cin >> a[i].he;
        cout << "MU SO THU " << i + 1 << " = ";
        cin >> a[i].mu;
    }
}

void cau2 (DT a[], long &n)
{
    srand(time(0));
    long m = 5 + rand()%4;
    n = 0;
    while (m >= 0)
    {
        a[n].he = 10 + rand()%90;
        a[n].mu = m;
        n++;
        m--;
    }

}
void cau3 (DT a[], long n)
{
    cout << "y = f(x) = ";
    for (long i = 0; i < n - 1; i++)
    {
        cout << a[i].he << "x^" << a[i].mu << " + ";
    }
    cout << a[n - 1].he << "x^" << a[n - 1].mu << endl;
}



void cau4 (DT a[], long n)
{
    float res = 0;
    long x;
    cout <<"X = ";
    cin >> x;
    for (long i = 0; i < n; i++)
    {
        res = res + a[i].he * pow(x, a[i].mu);
    }

    cout << "y = F(x) = " << res << endl;
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

int main ()
{
    long n; DT a[MAXN];
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
