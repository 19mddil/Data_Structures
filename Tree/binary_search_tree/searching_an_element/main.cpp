#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#define COUNT 10
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int key){
        left = right = NULL;
        data = key;
    }
};
class bst{
    public:
    node * root;
    vector<int> v;
    bst(){
        root = NULL;
    }
    bst(int key){
        root = new node(key);
    }
    void Insert(int key){
        root = Insert(root,key);
    }
    node *Insert(node *r,int key){
        if(r == NULL){
            r = new node(key);
        }
        else{
            if((r->data)>key){
                r->left = Insert(r->left,key);
            }
            else{
                r->right = Insert(r->right,key);
            }
        }
        return r;
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
    void del(int key){
        node *r;
        if(Search_node(key) == NULL){
            cout<<"No nodes been found"<<endl;
        }
        else{
            r = Search_node(key);
            if(r->left == NULL && r->right == NULL){
                r = NULL;
            }
            else if(r ->left == NULL || r -> right == NULL){
                if(r->left == NULL){
                    r->data = r->right->data;
                    r->right = NULL;
                }
                else{
                    r->data = r->left->data;
                    r->left = NULL;
                }
            }
            else{
                del(r->left,key);
            }

        }
    }
    void del(node *r,int key){

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
    tree.Insert(45);
    tree.Insert(39);
    tree.Insert(56);
    tree.Insert(12);
    tree.Insert(34);
    tree.Insert(78);
    tree.Insert(32);
    tree.Insert(10);
    tree.Insert(89);
    tree.Insert(54);
    tree.Insert(67);
    tree.Insert(81);
    cout<<boolalpha<<tree.Search(67)<<endl;
    //tree.del()
    print2DUtil(tree.root,2);
}
