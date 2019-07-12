#include<iostream>
#include<vector>
#define MAXDEGREE    50   /**Maximum vertex outdegree **/
#define MAXV        100   /**Maximum number of vertices**/
using namespace std;
class graph{
    public:
        vector<int>neibours[MAXV];      /**adjacency info**/
        vector<int>degree;              /**outdegree of each vertex**/
        //vector<int>weight[MAXV];
        int totalvertices;              /**number of vertices**/
        int totaledges;                 /**Number of edges**/

        graph(){
            int i; ///counter
            totalvertices = 0;
            totaledges = 0;
            for(i=0;i<MAXV;i++){
                degree.push_back(0);///set all vertices degree to zero
                //weight[i].push_back(0);
            }
        }

        void insert_edge(int x,int y,bool directed){
            if(degree[x] > MAXDEGREE){
                cout<<"warning"<<endl;
            }
            neibours[x].push_back(y);
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
                cout<<"Enter Two neibours(no need 1  2 and 2 1)"<<endl;
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
                    cout<<neibours[i][j]<<' ' ;///i represents nodes
                }
                cout<<endl;
            }
            cout<<endl;
        }

};
int main(){
    int x;
    bool t = false;
    cout<<"is the graph directed?"<<endl;
    cin>>x;
    if(x == 1){
        t = true;
    }
    graph g;
    g.read(t);
    g.print();
    cout<<g.degree[2]<<endl;
}
