#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define max 10
int adjmat[max][max];
bool visitedbfs[max];
bool visiteddfs[max];
class graphTraversal{
    private :
        int n,m,u,v;
        

    public:
    void BFS(int start,int n){
        queue <int>q;
        visitedbfs[start] = true;
        q.push(start);

        cout<<"BFS Traversal :\n";

        while(!q.empty()){
            int current = q.front();
            q.pop();// empty hogay queue by removing only one element present in it 
            cout<<current<<" ";// yeh visited print hoga pehle.

            for(int i = 1; i <= n ; i++){
                if(adjmat[current][i]==1 && !visitedbfs[i]){
                    q.push(i);
                    visitedbfs[i] = true;
                }
            }
        }
        cout<<endl;
    }

    // void DFS(int startvertex,int n){
    //     visiteddfs[startvertex] = true;
    //     cout<<startvertex<<" ";

    //     for(int i = 0; i < n ; i++){
    //         if(adjmat[startvertex][i] == 1 && !visiteddfs[i]){
    //             DFS(i,n);
    //         }
    //     }
    //     cout<<endl;
    // }

    void DFS(int startvertex, int n){
        stack <int> s;
        s.push(startvertex);
        visiteddfs[startvertex] = true;

        cout<<"DFS Traversal :\n";
        while(!s.empty()){
            int v = s.top();
            s.pop();
            cout<<v<<" ";
            for(int i = n ; i >= 0 ; i--){
                if(adjmat[v][i] == 1 && !visiteddfs[i]){
                    s.push(i);
                    visiteddfs[i] = true;
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    graphTraversal gt;
    int n, m, startbfs,startdfs,u,v;
    // int adjmat[max][max];
    cout<<"Enter the number of vertices : ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the number of edges : ";
    cin>>m;
    cout<<endl;
    //Initialize the adjacency Matrix.
    for(int i = 1; i <= n;i++){
        for(int j = 1 ; j <= n; j++){
            adjmat[i][j] = 0;
        }
        cout<<endl;
    }
    cout<<"Enter the edges (u,v) :";
    for(int i = 0 ; i < m; i ++){
        cin>>u>>v;
        adjmat[u][v] = 1;
        adjmat[v][u] = 1;

    }
    cout<<"\nAdjacency Matrix is : \t\t";
    for(int i =1 ;i <= n;i++){
        for(int j = 1 ; j <= n; j++){
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the starting vertex for BFS : ";
    cin>>startbfs;
    cout<<endl;
    gt.BFS(startbfs,n);

    cout<<"Enter the startinf vertex for DFS : ";
    cin>>startdfs;
    cout<<endl;
    gt.DFS(startdfs,n);

    return 0;
}
