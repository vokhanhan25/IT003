#include <iostream>

using namespace std;

struct TNode {
    int key;
    struct TNode *pLeft;
    struct TNode *pRight;
};

typedef TNode *TREE;

void CreateTree(TREE &T) {
    T = NULL;
}

TNode *CreateTNode(int x) {
    TNode *p;
    p = new TNode;
    if (p == NULL) 
        exit(1);
    else {
        p->key = x;
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;
}

int InsertTNode (TREE &T, int x) {
    if (T) {
        if (T->key == x) 
            return 0;
        if (T->key > x) 
            return InsertTNode(T->pLeft, x);
        return InsertTNode(T->pRight, x);
    }

    T = new TNode;
    if (T == NULL) 
        return -1;
    T->key = x;
    T->pLeft = T->pRight = NULL;
    return 1;
}

TNode* SearchTNode (TREE T, int x) {
    if (T != NULL) {
        if (T->key == x)
            return T;
        else if (x > T->key)
            return SearchTNode(T->pRight, x);
        else 
            return SearchTNode(T->pLeft, x);
    }
    return NULL;
}


int main() {

}