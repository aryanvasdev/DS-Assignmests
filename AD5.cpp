#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int searchInorder(int inorder[], int inStart, int inEnd, int value) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    int inIndex = searchInorder(inorder, inStart, inEnd, rootVal);

    root->left  = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

Node* constructBinaryTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return buildTree(preorder, inorder, 0, n - 1, preIndex);
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[]  = {9, 3, 15, 20, 7};
    int n = 5;

    Node* root = constructBinaryTree(preorder, inorder, n);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
}

