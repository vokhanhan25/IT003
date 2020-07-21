// STT: 01
// Họ và tên: Võ Khánh An
// Ghi chú:

#include <iostream>
#include <time.h>
#include <stdlib.h>


using namespace std;

struct NODE { 
    int key; 
    struct NODE *left, *right; 
}; 


  
NODE *CreateNode(int item) { 
    NODE *temp = new NODE; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
  
// NODE* Insert(NODE* root, int key) 
// { 
//     NODE* p = CreateNode(key); 
//     NODE* x = root; 
//     NODE* y = NULL; 
  
//     while (x != NULL) { 
//         y = x; 
//         if (key < x->key) 
//             x = x->left; 
//         else
//             x = x->right; 
//     } 

//     if (y == NULL) 
//         y = p; 
  
//     else if (key < y->key) 
//         y->left = p; 
  
//     else
//         y->right = p; 
  
//     return y; 
// } 

NODE* Insert(NODE* root, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (root == NULL) return CreateNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < root->key) 
        root->left  = Insert(root->left, key); 
    else if (key > root->key) 
        root->right = Insert(root->right, key);    
  
    /* return the (unchanged) node pointer */
    return root; 
} 
  

NODE * MinValueNode(NODE* node) { 
    NODE* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

NODE* DeleteNode(NODE* root, int key) { 
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

void NLR(NODE *root) {
    if (root != NULL) {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(NODE *root) {
    if (root != NULL) {
        LNR(root->left );
        cout << root->key << "\t";
        cout << root << "\t";
       // cout << "pLeft: " << root->left << "\t";
       // cout << "pRight: " << root->right << "\t";
        LNR(root->right);
    }
}


void LRN(NODE *root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}

void NRL(NODE *root) {
    if (root != NULL) {
        cout << root->key << " ";
        NRL(root->right);
        NRL(root->left);
    }
}

void RNL(NODE *root) {
    if (root != NULL) {
        RNL(root->right);
        cout << root->key << " ";
        RNL(root->left);
    }
}

void RLN(NODE *root) {
    if (root != NULL) {
        RLN(root->right);
        RLN(root->left);
        cout << root->key << " ";
    }
}

NODE* CreateTreeAutomatically (NODE *root) {
    srand(time(0));
    int n = 10 + rand() % 11;
    int x;
    bool checkRoot = false;
    while (n--) {
        x = 358 + rand() % 1001;
        if (checkRoot) 
            Insert(root, x);
        else {
            root = Insert(root, x);
            checkRoot = true;
        }
    }
    cout << "Da tao cay xong!\n";
    return root;
}

void Browse(NODE *root, int choose) {
    switch(choose) {
        case 1:
            NLR(root);
            break;
        case 2:
            LNR(root);
            break;
        case 3:
            LRN(root);
            break;
        case 4:
            NRL(root);
            break;
        case 5:
            RNL(root);
            break;
        case 6:
            RLN(root);
            break;
        default:
            cout << "Khong hop le!\n";
    }
    cout << "\n";
}

void DisplayCaseBrowse() {
    cout << "1: NLR\n";
    cout << "2: LNR\n";
    cout << "3: LRN\n";
    cout << "4: NRL\n";
    cout << "5: RNL\n";
    cout << "6: RLN\n";
    cout << "\n";
}

bool SearchNode(NODE* root, int key) { 
    if (root == NULL) 
        return false; 
  
    if (root->key == key) 
        return true; 
  
    bool res1 = SearchNode(root->left, key); 
  
    if(res1) return true; 
  
    bool res2 = SearchNode(root->right, key); 
  
    return res2; 
} 

void CountNode(NODE *root, int &cnt) {
    if (root != NULL) {
        cnt++;
        CountNode(root->left, cnt);
        CountNode(root->right, cnt);
    }
}

void CountLeaf(NODE *root, int &cnt) {
    if (root != NULL) {
        if(root->left == NULL && root->right == NULL) 
            cnt++;
        CountLeaf(root->left, cnt);
        CountLeaf(root->right, cnt);
    }
}

void CountBranch(NODE *root, int &cnt) {
    if (root != NULL) {
        if(root->left != NULL || root->right != NULL) 
            cnt++;
        CountBranch(root->left, cnt);
        CountBranch(root->right, cnt);
    }
}

void CountNodeSmallerX(NODE *root, int key, int &cnt) {
    if (root != NULL) {
        if(root->key < key) 
            cnt++;
        CountNodeSmallerX(root->left, key, cnt);
        CountNodeSmallerX(root->right, key, cnt);
    }
}

void CountNodeGreaterX(NODE *root, int key, int &cnt) {
    if (root != NULL) {
        if(root->key > key) 
            cnt++;
        CountNodeGreaterX(root->left, key, cnt);
        CountNodeGreaterX(root->right, key, cnt);
    }
}

void CountXSmallerNodeGreaterY(NODE *root, int key1, int key2, int &cnt) {
    if (root != NULL) {
        if(key1 < root->key && root->key < key2) 
            cnt++;
        CountXSmallerNodeGreaterY(root->left, key1, key2, cnt);
        CountXSmallerNodeGreaterY(root->right, key1, key2, cnt);
    }
}

void CountNodeEven(NODE *root, int &cnt) {
    if (root != NULL) {
        if(root->key % 2 == 0) 
            cnt++;
        CountNodeEven(root->left, cnt);
        CountNodeEven(root->right, cnt);
    }
}

void CountNodeOdd(NODE *root, int &cnt) {
    if (root != NULL) {
        if(root->key % 2 == 1) 
            cnt++;
        CountNodeOdd(root->left, cnt);
        CountNodeOdd(root->right, cnt);
    }
}

void GetSumNode(NODE *root, int &sum) {
    if (root != NULL) {
        sum += root->key;
        GetSumNode(root->left, sum);
        GetSumNode(root->right, sum);
    }
}

void GetSumEvenNode(NODE *root, int &sum) {
    if (root != NULL) {
        if (root->key % 2 == 0)
            sum += root->key;
        GetSumEvenNode(root->left, sum);
        GetSumEvenNode(root->right, sum);
    }
}

void GetSumOddNode(NODE *root, int &sum) {
    if (root != NULL) {
        if (root->key % 2 == 1)
            sum += root->key;
        GetSumOddNode(root->left, sum);
        GetSumOddNode(root->right, sum);
    }
}

void GetMaxNode(NODE *root, int &maxNode) {
    if (root != NULL) {
        if (root->key > maxNode) 
            maxNode = root->key;
        GetMaxNode(root->left, maxNode);
        GetMaxNode(root->right, maxNode);
    }
}

void GetMinNode(NODE *root, int &minNode) {
    if (root != NULL) {
        if (root->key < minNode) 
            minNode = root->key;
        GetMinNode(root->left, minNode);
        GetMinNode(root->right, minNode);
    }
}

int trace[100];



// bool SearchNode(NODE* root, int key) { 
//     NODE *current, *pre; 
  
//     if (root == NULL) 
//         return false;
  
//     current = root; 
//     while (current != NULL) { 
  
//         if (current->left == NULL) { 
//             if (current->key == key)
//                 return true;
//             current = current->right; 
//         } 
//         else { 
//             pre = current->left; 
//             while (pre->right != NULL && pre->right != current) 
//                 pre = pre->right; 
  
//             if (pre->right == NULL) { 
//                 pre->right = current; 
//                 current = current->left; 
//             } 
  
//             else { 
//                 pre->right = NULL; 
//                 if (current->key == key)
//                     return true;
//                 current = current->right; 
//             } 
//         } 
//     }
//     return false;
// } 

// int CountNode(NODE* root) { 
//     NODE *current, *pre; 
//     int cnt = 0;
//     if (root == NULL) 
//         return 0;
  
//     current = root; 
//     while (current != NULL) { 
  
//         if (current->left == NULL) { 
//             cnt++;
//             current = current->right; 
//         } 
//         else { 
//             pre = current->left; 
//             while (pre->right != NULL && pre->right != current) 
//                 pre = pre->right; 
  
//             if (pre->right == NULL) { 
//                 pre->right = current; 
//                 current = current->left; 
//             } 
  
//             else { 
//                 pre->right = NULL; 
//                 cnt++;
//                 current = current->right; 
//             } 
//         } 
//     }
//     return cnt;
// } 

void DisplayOption() {
    cout << "1: Insert Node\n";
    cout << "2: Create Tree Automatically\n";
    cout << "3: NLR, LNR, LRN, NRL, RNL, RLN\n";
    cout << "4: Search Node\n";
    cout << "5: Delete Node\n";
    cout << "6: Delete All Node\n";
    cout << "7: Count Node\n";
    cout << "8: Count Leaf\n";
    cout << "9: Count Branch\n";
    cout << "10: Count Node < X\n";
    cout << "11: Count Node > X\n";
    cout << "12: Count X < Node < Y\n";
    cout << "13: Compare Count Node < X & Count Node > X\n";
    cout << "14: Compare Count Node Even & Count Node Odd\n";
    cout << "15: Sum Node\n";
    cout << "16: Sum Even Node\n";
    cout << "17: Sum Odd Node\n";
    cout << "18: Compare Sum Even Node & Sum Odd Node\n";
    cout << "19: Get Max Node & Min Node\n";
    cout << "20: Find path form Root to X\n";
    cout << "21: Thoat khoi chuong trinh\n";
    cout << "\n";
}

int main() {
    NODE *root = NULL;
    int choose, x, y, cnt, res1, res2, sum, maxNode, minNode;
    bool checkRoot = false;

    while (true) {
        DisplayOption();
        cin >> choose;
        switch(choose) {
            case 1:
                do {
                    cout << "Nhap gia tri cua Node can chen: ";
                    cin >> x;
                    if (checkRoot)
                        Insert(root, x);
                    else {
                        root = Insert(root, x);
                        checkRoot = true;
                    }
                    cout << "Ban co muon tiep tuc Insert Node?(1/0): ";
                    cin >> x;
                } while (x == 1);
                break;
            case 2:
                root = CreateTreeAutomatically(root);
                break;
            case 3:
                DisplayCaseBrowse();
                cout << "Chon cach duyet:";
                cin >> x;
                Browse(root, x);
                break;
            case 4:
                cout << "Nhap gia tri x can kiem tra: ";
                cin >> x;
                if (SearchNode(root, x))
                    cout << "Gia tri x co trong BST\n";
                else 
                    cout << "Gia tri x KHONG co trong BST\n";
                break;
            case 5:
                cout << "Nhap gia tri x can xoa: ";
                cin >> x;
                root = DeleteNode(root, x);
                break;
            case 6:
                while (root != NULL) 
                    root = DeleteNode(root, root->key);
                cout << "Da xoa tat ca cac node xong!\n";
                break;
            case 7:
                cnt = 0;
                CountNode(root, cnt);
                cout << "So node tren cay = " << cnt << "\n";
                break;
            case 8:
                cnt = 0;
                CountLeaf(root, cnt);
                cout << "So la tren cay = " << cnt << "\n";
                break;
            case 9:
                cnt = 0;
                CountBranch(root, cnt);
                cout << "So nhanh tren cay = " << cnt << "\n";
                break;
            case 10:
                cout << "Nhap gia tri x: ";
                cin >> x;
                cnt = 0;
                CountNodeSmallerX(root, x, cnt);
                cout << "So node < x tren cay: " << cnt << "\n";
                break;
            case 11:
                cout << "Nhap gia tri x: ";
                cin >> x;
                cnt = 0;
                CountNodeGreaterX(root, x, cnt);
                cout << "So node > x tren cay: " << cnt << "\n";
                break;
            case 12:
                cout << "Nhap gia tri x: ";
                cin >> x;
                cout << "Nhap gia tri y: ";
                cin >> y;
                cnt = 0;
                CountXSmallerNodeGreaterY(root, x, y, cnt);
                cout << "So node voi dieu kien y < node < x tren cay: " << cnt << "\n";
                break;
            case 13:
                cout << "Nhap gia tri x: ";
                cin >> x;
                res1 = 0;
                res2 = 0;
                CountNodeGreaterX(root, x, res1);
                CountNodeSmallerX(root, x, res2);
                if (res1 > res2)
                    cout << "So luong Node > x nhieu hon so luong Node < x";
                else if (res1 < res2)  
                    cout << "So luong Node > x it hon so luong Node < x";
                else 
                    cout << "So luong Node > x bang so luong Node < x";
                cout << "\n";
                break;
            case 14:
                res1 = 0;
                res2 = 0;
                CountNodeEven(root, res1);
                CountNodeOdd(root, res2);
                if (res1 > res2)
                    cout << "So luong Node chan lon hon so luong Node le";
                else if (res1 < res2)
                    cout << "So luong Node chan nho hon so luong Node le";
                else 
                    cout << "So luong Node chan bang so luong Node le";
                cout <<"\n";
                break;
            case 15:
                sum = 0;
                GetSumNode(root, sum);
                cout << "Tong cac Node tren cay = " << sum << "\n";
                break;
            case 16:
                sum = 0;
                GetSumEvenNode(root, sum);
                cout << "Tong cac Node chan tren cay = " << sum << "\n";
                break;
            case 17:
                sum = 0;
                GetSumOddNode(root, sum);
                cout << "Tong cac Node le tren cay = " << sum << "\n";
                break;
            case 18:
                res1 = 0;
                res2 = 0;
                GetSumEvenNode(root, res1);
                GetSumOddNode(root, res2);
                if (res1 > res2)
                    cout << "Tong Node chan lon hon tong Node le";
                else if (res1 < res2)
                    cout << "Tong Node chan nho hon tong Node le";
                else 
                    cout << "Tong Node chan bang tong Node le";
                cout <<"\n";
                break;
            case 19:
                maxNode = 0;
                GetMaxNode(root, maxNode);
                minNode = maxNode;
                GetMinNode(root, minNode);
                cout << "Node lon nhat = " << maxNode << "\n";
                cout << "Node nho nhat = " << minNode << "\n";
                break;
            case 20:
                break;
            case 21:
                cout << "EXIT!\n";
                return 0;
                break;
            default:
                cout << "Khong hop le, vui long nhap lai!\n";
        }
    }
}
