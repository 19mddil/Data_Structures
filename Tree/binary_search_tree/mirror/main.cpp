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
    void mirror(node *r){
        if(r == NULL){
            return;
        }
        mirror(r->left);
        mirror(r->right);
        swap(r->left,r->right);
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

int main(){
    bst tree;
    tree.Insert(12);
    tree.Insert(15);
    tree.Insert(10);
    tree.Insert(17);
    tree.Insert(16);
    tree.Insert(20);
    tree.Insert(18);
    tree.Insert(11);
    print2DUtil(tree.root,2);
    tree.mirror(tree.root);
    print2DUtil(tree.root,2);

}
