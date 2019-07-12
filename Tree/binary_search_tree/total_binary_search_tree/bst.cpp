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

/**
 *Insert
 *
 **/

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
    
    int height(node * r){
        if(r==NULL){
            return 0;
        }
        int leftheight = height(r->left);
        int rightheight = height(r->right);
        if(leftheight>rightheight){
            return leftheight+1;
        }
        else{
            return rightheight+1;
        }

    }
    
    void mirror(node *r){
        if(r == NULL){
            return;
        }
        mirror(r->left);
        mirror(r->right);
        swap(r->left,r->right);
    }
    
    bool Search(int value){
        return Search(root,value);
    }
    bool Search(node * r,int value){
        if(r == NULL){///NULL ki data like r->data where r is null makes run time error...
            return false;
        }
        else if(r->data == value){
            return true;
        }
        else{
            if( value < r->data){
                return Search(r->left,value);
            }
            else{
                return Search(r->right,value);
            }
        }
    }
    node *Search_node(int value){
        return Search_node(root,value);
    }
    node *Search_node(node * r,int value){
        if(r == NULL){///NULL ki data like r->data where r is null makes run time error...
            return NULL;
        }
        else if(r->data == value){
            return r;
        }
        else{
            if( value < r->data){
                return Search_node(r->left,value);
            }
            else{
                return Search_node(r->right,value);
            }
        }
    }
    
    int totalnode(node *r){
        if(r == NULL){
            return 0;
        }
        return totalnode(r->left)+totalnode(r->right)+1;
    }
    int totalexternalnode(node *r){
        if(r==NULL){
            return 0;
        }
        if(r->left == NULL && r->right == NULL){
            return 1;
        }
        return totalexternalnode(r->left)+totalexternalnode(r->right);
    }
    int totalinternalnode(node *r){
        if(r == NULL){
            return 0;
        }
        if(r->left == NULL && r->right == NULL){
            return 0;
        }
        return totalinternalnode(r->left)+totalinternalnode(r->right)+1;
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

