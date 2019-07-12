/*
    if a node has both child not null, then we got to right subtree, find the smallest node of that
    subtree and make the parent of this subtree to valued that minimum value.
    Now, in the subtree the smallest node wont have a left subtree ever and it may or may not have a
    right subtree which is good.
*/
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

    void Delete(int key){
        root = Delete(root,key);
    }
    node* Delete(node *r,int key){
        if(r == NULL){
            return r;
        }
        if(key > r->data){
            r->right = Delete(r->right,key);
        }
        else if(key < r->data){
            r->left = Delete(r->left,key);
        }
        else{
            if(r->left == NULL){
                return r->right;
            }
            if(r->right == NULL){
                return r->left;
            }
            r->data = minv(r->right);
            r->right = Delete(r->right,r->data);
        }
        return r;
    }
    int minv(node *r){
        int mini = r->data;
        while(r->left != NULL){
            mini = r->left->data;
            r = r->left;
        }
        return mini;
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
    tree.Insert(13);
    print2DUtil(tree.root,2);
    tree.Delete(15);
    print2DUtil (tree.root,2);

}

