#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

struct NODE {
    double key;
    struct NODE *left, *right;
};

NODE *CreateNode(double item) {
    NODE *temp = new NODE;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

NODE* Insert (NODE *root, double key) {
    NODE *p = CreateNode(key);
    NODE *x = root;
    NODE *y = NULL;

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

NODE* CreateTreeAuto(NODE *root) {
    srand(time(0));
    int n = 26 + rand() % 13;
    double x;
    bool checkRoot = false;
    while (n--) {
        x = 577 + rand() % 412 + rand() / (double)RAND_MAX;
        if (checkRoot)
            Insert(root, x);
        else {
            root = Insert(root, x);
            checkRoot = true;
        }
    }
    cout << "Da tao cay xong \n";
    return root;
}

NODE* CreateTreeArr(NODE *root) {
    srand(time(0));
    int n = 26 + rand() % 13;
    double a[50];
    bool checkRoot = false;
    for (int i = 0; i < n; i++)
        a[i] = 577 + rand() % 412 + rand() / (double)RAND_MAX;
    for (int i = 0; i < n; i++) {
        if (checkRoot)
            Insert(root, a[i]);
        else {
            root = Insert(root, a[i]);
            checkRoot = true;
        }
    }
    cout << "Da tao cay xong\n";
    return root;
}

void NLR(NODE *root) {
    if (root != NULL) {
        cout << root->key << "\t";
        cout << root << "\t";
        cout << root->left << "\t";
        cout << root->right << "\n";
        NLR(root->left);
        NLR(root->right);
    }
}

void LRN(NODE *root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << "\t";
        cout << root << "\t";
        cout << root->left << "\t";
        cout << root->right << "\n";
    }
}

bool SearchNode (NODE *root, double key) {
    if (root->key == NULL)
        return false;
    if (root->key == key)
        return true;
    bool res1 = SearchNode(root->left, key);
    if (res1) return true;
    bool res2 = SearchNode(root->right, key);
    return res2;
}

void CountNodeNotLeaf(NODE *root, int &cnt) {
    if (root != NULL) {
        if (root->left != NULL || root->right != NULL)
            cnt++;
        CountNodeNotLeaf(root->left, cnt);
        CountNodeNotLeaf(root->right, cnt);
    }
}

void CountNodeOdd(NODE *root, int &cnt) {
    if (root != NULL) {
        if (int(root->key) % 2 == 1)
            cnt++;
        CountNodeOdd(root->left, cnt);
        CountNodeOdd(root->right, cnt);
    }
}

void CountNodeEven(NODE *root, int &cnt) {
    if (root != NULL) {
        if (int(root->key) % 2 == 0)
            cnt++;
        CountNodeEven(root->left, cnt);
        CountNodeEven(root->right, cnt);
    }
}

bool CompareCountNode(NODE*root) {
    int cnt1 = 0;
    int cnt2 = 0;
    CountNodeEven(root, cnt1);
    CountNodeOdd(root, cnt2);
    if (cnt1 < cnt2)
        return false;
    if (cnt1 == cnt2)
        return 1;
    if (cnt1 > cnt2)
        return true;
}



void GetMinMax(NODE *root, double &minNode, double &maxNode) {
    if (root != NULL) {
       // minNode = min(minNode, root->key);
      //  maxNode = max(maxNode, root->key);
        GetMinMax(root->left, minNode, maxNode);
        GetMinMax(root->right, minNode, maxNode);
    }
}

void DisplayOption() {
    cout << "1: Insert Node\n";
    cout << "2: Create Tree Auto by Random Number\n";
    cout << "3: Create Tree Auto by Array\n";
    cout << "4: NLR, LRN\n";
    cout << "5: Search Node\n";
    cout << "6: Count Node without is Leaf Node\n";
    cout << "7: \n";
    cout << "8: Count Node Odd & Even\n";
    cout << "9: Get Node Max & Min\n";
    cout << "10: EXIT\n";
    cout << "\n";
}

int main()
{
    NODE *root = NULL;
    int option, y;
    double x;
    bool checkRoot = false;
    while(true) {
        DisplayOption();
        cout << "Nhap lua chon: ";
        cin >> option;

        switch(option) {
            case 1:
                do {
                    cout << "Nhap gia tri cua Node can chen: ";
                    cin >> x;
                    if (checkRoot) {
                        if (!SearchNode(root, x))
                            Insert(root, x);
                    }
                    else {
                            root = Insert(root, x);
                            checkRoot = true;
                    }
                    cout << "\n1: Tiep tuc\n";
                    cout << "0: Dung \n";
                    cout << "Ban co muon tuc Insert?(1/0): ";
                    cin >> x;
                } while(x == 1);
                break;
            case 2:
                root = CreateTreeAuto(root);
                break;
            case 3:
                root = CreateTreeArr(root);
                break;
            case 4:
                cout << "1: NLR\n";
                cout << "2: LRN\n";
                cout << "Nhap lua chon cua ban: ";
                cin >> y;
                switch(y) {
                    case 1:
                        cout << "Value   Node   Node Left   Node Right\n";
                        NLR(root);
                        break;
                    case 2:
                        cout << "Value   Node   Node Left   Node Right\n";
                        LRN(root);
                        break;
                }
                break;
            case 5:
                cout << "Nhap gia tri Node can tim kiem: ";
                cin >> x;
                if (SearchNode(root, x))
                    cout << "Gia tri can tim co trong BST\n";
                else
                    cout << "Gia tri can tim KHONG co torng BST\n";
                break;
            case 6:
                y = 0;
                CountNodeNotLeaf(root, y);
                cout << "So Node khong la Node la trong cay: " << y << "\n";
                break;
            case 7:
                break;
            case 8:
                if (CompareCountNode(root))
                    cout << "So luong Node chan >= Node le\n";
                else
                    cout << "So luong Node chan < Node le\n";
                break;
            case 9:
                double minNode, maxNode;
                minNode = maxNode = root->key;
                GetMinMax(root, minNode, maxNode);
                cout << "Node co gia tri lon nhat: " << maxNode << "\n";
                cout << "Node co gia tri nho nhat: " << minNode << "\n";
                break;
            case 10:
                cout << "EXIT!\n";
                return 0;
            default:
                cout << "Khong hop le, vui long nhap lai!\n";
        }
    }
}
