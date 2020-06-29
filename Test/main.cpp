#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct NODE {
    double key;
    struct NODE *left, *right;
};

NODE *CreateNode(double key) {
    NODE *temp = new NODE;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

NODE *InsertNode(NODE *root, double key) {
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
        x = p;
    else if (key < y->key)
        y->left = p;
    else
        y->right = p;
    return y;
}

void NLR(NODE *root) {
    if (root != NULL) {
        cout << root->key << "\t";
        cout << root << "\t";
        cout << root->left << "\t";
        cout << root->right << "\t";
        cout << "\n";
        NLR(root->left);
        NLR(root->right);
    }
}

void LRN(NODE *root) {
    if (root != NULL) {
        LRN(root->left);
        cout << root->key << "\t";
        cout << root << "\t";
        cout << root->left << "\t";
        cout << root->right << "\t";
        cout << "\n";
        LRN(root->right);
    }
}

bool checkRoot = false;

bool SearchNode(NODE *root, double key) {
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;
    bool res1 = SearchNode(root->left, key);
    if (res1) return true;
    bool res2 = SearchNode(root->right, key);
    return res2;
}

NODE* CreateTreeAuto(NODE *root) {
    srand(time(0));
    int n = 26 + rand() % 13;
    double key;
    while (n--) {
        key = 577 + rand() % (988 - 577) + rand() / (double)RAND_MAX;
        if (checkRoot) {
            if (!SearchNode(root, key)) {
                InsertNode(root, key);
            }
        }
        else {
            root = InsertNode(root, key);
            checkRoot = true;
        }
    }
    cout << "Da tao tu dong xong\n";
    return root;
}

NODE* CreateTreeByArray(NODE *root, double a[], int n) {
    for (int i = 0; i < n; i++) {
        if (checkRoot) {
            if (!SearchNode(root, a[i])) {
                InsertNode(root, a[i]);
            }
        }
        else {
            root = InsertNode(root, a[i]);
            checkRoot = true;
        }
    }
    cout << "Da tao cay bang Array xong\n";
    return root;
}

void DisplayOption() {
    cout << "1: Insert Node\n";
    cout << "2: Create Tree Auto\n";
    cout << "3: Create Tree By Array\n";
    cout << "4: NLR, LRN\n";
    cout << "5: Search Node\n";
    cout << "6: \n";
    cout << "7: \n";
    cout << "8: \n";
    cout << "9: \n";
    cout << "10: Thoat khoi chuong trinh\n";
    cout << "\n";
}

int main() {
    NODE *root = NULL;
    int option, value, n = 11;
    double key;
    double a[20] = {50, 75, 25, 50, 10, 90, 25, 75, 30, 70, 10};
    while (true) {
        DisplayOption();
        cout << "Nhap lua chon cua ban: ";
        cin >> option;
        switch (option) {
            case 1:
                do {
                    cout << "Nhap gia tri Node can chen: ";
                    cin >> key;

                    if (checkRoot) {
                        if (!SearchNode(root, key)) {
                            InsertNode(root, key);
                        }
                    }
                    else {
                        root = InsertNode(root, key);
                        checkRoot = true;
                    }

                    cout << "Ban co muon tiep tuc Insert khong?\n";
                    cout << "1: Tiep tuc\n";
                    cout << "0: Dung\n";
                    cin >> value;
                } while (value == 1);
                break;
            case 2:
                root = CreateTreeAuto(root);
                break;
            case 3:
                root = CreateTreeByArray(root, a, n);
                break;
            case 4:
                cout << "1: NLR\n";
                cout << "2: LRN\n";
                cout << "Nhap lua chon cua ban: ";
                cin >> value;
                cout << "Dia chi Node\tGia tri Node\tDia chi Left\tDia chi Right\n";
                switch (value) {
                    case 1:
                        NLR(root);
                        break;
                    case 2:
                        LRN(root);
                        break;
                }
                break;
            case 5:
                cout << "Nhap gia tri node can tim: ";
                cin >> key;
                if (SearchNode(root, key))
                    cout << "Gia tri can tim co trong BST \n";
                else
                    cout << "Gia tri can tim KHONG CO trong BST\n";
                break;
            case 10:
                cout << "EXIT!\n";
                return 0;
            default:
                cout << "Khong hop le, vui long nhap lai!\n";
        }
    }
}
