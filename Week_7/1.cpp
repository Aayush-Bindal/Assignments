
#include<iostream>
using namespace std;
class node{
    public:
    char data;
    node* left;
    node* right;
    node(char data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
class binaryTree{
    public:
    node* root;
    binaryTree(){
        root=NULL;
    }
    //preorder traversal root->left->right
    void preorder(node* node){
        if(node==NULL){
            return;
        }
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);

    }
    //postorder.  left->right->root
    void postorder(node* node){
        if(node==NULL){
            return ;
        }
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }
    //inorder left -> root -> right;
    void inorder(node* node){
        if(node==NULL){
            return ;
        }
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
};
int main(){
    binaryTree tree;
    tree.root = new node('A');
    tree.root->left = new node('B');
    tree.root->right = new node('C');
    tree.root->left->left = new node('D');
    tree.root->left->right = new node('E');
    tree.root->right->left = new node('F');
    tree.root->right->right = new node('G');
    tree.root->left->right->left = new node('H');
    tree.root->left->right->right = new node('I');

    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << "\nInorder Traversal: ";
    tree.inorder(tree.root);
    cout << "\nPostorder Traversal: ";
    tree.postorder(tree.root);

    return 0;
}