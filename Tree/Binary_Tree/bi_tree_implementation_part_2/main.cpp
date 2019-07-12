#include<iostream>
#define COUNT 10
using namespace std;
class node{
    public:
    char data;
    node *left;
    node *right;
    /**A powerfull and easy constructor**/
    node(char key){
        data = key;
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
void preorder(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<' ';
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
void postorder(node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<' ';
}
int main(){
    binary_tree *tree = new binary_tree();
    tree->root = new node('A');
    tree->root->left = new node('B');
    tree->root->right = new node('C');
    tree->root->left->left = new node('D');
    tree->root->left->right = new node('E');
    tree->root->left->left->left = new node('G');
    tree->root->left->left->right = new node('H');
    tree->root->left->left->right->right = new node('L');
    tree->root->right->right= new node('F');
    tree->root->right->right->left= new node('I');
    tree->root->right->right->right= new node('J');
    tree->root->right->right->right->left= new node('K');
    print2DUtil(tree->root,2);
    preorder(tree->root);
    cout<<endl;
    inorder(tree->root);
    cout<<endl;
    postorder(tree->root);
    cout<<endl;

}
