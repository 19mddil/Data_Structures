#include<iostream>
#include<vector>
#include<queue>
#define MAXDEGREE    50   /**Maximum vertex outdegree **/
#define MAXV        100   /**Maximum number of vertices**/
using namespace std;
class graph{
    public:
        vector<int>edge[MAXV];      /**adjacency info**/
        vector<int>degree;              /**outdegree of each vertex**/
        //vector<int>weight[MAXV];
        vector<int>level;
        int totalvertices;              /**number of vertices**/
        int totaledges;

        bool processed[MAXV];                 /**Number of edges**/
        bool discovered[MAXV];
        int parent[MAXV];

        graph(){
            int i; ///counter
            totalvertices = 0;
            totaledges = 0;
            for(i=0;i<MAXV;i++){
                degree.push_back(0);///set all vertices degree to zero
                processed[i] = false;
                discovered[i] = false;
                parent[i] = -1;
                //weight[i].push_back(0);
            }
        }

        void insert_edge(int x,int y,bool directed){
            if(degree[x] > MAXDEGREE){
                cout<<"warning"<<endl;
            }
            edge[x].push_back(y);
            degree[x]++;
            if(directed == false){
                insert_edge(y,x,true);
            }
            else{
                totaledges++;
            }
        }

        void read(bool directed){
            int i; ///counter
            int m; ///number of edges
            int x,y; ///vertices in edge(x,y)

            cout<<"Enter The Number of Nodes and Edges in Graph : ";
            cin>>totalvertices>>m;///suppose we have 10 nodes with 5 edges
            cout<<endl;
            for(i = 1;i<=m;i++){
                cout<<"Enter Two edge(no need 1  2 and 2 1)"<<endl;
                cin>>x>>y;///vertices
                cout<<endl;
                insert_edge(x,y,directed);
            }
        }

        void print(){
            int i;
            int j;
            for(i=1;i<=totalvertices;i++){
                cout<<i<<":"<<' ';
                for(j=0;j<degree[i];j++){
                    cout<<edge[i][j]<<' ' ;///i represents nodes
                }
                cout<<endl;
            }
            cout<<endl;
        }

    void bfs(int start){
        queue<int> q; ///queue of vertices to visit
        int v;        ///current node or vertex
        int i =-1;        ///counter
        q.push(start);
        discovered[start] = true;

        while(!q.empty()){
            i = i+1;
            v = q.front();
            q.pop();
            process_vertex(v);
            processed[v] = true;
            cout<<v<<endl;
            for(i=0;i<degree[v];i++){
                if(discovered[edge[v][i]] == false){
                    q.push(edge[v][i]);
                    discovered[edge[v][i]] = true;

                    parent[edge[v][i]] = v;
                }
                if(processed[edge [v][i]] == false){
                    process_edge(v,edge[v][i]);
                }
            }
        }
    }
    void process_vertex(int x){

    }
    void process_edge(int x,int y){

    }
    void find_path(int start ,int end){
        if((start == end) || (end == -1)){
            cout<<endl<<start;
        }
        else{
            find_path(start,parent[end]);
            cout<<' '<<end<<endl;
        }
    }
};
int main(){
    graph g;
    g.read(false);
    g.print();
    g.bfs(1);
    g.find_path(1,5);
}
