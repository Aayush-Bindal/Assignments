#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int v) {
    Node* t = new Node;
    t->data = v;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* root, int v) {
    if (!root) return newNode(v);
    if (v < root->data) root->left = insert(root->left, v);
    else if (v > root->data) root->right = insert(root->right, v);
    return root;
}

Node* findMin(Node* r) {
    while (r && r->left) r = r->left;
    return r;
}

Node* deleteNode(Node* r, int key) {
    if (!r) return r;
    if (key < r->data) r->left = deleteNode(r->left, key);
    else if (key > r->data) r->right = deleteNode(r->right, key);
    else {
        if (!r->left) { Node* t = r->right; delete r; return t; }
        else if (!r->right) { Node* t = r->left; delete r; return t; }
        Node* t = findMin(r->right);
        r->data = t->data;
        r->right = deleteNode(r->right, t->data);
    }
    return r;
}

int maxDepth(Node* r) {
    if (!r) return 0;
    int l = maxDepth(r->left), rt = maxDepth(r->right);
    return (l > rt ? l : rt) + 1;
}

int minDepth(Node* r) {
    if (!r) return 0;
    if (!r->left) return 1 + minDepth(r->right);
    if (!r->right) return 1 + minDepth(r->left);
    int l = minDepth(r->left), rt = minDepth(r->right);
    return (l < rt ? l : rt) + 1;
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {20, 10, 30, 25, 5, 35};
    for (int i = 0; i < 6; i++) root = insert(root, arr[i]);

    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    root = deleteNode(root, 25);
    cout << "After deleting " << "25 :"; 
    inorder(root);
    cout << endl;

    return 0;
}