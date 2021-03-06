// STT: 01
// Họ và tên: Võ Khánh An
// Buổi 03 - Bài 02
// Ngôn ngữ: C++

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

struct STUDENT {
    string name;
    double gpa;
};

struct NODE
{
    STUDENT info;
    struct NODE *pNext;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

void CreateEmptylist (LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE* CreateNode (STUDENT x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

bool IsEmpty (LIST &l)
{
    if (l.pHead == NULL)
        return true;
    return false;
}

void AddHead (LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail (LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void InputList(LIST &l, long &n)
{
    STUDENT x; NODE *p;
    string t; n = 0;
    cout << "NHAP SINH VIEN: " << endl;
    do {
        cout << "NHAP TEN SINH VIEN THU " << n + 1 << " : ";
        fflush(stdin);
        getline(cin, x.name);
        while (true) {
            cout << "NHAP GPA SINH VIEN THU " << n + 1 << " : ";
            cin >> x.gpa;
            if (x.gpa >= 0 && x.gpa <= 10)
                break;
            else cout << "DIEM GPA KHONG HOP LE, VUI LONG NHAP LAI!\n";
        }
        p = CreateNode(x);
        if (p != NULL)
            AddTail (l,p);
        n++;
        cout << "BAN CO MUON TIEP TUC KHONG? (YES/NO): ";
        fflush(stdin);
        getline(cin, t);
        cout << "\n";
    } while (t != "NO");

    cout <<"DANG NHAP TU DONG... \n";
    srand(time(0));
    n = 1 + rand () % 20;
    for (int i = 0; i < n; i++) {
        string s = to_string(1 + rand () % 30);
        x.name = "Sinh vien " + s;
        x.gpa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/10));
        p = CreateNode(x);
        if (p != NULL)
            AddHead (l,p);
    }
    cout <<"NHAP TU DONG HOAN TAT!\n";
}


bool RemoveHead(LIST &l, double &x)
{
    NODE *p;
    if (l.pHead != NULL)
    {
        x = l.pHead -> info.gpa;
        p = l.pHead;
        l.pHead = l.pHead -> pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
        delete p;
        return true;
    }
    return false;
}

bool RemoveAfterQ (LIST &l, NODE *Q, double &x)
{
    NODE *p;
    if (Q != NULL) {
        NODE *p = Q -> pNext;
        Q -> pNext = p -> pNext;
        x = p->info.gpa;
        if (p == l.pTail)
            l.pTail = Q;
        delete p;
        return true;
    }
    return false;
}

bool RemoveX(LIST &l, double x)
{
    NODE *Q = NULL, *p = l.pHead;
    while (p != NULL && p->info.gpa != x)
    {
        Q = p;
        p = p -> pNext;
    }

    if (p == NULL) return false;
    if (Q != NULL) RemoveAfterQ(l, Q, x);
    else RemoveHead(l, x);

    return true;
}

void SearchNode(LIST l, double x, string &name)
{
    NODE *p = l.pHead;
    bool check = false;
    cout << "TEN NHUNG SINH VIEN CO DIEM GPA " << x << " LA:\n";
    while (p != NULL)
    {
        if (x == p->info.gpa) {
            name = p->info.name;
            if (!check) {
                cout << "TEN NHUNG SINH VIEN CO DIEM GPA " << x << " LA:\n";
                check = true;
            }
            cout << name << "\n";
        }
        p = p->pNext;
    }
    if (!check)
        cout << "KHONG CO SINH VIEN NAO THOA MAN\n";
}

void SortList (LIST &l)
{
    for (NODE *i = l.pHead; i != l.pTail; i = i->pNext)
        for (NODE *j = i ->pNext; j != NULL; j = j->pNext)
            if (i->info.gpa > j->info.gpa)
                swap (i->info, j->info);
}

bool RemoveHead(LIST &l, string &x)
{
    NODE *p;
    if (l.pHead != NULL)
    {
        x = l.pHead -> info.name;
        p = l.pHead;
        l.pHead = l.pHead -> pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
        delete p;
        return true;
    }
    return false;
}

bool RemoveAfterQ (LIST &l, NODE *Q, string &x)
{
    NODE *p;
    if (Q != NULL) {
        NODE *p = Q -> pNext;
        Q -> pNext = p -> pNext;
        x = p->info.name;
        if (p == l.pTail)
            l.pTail = Q;
        delete p;
        return true;
    }
    return false;
}

bool RemoveX(LIST &l, string x)
{
    NODE *Q = NULL, *p = l.pHead;
    while (p != NULL && p->info.name != x)
    {
        Q = p;
        p = p -> pNext;
    }

    if (p == NULL) return false;
    if (Q != NULL) RemoveAfterQ(l, Q, x);
    else RemoveHead(l, x);

    return true;
}

bool SetX(LIST &l, string y, STUDENT x)
{
    NODE *p = l.pHead;
    bool ok = false;
    while (p != NULL)
    {
        if (y == p->info.name) {
            p->info = x;
            ok = true;
        }
        p = p->pNext;
    }
    if (ok) return true;
    return false;
}

void OutputList(LIST l)
{
    NODE *p = l.pHead;
    cout << "DANH SACH SINH VIEN HIEN TAI LA: " << endl;
    while (p != NULL)
    {
        cout << p->info.name << " " << p->info.gpa << endl;
        p = p->pNext;
    }
    cout << endl;
}

void Init()
{
    cout << "NHAN 1 - NHAP DANH SACH SINH VIEN" << endl;
    cout << "NHAN 2 - SAP XEP DANH SACH SINH VIEN THEO GPA" << endl;
    cout << "NHAN 3 - TIM KIEM SINH VIEN THEO GPA" << endl;
    cout << "NHAN 4 - XOA SINH VIEN TRONG DANH SACH BANG KHOA TEN SINH VIEN" << endl;
    cout << "NHAN 5 - CAP NHAT SINH VIEN TRONG DANH SACH BANG KHOA TEN SINH VIEN" << endl;
    cout << "NHAN 6 - IN DANH SACH SINH VIEN" << endl;
    cout << "NHAN 7 - THOAT KHOI CHUONG TRINH" << endl;
    cout << "-------------------" << endl;
    cout << endl;
}

int main()
{
    STUDENT t;
    LIST l;
    double x;
    long n, choose; 
    string st, y;
    NODE *p;
    CreateEmptylist(l);

    while (true) {
        cout << endl;
        Init ();
        cin >> choose;
        switch (choose) {
            case 1:
                InputList(l, n);
                break;         
            case 2:
                SortList(l);
                cout << "DANH SACH DA DUOC SAP XEP! \n"; 
                break; 
            case 3:
                cout << "NHAP DIEM GPA CAN TIM = ";
                cin >> x;
                SearchNode(l, x, st);
                break;
            case 4:
                cout << "NHAP TEN SINH VIEN CAN XOA: ";
                fflush (stdin);
                getline (cin, st);
                if (RemoveX(l, st)) 
                    cout << "DA XOA THANH CONG \n";
                else cout << "TEN SINH VIEN KHONG TON TAI \n";
                break;
            case 5:
                cout << "NHAP TEN SINH VIEN CAN CAP NHAT TRONG DANH SACH = ";
                fflush (stdin);
                getline (cin, y);
                cout << "NHAP TEN SINH VIEN SE DUOC CAP NHAT TEN = ";
                fflush (stdin);
                getline (cin, t.name);

                cout << "NHAP DIEM GPA CUA SINH VIEN SE DUOC CAP NHAT = ";
                cin >> t.gpa;
                if (SetX(l, y, t)) 
                    cout << "CAP NHAT TEN SINH VIEN THANH CONG! \n";
                else cout << "SINH VIEN CAN CAP NHAT KHONG TON TAI! \n";
                break;
            case 6:
                OutputList(l);
                break;
            case 7:
                cout <<"EXIT" << endl;
                return 0;
            default:
                cout << "Ban da nhap sai, vui long nhap lai: " << endl;
                cout << endl;
        }
    }
}
