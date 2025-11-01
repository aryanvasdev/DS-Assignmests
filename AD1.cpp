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
    int sumOfLeftLeaves(tree* root) {
        if (root == NULL) return 0;

        int sum = 0;

        if (root->lptr != NULL) {
            if (root->lptr->lptr == NULL && root->lptr->rptr == NULL)
                sum += root->lptr->data;
            else
                sum += sumOfLeftLeaves(root->lptr);
        }
        sum += sumOfLeftLeaves(root->rptr);

        return sum;
    }
};

int main() {
    // Construct the tree: [3,9,20,null,null,15,7]
    tree* root = new tree(3);
    root->lptr = new tree(9);
    root->rptr = new tree(20);
    root->rptr->lptr = new tree(15);
    root->rptr->rptr = new tree(7);
    cout << root->sumOfLeftLeaves(root) << endl; // Output: 24

    return 0;
}