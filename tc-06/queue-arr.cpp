#include <iostream>
#define MAXN 10000

using namespace std;

struct QUEUE {
    long a[MAXN], Front, Rear;
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


bool DeQueue (QUEUE &q, long x) {
    long f, r;
    if (IsFull(q))
        cout << "QUEUE BI DAY, KHONG THEM DUOC" << endl;
    else {
        if (q.Front == -1) {
            q.Front = 0;
            q.Rear = -1;
        }
        if (q.Rear == MAXN - 1) {
            f = q.Front;
            r = q.Rear;
            for (long i = f; i <=r; i++) 
                q.a[i - f] = q.a[i];
            q.Front = 0;
            q.Rear = r - f;
        }
        q.Rear++;
        q.a[q.Rear] = x;
    }
}

bool EnQueue (QUEUE &q, long x) {
    if (!IsEmpty(q)) {
        x = q.a[q.Front];
        q.Front++;
        if (q.Front > q.Rear) {
            q.Front = -1;
            q.Rear = -1;
        }
        return true;
    }
    cout << "QUEUE RONG" << endl;
    return false;
}


int main () {

}