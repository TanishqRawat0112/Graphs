#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> >floyd_warshall(vector<vector<int> >&adj,int n){
    vector<vector<int> >cost=adj;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(j==k)continue;
                int inp=cost[j][i] + cost[i][k];
                if(inp<adj[j][k]){
                    cost[j][k]=inp;
                }
            }
        }
    }
    return cost;
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<vector<int> >adj(n,vector<int>(n,1e9));
    cout<<"Enter the Edges : "<<endl;
    for(int i=0;i<m;i++){
        int first,second,wt;
        cin>>first>>second>>wt;
        adj[first][second]=wt;
    }
    for(int i=0;i<n;i++){
        adj[i][i]=0;
    }

    vector<vector<int> >floydMat=floyd_warshall(adj,n);

    cout<<"The Multi-Source Shortest Path Adjacent Matrix will be : "<<endl;
    int counter=0;
    for(auto it:floydMat){
        cout<<counter<<" : ";
        for(auto i:it){
            if(i==1e9){
                cout<<"INF ";
                continue;
            }
            cout<<i<<" ";
        }
        counter++;
        cout<<endl;
    }

return 0;
}