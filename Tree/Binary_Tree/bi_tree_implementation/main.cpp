#include<iostream>
#define COUNT 10
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int x){
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
    binary_tree(int key){
        root = new node(key);
    }
};
void print2DUtil(node *root, int space){
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
    print2DUtil(root->left, space);
}
void print2D(node *root){
    print2DUtil(root, 0);
}
void pre_order(node * r){
    if(r == NULL){
        return;
    }
    cout<<r->data<<' ';
    pre_order(r->left);
    pre_order(r->right);
}
int main(){
    binary_tree *tree1 = new binary_tree();
    tree1->root = new node(1);
    tree1->root->left = new node(2);
    tree1->root->right = new node(3);
    tree1->root->left->left = new node(4);
    tree1->root->left->right = new node(5);
    tree1->root->left->left->left = new node(8);
    tree1->root->left->left->right = new node(9);

    tree1->root->right->left = new node(6);
    tree1->root->right->right = new node(7);
    tree1->root->right->left->left = new node(10);
    tree1->root->right->left->right = new node(11);
    tree1->root->right->right->right = new node(12);
    //print2DUtil(tree1->root,2);
    pre_order(tree1->root);
}
