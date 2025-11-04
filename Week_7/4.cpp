#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isBST(Node* root) {
    if (root == nullptr) return true;

    if (root->left && root->left->data >= root->data) return false;
    if (root->right && root->right->data <= root->data) return false;

    return isBST(root->left) && isBST(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(55);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    if (isBST(root))
        cout << "It isa  bst";
    else
        cout << "not a BST";
}