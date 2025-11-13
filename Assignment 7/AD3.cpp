#include <iostream>
using namespace std;

class tree {
public:
    int data;
    tree* lptr;
    tree* rptr;

    tree(int n) {
        data = n;
        tree* lptr = NULL;
        tree* rptr = NULL;
    }
    int maxDepth(tree* root) {
        if (root == NULL) return 0;

        int lptrDepth = maxDepth(root->lptr);
        int rptrDepth = maxDepth(root->rptr);

        return 1 + max(lptrDepth, rptrDepth);
    }
};

int main() {
    tree* root = new tree(1);

    root->lptr = new tree(2);
    root->rptr = new tree(3);

    root->lptr->lptr = new tree(4);
    root->lptr->rptr = new tree(5);
    root->lptr->rptr->lptr = new tree(7);

    root->rptr->rptr = new tree(6);
    root->rptr->rptr->lptr = new tree(8);
    cout << root->maxDepth(root) << endl; 

    return 0;
}