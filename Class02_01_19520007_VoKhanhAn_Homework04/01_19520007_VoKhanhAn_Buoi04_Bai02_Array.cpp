// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 04 - Bài 02
// Ngôn ngữ: C++ / Cài đặt bằng Mảng

#include <iostream>
#include <cmath>
#define MAXN 10000

using namespace std;

struct info{
    double coefficient, exponent;
};

struct QUEUE {
    info a[MAXN];
    int Front, Rear;
};

void CreateQueue (QUEUE &q) {
    q.Front = -1;
    q.Rear = -1;
}

bool IsEmpty (QUEUE q) {
    if (q.Front == -1)
        return true;
    return false;
}


bool IsFull (QUEUE q) {
    if (q.Rear - q.Front + 1 == MAXN)
        return true;
    return false;
}

bool EnQueue (QUEUE &q, info x) {
    int f, r;
    if (IsFull(q))
        cout << "Queue bi day, khong them duoc\n";
    else {
        if (q.Front == -1) {
            q.Front = 0;
            q.Rear = -1;
        }
        if (q.Rear == MAXN - 1) {
            f = q.Front;
            r = q.Rear;
            for (int i = f; i <=r; i++) 
                q.a[i - f] = q.a[i];
            q.Front = 0;
            q.Rear = r - f;
        }
        q.Rear++;
        q.a[q.Rear] = x;
    }
}

bool Front (QUEUE &q, info &trave) {
    if (!IsEmpty(q)) {
        trave = q.a[q.Front];
        return true;
    }
    return false;
}

bool DeQueue (QUEUE &q, info &x) {
    if (!IsEmpty(q)) {
        x = q.a[q.Front];
        q.Front++;
        if (q.Front > q.Rear) {
            q.Front = -1;
            q.Rear = -1;
        }
        return true;
    }
    return false;
}

bool Rear (QUEUE &q, info &trave) {
    if (!IsEmpty(q)) {
        trave = q.a[q.Rear];
        return true;
    }
    return false;
}

void OutputQueue(QUEUE q) {
    cout << "QUEUE: FRONT<\t";
    for (int i = q.Front; i <= q.Rear; i++) {
        if (i != q.Front  && q.a[i].coefficient >= 0)
            cout << "+ ";
        cout << q.a[i].coefficient << "x^" << q.a[i].exponent << " ";
    }
    cout << ">REAR\n\n";
}

void Init()
{
    cout << "1: EnQueue\n";
    cout << "2: DeQueue\n"; 
    cout << "3: Front\n";
    cout << "4: Rear\n";
    cout << "5: IsFull\n";
    cout << "6: IsEmpty\n";
    cout << "7: Thoat khoi chuong trinh!\n";
    cout << "------------------\n\n";
}


int main () {
    QUEUE q; int choose, tm;
    info x; double res = 0, xx;
    CreateQueue(q);

    while (true) {
        Init();
        if (!IsEmpty(q))
            OutputQueue(q);
        cin >> choose;
        switch (choose) {
            case 1:
                do {
                    cout << "Nhap he so = ";
                    cin >> x.coefficient;
                    cout << "Nhap mu so = ";
                    cin >> x.exponent;
                    EnQueue(q, x);
                    cout << "Nhan 0 de dung nhap, nhan 1 de tiep tuc!\n";
                    cin >> tm;
                } while (tm != 0);
                cout << "Nhap gia tri x = ";
                cin >> xx;
                cout << "\n";
                break;
            case 2:
                if (!IsEmpty(q)) {
                    DeQueue(q, x);
                    res += x.coefficient * pow(xx, x.exponent);
                    cout << "TONG CUA DA THUC DUOC LAY RA HIEN TAI = " << res << "\n";
                }
                else cout << "Danh sach rong!\n";
                break;
            case 3:
                if (!IsEmpty(q)) {
                    Front(q, x);
                    cout << "Don thuc nam o dau Queue la: ";
                    cout << x.coefficient << "x^" << x.exponent << "\n\n";
                }
                else cout << "Danh sach rong!\n";
                break;
            case 4:
                if (!IsEmpty(q)) {
                    Rear(q, x);
                    cout << "Don thuc nam o cuoi Queue la: ";
                    cout << x.coefficient << "x^" << x.exponent << "\n\n";
                }
                else cout << "Danh sach rong!\n";
                break;
            case 5:
                if(IsFull(q)) 
                    cout << "Queue bi day!\n\n";
                else cout <<"Queue KHONG day!\n\n";
                break;
            case 6:
                if (IsEmpty(q))
                    cout << "Queue bi rong!\n\n";
                else cout << "Queue KHONG rong!\n\n";
                break;
            case 7:
                cout <<"EXIT\n";
                return 0;
            default:
                cout << "Lua chon khong hop le, vui long nhap lai:\n";
        }
    }
}