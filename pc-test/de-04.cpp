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
        y = p;
    else if (key < y->key)
        y->left = p;
    else 
        y->right = p;
    return y;
}

void NLR(NODE *root) {
    if (root != NULL) {
        cout << root->key << "\t\t";
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
        LRN(root->right);
        cout << root->key << "\t\t";
        cout << root << "\t";
        cout << root->left << "\t";
        cout << root->right << "\t";
        cout << "\n";
    }
}

void CountBranchNode(NODE *root, int &cnt, double key) {
    if (root != NULL) {
        CountBranchNode(root->left, cnt, key);
        if ((root->right != NULL || root->left != NULL) && (root->key != key)) 
            cnt++;
        CountBranchNode(root->right, cnt, key);
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

void CountWithoutLeafNode(NODE *root, int &cnt) {
    if (root != NULL) {
        if (root->left != NULL || root->right != NULL)
            cnt++;
        CountWithoutLeafNode(root->left, cnt);
        CountWithoutLeafNode(root->right, cnt);
    }
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

void CountNodeOddEven(NODE *root, int &cntEven, int &cntOdd) {
    if (root != NULL) {
        if (int(root->key) % 2 == 0)
            cntEven++;
        else
            cntOdd++;
        CountNodeOddEven(root->left, cntEven, cntOdd);
        CountNodeOddEven(root->right, cntEven, cntOdd);
    }
}

bool CompareNodeOddEven(NODE *root) {
    int cntEven = 0, cntOdd = 0;
    CountNodeOddEven(root, cntEven, cntOdd);
    if (cntEven < cntOdd)
        return false;
    if (cntEven = cntOdd)
        return 1;
    if (cntEven > cntOdd)   
        return true;
}

double max(double a, double b) {
    if (a > b) 
        return a;
    return b;
}

double min(double a, double b) {
    if (a < b)
        return a;
    return b;
}

void FindNodeMaxMin(NODE *root, double &maxNode, double &minNode) {
    if (root != NULL) {
        maxNode = max(maxNode, root->key);
        minNode = min(minNode, root->key);
        FindNodeMaxMin(root->left, maxNode, minNode);
        FindNodeMaxMin(root->right, maxNode, minNode);
    }
}

void DisplayOption() {
    cout << "1: Insert Node\n";
    cout << "2: Create Tree Auto\n";
    cout << "3: Create Tree By Array\n";
    cout << "4: NLR, LRN\n";
    cout << "5: Search Node\n";
    cout << "6: Count Without Leaf Node\n";
    cout << "7: Count Branch Node\n";
    cout << "8: Compare Node Odd & Even\n";
    cout << "9: Find Max Min Node\n";
    cout << "10: Thoat khoi chuong trinh\n";
    cout << "\n";
}

int main() {
    NODE *root = NULL;
    int option, value, n = 11, cnt;
    double key, maxNode, minNode;
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
                cout << "Gia tri Node\tDia chi Node\tDia chi Left\tDia chi Right\n";
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
            case 6:
                cnt = 0;
                CountWithoutLeafNode(root, cnt);
                cout << "So node khong la Node la trong cay = " << cnt << "\n";
                break;
            case 7:
                cout << "Nhap gia tri cua Node: ";
                cin >> key;
                cnt = 0;
                CountBranchNode(root, cnt, key);
                cout << "So Node la node nhanh, ngoai tru Node duoc nhap = " << cnt << "\n";
                break;
            case 8:
                if (CompareNodeOddEven(root))
                    cout << "So Node chan >= So node le\n";
                else
                    cout << "So Node chan < So Node le\n";
                break;
            case 9:
                maxNode = root->key;
                minNode = root->key;
                FindNodeMaxMin(root, maxNode, minNode);
                cout << "Max Node = " << maxNode << "\n";
                cout << "Min Node = " << minNode << "\n";
                break;
            case 10:
                cout << "EXIT!\n";
                return 0;
            default:
                cout << "Khong hop le, vui long nhap lai!\n";
        }
    }
}