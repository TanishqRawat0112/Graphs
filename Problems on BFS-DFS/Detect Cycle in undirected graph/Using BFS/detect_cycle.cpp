#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfs(vector<vector<int> >adj,int n,int m){
    vector<int>visited(n+1,0);
    unordered_map<int,int>mpp;
    queue<int>q;
    q.push(1);
    visited[1]=1;
    mpp[1]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        mpp[node]=0;
        for(auto it:adj[node]){
                if(mpp.find(it)==mpp.end() || mpp[it]==0){
                    if(visited[it]==0){
                    visited[it]=1;
                    mpp[it]=1;
                    q.push(it);
                    }
                }
                else if(mpp[it]==1){
                    return true;
                }
        }
    }
    return false;

}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<vector<int> >adj(n+1);
    cout<<"Enter the edges : "<<endl;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    if(bfs(adj,n,m)){
        cout<<"Yes, There is a cycle in the graph.";
    }
    else{
        cout<<"No, There is not any cycle present in the graph.";
    }

return 0;
}