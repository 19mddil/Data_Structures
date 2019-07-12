#include<iostream>
#define COUNT 10
using namespace std;
class node{
    public:
    char data;
    node* left;
    node* right;
    node(char x){
        data = x;
        left = right = NULL;
    }
};
class binary_tree{
    public:
    node *root;
    binary_tree(){
        root = NULL;
    }
    binary_tree(char key){
        root = new node(key);
    }
};
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
void pre_order(node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<' ';
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(node * root){
    if(root == NULL){
        return;
    }
    in_order(root->left);
    cout<<root->data<<' ';
    in_order(root->right);
}

int main(){
    binary_tree *tree = new binary_tree();
    tree->root = new node('%');
    tree->root->left = new node('-');
    tree->root->right = new node('/');
    tree->root->left->left = new node('+');
    tree->root->left->right = new node('*');
    tree->root->left->left->left = new node('a');
    tree->root->left->left->right = new node('b');
    tree->root->left->right->left = new node('c');
    tree->root->left->right->right = new node('d');
    tree->root->right->left = new node('^');
    tree->root->right->right = new node('-');
    tree->root->right->left->left = new node('f');
    tree->root->right->left->right = new node('g');
    tree->root->right->right->left = new node('h');
    tree->root->right->right->right = new node('i');
    print2DUtil(tree->root,1);
    pre_order(tree->root);
    cout<<endl;
    in_order(tree->root);
}
