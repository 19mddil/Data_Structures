#include<iostream>
using namespace std;
class ad_list{
	public:
	int data=-1;
	ad_list * next;
	ad_list * last;
	void create_list(ad_list *adj[],int nodes){
		int i,j,n,value;
		for(i=0;i<=nodes;i++){
			adj[i] = NULL;
		}
		for(i=1;i<=nodes;i++){cout<<"Enter the number of adjacent nodes(neibours) for node "<<i<<" :";
			cin>>n;
			cout<<endl;
			last = NULL;
			for(j=1;j<=n;j++){
				cout<<"Enter the neibour "<<j<<"for node "<<i<<" :";
				cin>>value;
				ad_list * newnode = new ad_list;
				newnode->data = value;
				newnode->next = NULL;
				if(adj[i] == NULL){
					adj[i] = newnode;
				}
				else{
					last->next = newnode;
				}
				last = newnode;
		}
	}
}
void display(ad_list *adj[],int nodes){
    int i;
    ad_list *ptr;
    for(i=0;i<nodes;i++){
        ptr = adj[i];
        cout<<"node "<<i+1<<"has adjacent nodes which are: ";
        while(ptr != NULL){
            cout<<ptr->data<<' ';
            ptr = ptr->next;
        }
        cout<<endl;
    }
}
};

int main(){
	int nodes;
	cout<<"Enter the number of nodes: ";
	ad_list *adj = new ad_list[nodes];
	cin>>nodes;
	ad_list *xxx = new ad_list;
	xxx->create_list(&adj,nodes);
    xxx->display(&adj,nodes);
}
