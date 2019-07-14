#include<bits/stdc++.h>
#define MAXDEGREE    500   /**Maximum vertex outdegree **/
#define MAXV         1000   /**Maximum number of vertices**/
using namespace std;

class Queue{
	public:
		char *data;
		int MAX;
		int font,rear;
		Queue(int x){
			MAX = x;
			data = new char[x];
			font = rear = -1;
		}
		void enqueue(int x){                       ///MAX = 3
			if(font == -1 && rear == -1){          ///rear = 0 ///false                     ///false                ///false
				font = rear = 0;                   ///font = 0
			}
			else if(((rear+1) % MAX) == font){                 /// (0+1) % 3 = 1 ,font = 0  ///(1+1)%3=2            ///(2+1)%3 = 0 true
				cout<<"overflow"<<endl;
				return;
			}
			else{
				rear = (rear + 1) % MAX;         ///rear = 0  /// rear = (0+1)%3 = 1       ///rear = (1+1)%3 = 2    ///false
			}
			data[rear] = x;
		}
		char dequeue(){
			if(font == rear && (font != (-1))){
				int i;
				i = data[font];
				font = rear = -1;
				return i;
			}
			else if((font == (-1))&&(rear ==(-1))){
				cout<<"unerflow"<<endl;
				exit(1);
			}
			else {
				int i;
				i = data[font];
				font = (font + 1)%MAX;
				return i;
			}
		}
		int isempty(){
            if(font==-1 && rear == -1){
                return 1;
            }
            return 0;
		}
};


class grph{
    public:
    
    int totalvertices;              /**number of vertices**/
    int totaledges;                 /**Number of edges**/
    char first[MAXV][2];
    
    
    char vertices[MAXV];
    char edges[MAXV][MAXDEGREE];
    int degree[MAXV+1];

    bool discovered[MAXV];
    char parent[MAXV];
    bool processed[MAXV];


    grph(){
            int i; ///counter
            totalvertices = 0;
            totaledges = 0;
            for(i=0;i<MAXV;i++){
                degree[i]=0;///set all vertices degree to zero
                parent[i]= '&';
                discovered[i] = false;
            }
    }
    
    void init_bfs(){
		int i= 0;
		for(i=0;i<MAXV;i++){
			parent[i]= '&';
            discovered[i] = false;
		}
	}
	void init_dfs(){
		init_bfs();
	}

    int removeDuplicates(char arr[], int n){
        if (n==0 || n==1)
            return n;
        int j = 0;
        for (int i=0; i < n-1; i++)
            if (arr[i] != arr[i+1])
                arr[j++] = arr[i];

        arr[j++] = arr[n-1];

        return j;
    }
    
    void read(bool directed,int m){
        totaledges = m;
        int i;
        for(i=0;i<m;i++){
            string x;
            string y;
            cin>>x>>y;
            char c1,c2;
            c1 = x[0];
            c2 = y[0];
            first[i][0] = c1;
            first[i][1] = c2;
            insert_edge(first[i][0],first[i][1],directed);
        }
        int j;
        int k = 0;
        for(i=0;i<m;i++){
            for(j=0;j<2;j++){
                vertices[k++] = first[i][j];
            }
        }
        sort(vertices,vertices+2*m);
        totalvertices = removeDuplicates(vertices,2*m);
    }
    
    void insert_edge(char x,char y,bool directed){
            if(degree[x] > MAXDEGREE){
                cout<<"warning"<<endl;
            }

            edges[x][degree[x]] = y;
            degree[x]++;
            if(directed == false){
                insert_edge(y,x,true);
            }
            else{
                totaledges++;
            }
    }
    
    void bfs(char x){
        char v;
        int i;
        Queue *q=new Queue( MAXV);
        q->enqueue(x);
        discovered[x] = true;

        while(!q->isempty()){
                v = q->dequeue();
                
                process_vertex(v);
                processed[v] = true;
                
                for(i=0;i<degree[v];i++){
                    if(discovered[edges[v][i]] == false){
                        q->enqueue(edges[v][i]);
                        discovered[edges[v][i]] = true;
                        parent[edges[v][i]] = v;
                    }
                    if(processed[edges[v][i]] == false){
						process_edge(v,edges[v][i]);
					}
                }
        }

    }
    
    void dfs(char v){
		int i;
		int y;
		if(degree[v] == 0){
			return;
		}
		process_vertex(v);
		discovered[v] = true;
		for(i = 0;i<(degree[v]);i++){
			y = edges[v][i];
			if(discovered[y] == false){
				parent[y] = v;
				dfs(y);
			}
			else{
				if(processed[y] == false){
					process_edge(v,y);
				}
			}
			if(degree[edges[v][i+1]]==0){
				return;
			}
		}
		processed[v] = true;
	}
    
    void print(){
        int i,j;
        for(i=0;i<totalvertices;i++){
            cout<<vertices[i]<<" : ";
            for(j=0;j<degree[vertices[i]];j++){
                cout<<edges[vertices[i]][j]<<' ';
            }
            cout<<endl;
        }
    }
    
    void find_path(char start ,char end){
        if((start == end) || (end == '&')){
            cout<<start;
        }
        else{
            find_path(start,parent[end]);
            cout<<end;
        }
    }
   
    void process_vertex(char v){
		//Enter your codes here
		cout<<v<<' ';
	} 
	void process_edge(char x,char y){
		//Enter your codes here
	}

};


int main(){
	while(true){
		 grph g;
		 int egde;
		 cin>>egde;
		 g.read(false,egde);
		 g.print();
		 g.init_bfs();
		 g.dfs('a');
		 int i;
		 cout<<endl;
		 cout<<"Vertices : \t";
		 for(i=0;i<g.totalvertices;i++){
			 cout<<g.vertices[i]<<' ';
		 }
		 cout<<endl;
		 cout<<"Parents  : \t";
		 for(i=0;i<g.totalvertices;i++){
			 cout<<g.parent[g.vertices[i]]<<' ';
		 }
		 cout<<endl;
	}
}


