#include <iostream>
#include <stdlib.h> 
#include <time.h> 

#define MAXN 1e6
#define space 9
#define space2 6

using namespace std;

double a[int(MAXN)], b[int(MAXN)];

int LinearSearch (double a[], int n, double x) {
    int i = 0; a[n] = x;
    while (a[i] != x) 
        i++;
    if (i == n)
        return -1;
    return i;
}

int BinarySearch (double a[], int n, double x) {
    int l = 0, r = n - 1, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (a[m] == x)
            return m;
        else if (a[m] < x) 
            l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int InterpolationSearch (double a[], int n, double x) {
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

struct NODE { 
    double key; 
    struct NODE *left, *right; 
}; 


  
NODE* CreateNode(double item) { 
    NODE *temp = new NODE; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
  
NODE* Insert(NODE* root, double key) 
{ 
    NODE* p = CreateNode(key); 
    NODE* x = root; 
    NODE* y = NULL; 
  
    while (x != NULL) { 
        y = x; 
        if (key < x->key) 
            x = x->left; 
        else
            x = x->right; 
    } 

    if (y == NULL) 
        y = p; 
  
    else if (key < y->key) 
        y->left = p; 
  
    else
        y->right = p; 
  
    return y; 
} 

bool SearchNode(NODE* root, double key) { 
    if (root == NULL) 
        return false; 
  
    if (root->key == key) 
        return true; 
  
    bool res1 = SearchNode(root->left, key); 
  
    if(res1) return true; 
  
    bool res2 = SearchNode(root->right, key); 
  
    return res2; 
} 

NODE * MinValueNode(NODE* node) { 
    NODE* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

NODE* DeleteNode(NODE* root, double key) { 
    if (root == NULL) return root; 
  
    if (key < root->key) 
        root->left = DeleteNode(root->left, key); 
  
    else if (key > root->key) 
        root->right = DeleteNode(root->right, key); 
  
    else { 
        if (root->left == NULL) { 
            NODE *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) { 
            NODE *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        NODE* temp = MinValueNode(root->right); 
  
        root->key = temp->key; 
  
        root->right = DeleteNode(root->right, temp->key); 
    } 
    return root; 
} 

void InputRandomA(double a[], int &n) {
    srand(time(0));
    n = MAXN;
    for (int i = 0; i < n; i++) 
        a[i] = rand() + rand() / (double)RAND_MAX;
}

void InputRandomB(double a[], int &n) {
    srand(time(0));
    n = MAXN; 
    int pos;
    for (int i = 0; i < n; i++) {
        double x = rand() + rand() / (double)RAND_MAX;
        pos = i - 1;
        while (pos >= 0 && a[pos] > x) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

NODE* InputRandomC(NODE *root) {
    srand(time(0));
    int n = MAXN; 
    bool checkRoot = false;
    for (int i = 0; i < n; i++) {
        double x = rand() + rand() / (double)RAND_MAX;
        if (checkRoot)
            Insert(root, x);
        else {
            root = Insert(root, x);
            checkRoot = true;
        }
    }
    return root;
}

void GetTimeInputRandomA(double a[], int &n, double &cpu_time_used) {
    clock_t start, end;

    start = clock();

    InputRandomA(a, n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
}

void GetTimeInputRandomB(double a[], int &n, double &cpu_time_used) {
    clock_t start, end;

    start = clock();

    InputRandomB(a, n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
}

NODE* GetTimeInputRandomC(NODE *root, double &cpu_time_used) {
    clock_t start, end;

    start = clock();

    root = InputRandomC(root);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return root;
}

void Format (int n) {
    while (n--) 
        cout << " ";
}

double GetTimeBinarySearch(double a[], int n, double key) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    BinarySearch (a, n, key);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double GetTimeInterpolationSearch(double a[], int n, double key) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    InterpolationSearch(a, n, key);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double GetTimeLinearSearch(double a[], int n, double key) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    LinearSearch (a, n, key);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double GetTimeBinarySearchTree(NODE *root, double key) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    SearchNode (root, key);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}


int main() {
    NODE *root = NULL;
    int nA, nB, x;

    cout << "Dataset";
    Format(space);

    cout << "Array A";
    Format(space);

    cout << "Array B";
    Format(space);

    cout << "Tree C";
    Format(space);

    cout << "Linear Search";
    Format(space);

    cout << "Binaray Search";
    Format(space);

    cout << "Interpolation Search";
    Format(space);

    cout << "Binary Search Tree";
    // Format(space);

    cout << "\n";

    double runningTime;
    for (int i = 0; i < 15; i++) {
        cout << "Dataset " << i + 1;
        Format(8);

        GetTimeInputRandomA(a, nA, runningTime);
        cout << runningTime << "s";
        Format(10);

        GetTimeInputRandomB(b, nB, runningTime);
        cout << runningTime << "s";
        Format(10);

        root = GetTimeInputRandomC(root, runningTime);
        cout << runningTime << "s";
        Format(10);
        
        srand(time(0));
        double x = rand() + rand() / (double)RAND_MAX;

        cout << GetTimeLinearSearch(a, nA, x) << "s";
        Format(18);

        cout << GetTimeBinarySearch(b, nB, x) << "s";
        Format(25);

        cout << GetTimeInterpolationSearch(b, nB, x) << "s";
        Format(25);

        cout << GetTimeBinarySearchTree(root, x) << "s";
        //Format(20);

        while (root != NULL) 
            root = DeleteNode(root, root->key);

        cout << "\n";
    }
}