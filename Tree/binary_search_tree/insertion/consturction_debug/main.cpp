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
	node * root;
    node * temp;
    node * last;
	bst(){
		root =  NULL;
	}
	bst(int key){
		root = new node(key);
	}
	void Insert(node *r,int value){/// stack pop kills 39
		temp = r;///saving root
		if(temp == NULL){
            if(root == NULL){
                root = new node(value);
                root->data = value;
                return;
            }
            temp = new node(value);
            temp->data = value;
            temp->left = NULL;
            temp->right = NULL;
            return;
		}
		else{
			if(value > temp->data){
				Insert(temp->right,value);
				return;
			}
			else{
				Insert(temp->left,value);
				return;
			}
		}
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
    bst *tree = new bst();
	int nodes;
	cout<<"how many nodes?"<<endl;
	cin>>nodes;
	int value;
	int i;
	for(i=0;i<nodes;i++){
		cin>>value;
		tree->Insert(tree->root,value);
	}
	print2DUtil(tree->root,2);
	return 0;
}
