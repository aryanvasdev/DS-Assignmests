#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int find(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val)
            return i;
    return -1;
}

Node* buildTree(int inorder[], int preorder[], int start, int end, int &preIndex) {
    if (start > end) return NULL;

    int curr = preorder[preIndex++];       
    Node* root = new Node(curr);

    if (start == end) return root;         

    int pos = find(inorder, start, end, curr);  

    root->left = buildTree(inorder, preorder, start, pos - 1, preIndex);
    root->right = buildTree(inorder, preorder, pos + 1, end, preIndex);

    return root;
}
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};
    int n = 5, preIndex = 0;

    Node* root = buildTree(inorder, preorder, 0, n - 1, preIndex);

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
