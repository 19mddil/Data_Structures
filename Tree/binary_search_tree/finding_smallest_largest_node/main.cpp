#include<iostream>
#define COUNT 10
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int key){
        data = key;
        left = right = NULL;
    }
};
class bst{
    public:
    node *root;
    bst(){
        root = NULL;
    }
    void Insert(int key){
        root = Insert(root,key);///we are saving the root
    }
    node* Insert(node *r,int key){
        if(r == NULL){
            r = new node(key);
            //return r;/// root gets popped off but after assigning
        }
        else if(key > r->data){
            r->right = Insert(r->right,key);
        }
        else{
            r->left = Insert(r->left,key);
        }
        return r;///we are creating a linked list;
    }


    node* smallest(node *r){
        if(r == NULL || r->left == NULL){
            return r;
        }
        else{
            return smallest(r->left);
        }
    }
    node* largest(node *r){
        if(r == NULL || r->right == NULL){
            return r;
        }
        else{
            return largest(r->right);
        }
    }
    void delete_tree(){
        root = delete_tree(root);
    }
    node* delete_tree(node *r){
        if(r == NULL){
            return r;
        }
        delete_tree(r->left);
        delete_tree(r->right);
        delete r;
        return NULL;
    }
};

void print2DUtil(node *root, int space){
    if (root == NULL){
        //cout<<"its empty"<<endl;
        return;
    }
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

int main(){
    bst tree;/*its like javas bst tree = new bst(); or c++ equie bst *tree = new bst() but now tree-> but this tree. like java*/
    tree.Insert(45);
    tree.Insert(39);
    tree.Insert(78);
    tree.Insert(54);
    tree.Insert(79);
    tree.Insert(55);
    tree.Insert(80);
    tree.Insert(35);
    tree.Insert(36);
    tree.Insert(34);
    print2DUtil(tree.root,2);
    node * r = tree.smallest(tree.root);
    cout<<r->data<<endl;
    r = tree.largest(tree.root);
    cout<<r->data<<endl;
    tree.delete_tree();
    print2DUtil(tree.root,2);

}



