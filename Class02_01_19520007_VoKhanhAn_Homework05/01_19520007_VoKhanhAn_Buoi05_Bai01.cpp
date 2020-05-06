// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 05 - Bài 01
// Ghi chú: Bài này em sử dụng hàm search có sẵn trong thư viện algorithm ở case 7
// Link tham khảo thư viện: http://www.cplusplus.com/reference/algorithm/search/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>

#define MAXN 1005

using namespace std;

void InputRandom(int a[], int &n) {
    srand(time(0));
    n = 30 + rand() % 21;
    for (int i = 0; i < n; i++) 
        a[i] = 100 + rand() % 900;
    cout << "Da nhap tu xong!\n\n";
}

void InputAscending(int a[], int &n) {
    srand(time(0));
    a[0] = 100 + rand() % 31;
    n = 30 + rand () % 21;
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + rand() % 16;
    }
    cout << "Da nhap tu dong tang dan xong!\n\n";
}

void Output (int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i <<"] = " << a[i] << "\n";
    }
    cout << "\n\n";
}

int LinearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (x == a[i])
            return i;
    return -1;
}

int CountLinearSearch(int a[], int n, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        if (x == a[i])
            break;
    }
    return cnt;
}

int BinarySearch (int a[], int n, int x) {
    int l = 0, r = n - 1, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (a[m] == x)
            return m;
        else if (a[m] < x) 
            l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int CountBinarySearch (int a[], int n, int x) {
    int l = 0, r = n - 1, m, cnt = 0;
    while (l <= r) {
        m = l + (r - l) / 2;
        cnt++;
        if (a[m] == x)
            break;
        else if (a[m] < x) 
            l = m + 1;
        else r = m - 1;
    }
    return cnt;
}

int InterpolationSearch (int a[], int n, int x) {
    int l = 0, r = n - 1, m;
    while (l <= r) {
        m = l + ((r - l) * (x - a[l]) / (a[r] - a[l]));
        if (a[m] == x)
            return m;
        else if (a[m] < x) 
            l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int CountInterpolationSearch (int a[], int n, int x) {
    int l = 0, r = n - 1, m, cnt = 0;
    while (l <= r) {
        m = l + ((r - l) * (x - a[l]) / (a[r] - a[l]));
        cnt++;
        if (a[m] == x)
            break;
        else if (a[m] < x) 
            l = m + 1;
        else r = m - 1;
    }
    return cnt;
}

void Search(int a[], int n, int x) {
    vector<int> v(a, a + n);
    int tm[1];
    tm[0] = x;
    vector<int>::iterator it;
    it = search (v.begin(), v.end(), tm, tm + 1);

    if (it != v.end()) 
        cout << "Vi tri cua x trong ArrayY = " << (it-v.begin()) << '\n';
    else cout << "Khong tim thay x trong ArrayY\n";   
    cout << "\n";
} 

void Init()
{
    cout << "1: Tao mang tu dong - Array X/Y\n";
    cout << "2: Xuat mang - Array X/Y\n";
    cout << "3: Linear Search - Array X/Y\n";
    cout << "4: Binary Search - ArrayY\n";
    cout << "5: Interpolation Search - ArrayY\n";
    cout << "6: So sanh so lan thuc hien - ArrayY\n";
    cout << "7: Search trong thu vien Algorithms - ArrayY\n";
    cout << "8: Thoat khoi chuong trinh!\n";
    cout << "------------------\n\n";
}

void Compare (int a[], int n , int x) {
    int cnt1 = CountLinearSearch(a, n, x);
    int cnt2 = CountBinarySearch(a, n, x);
    int cnt3 = CountInterpolationSearch(a, n, x);
    int rmax = max(cnt1, max(cnt2, cnt3));
    int rmin = min(cnt1, min(cnt2, cnt3));

    if (rmax == cnt1)
        cout << "Tim kiem tuyen tinh co so lan thuc hien nhieu nhat\n";
    else if (rmax == cnt2)
        cout << "Tim kiem nhi phan co so lan thuc hien nhieu nhat\n";
    else if (rmax == cnt3)
        cout << "Tim kiem noi suy co so lan thuc hien nhieu nhat\n";
    cout << "So lan nhieu nhat = " << rmax << "\n\n";

    if (rmin == cnt1)
        cout << "Tim kiem tuyen tinh co so lan thuc hien it nhat\n";
    else if (rmin == cnt2)
        cout << "Tim kiem nhi phan co so lan thuc hien it nhat\n";
    else if (rmin == cnt3)
        cout << "Tim kiem noi suy co so lan thuc hien it nhat\n";
    cout << "So lan it nhat = " << rmin << "\n\n";
}

int main() {
    int n, m, a[MAXN], b[MAXN], choose, x, res;
    
    char c;   
    while (true) {
        Init();
        cin >> choose;
        switch (choose) {
            case 1:
                do {
                    cout << "Chon mang can tao (X/Y): ";
                    cin >> c;
                    if (c == 'X')
                        InputRandom(a, n);
                    else if (c == 'Y') {
                        InputAscending(b, m);
                    }
                    else 
                        cout << "Khong hop le, vui long nhap lai!\n\n";
                } while (c != 'X' && c != 'Y');
                break;

            case 2:
                do {
                    cout << "Chon mang can xuat (X/Y): ";
                    cin >> c;
                    if (c == 'X')
                        Output(a, n);
                    else if (c == 'Y')
                        Output(b, m);
                    else 
                        cout << "Khong hop le, vui long nhap lai!\n\n";
                } while (c != 'X' && c != 'Y');
                break;

            case 3:
                do {
                    cout << "Chon mang can tim kiem bang Linear Search (X/Y): ";
                    cin >> c;
                    cout << "Nhap gia tri can tim kiem cho Array" << c << ": ";
                    cin >> x;
                    if (c == 'X') {
                        res = LinearSearch(a, n, x);
                        if (res == -1)
                            cout << "Khong tim thay x trong ArrayX\n\n";
                        else cout << "Vi tri cua x trong ArrayX = " << res << "\n\n";
                    }
                    else if (c == 'Y') {
                        res = LinearSearch(b, m, x);
                        if (res == -1)
                            cout << "Khong tim thay x trong ArrayY\n\n";
                        else cout << "Vi tri cua x trong ArrayY = " << res << "\n\n";
                    }
                    else 
                        cout << "Khong hop le, vui long nhap lai!\n\n";
                } while (c != 'X' && c != 'Y');
                break;

            case 4:
                cout << "Nhap gia tri can tim kiem cho ArrayY: ";
                cin >> x;
                res = BinarySearch(b, m ,x);
                if (res == -1)
                    cout << "Khong tim thay x trong ArrayY\n\n";
                else cout << "Vi tri cua x trong ArrayY = " << res << "\n\n";
                break;

            case 5:
                cout << "Nhap gia tri can tim kiem cho ArrayY: ";
                cin >> x;
                res = InterpolationSearch(b, m, x);
                if (res == -1)
                    cout << "Khong tim thay x trong ArrayY\n\n";
                else cout << "Vi tri cua x trong ArrayY = " << res << "\n\n";
                break;

            case 6:
                cout << "Nhap gia tri can tim kiem = ";
                cin >> x;
                Compare(b, m , x);
                break;
            case 7:
                do {
                    cout << "Chon mang can tim kiem bang ham Search trong thu vien algorithm (X/Y): ";
                    cin >> c;
                    cout << "Nhap gia tri can tim kiem cho Array" << c << ": ";
                    cin >> x;
                    if (c == 'X') {
                        sort (a, a + n);
                        cout << "ArrayX da duoc sap xep tang dan!\n";
                        Search(a, n, x);
                    }
                    else if (c == 'Y') {
                        Search(b, m, x);
                    }
                    else 
                        cout << "Khong hop le, vui long nhap lai!\n\n";
                } while (c != 'X' && c != 'Y');
                break;
            case 8:
                cout <<"EXIT\n";
                return 0;
            default:
                cout << "Lua chon khong hop le, vui long nhap lai:\n";
        }
    }
}