#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* node = new Node();
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int &postIndex) {
    if (inStart > inEnd)
        return NULL;

    // Pick the current node from postorder
    Node* node = newNode(postorder[postIndex--]);

    // If this node has no children
    if (inStart == inEnd)
        return node;

    // Find the node position in inorder
    int inIndex = findIndex(inorder, inStart, inEnd, node->data);

    // Build right and left subtrees
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};
    int n = 5;

    int postIndex = n - 1;

    Node* root = buildTree(inorder, postorder, 0, n - 1, postIndex);

    cout << "Inorder Traversal of Constructed Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
