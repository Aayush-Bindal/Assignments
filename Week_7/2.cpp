#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

Node* findMax(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

Node* findMin(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    if (target == nullptr) return nullptr;

    if (target->right != nullptr)
        return findMin(target->right);

    Node* successor = nullptr;
    Node* ancestor = root;
    while (ancestor != nullptr) {
        if (target->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else if (target->data > ancestor->data)
            ancestor = ancestor->right;
        else
            break;
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* target) {
    if (target == nullptr) return nullptr;

    if (target->left != nullptr)
        return findMax(target->left);

    Node* predecessor = nullptr;
    Node* ancestor = root;
    while (ancestor != nullptr) {
        if (target->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else if (target->data < ancestor->data)
            ancestor = ancestor->left;
        else
            break;
    }
    return predecessor;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int arr[] = {20, 10, 5, 15, 30, 25, 35};
    for (int x : arr)
        root = insert(root, x);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int key = 15;
    cout << "\n(a) Search (Recursive): ";
    if (searchRecursive(root, key))
        cout << "Found";
    else
        cout << "Not Found";

    cout << "\n(a) Search (Iterative): ";
    if (searchIterative(root, key))
        cout << "Found";
    else
        cout << "Not Found";

    Node* maxNode = findMax(root);
    cout << "\n\n(b) Maximum element: " << (maxNode ? maxNode->data : -1);

    Node* minNode = findMin(root);
    cout << "\n(c) Minimum element: " << (minNode ? minNode->data : -1);

    Node* node = searchRecursive(root, 25);
    Node* succ = inorderSuccessor(root, node);
    cout << "\n\n(d) Inorder Successor of 25: ";
    if (succ)
        cout << succ->data;
    else
        cout << "Does not exist";

    Node* pred = inorderPredecessor(root, node);
    cout << "\n(e) Inorder Predecessor of 25: ";
    if (pred)
        cout << pred->data;
    else
        cout << "Does not exist";

    cout << endl;
    return 0;
}