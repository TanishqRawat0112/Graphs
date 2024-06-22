#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int> >&adj,vector<int>&visited,int node,int parent){
    visited[node]=1;
    for(auto it:adj[node]){
        if(visited[it]==0){
            if(dfs(adj,visited,it,node)==true){
                return true;
            }
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}

bool findCycle(vector<vector<int> >&adj,int n,int m){
    vector<int>visited(n+1,0);
    return dfs(adj,visited,1,-1);
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

    if(findCycle(adj,n,m)){
        cout<<"Yes , there is cycle present in the graph."<<endl;
    }
    else{
        cout<<"No, There is no cycle present in the graph."<<endl;
    }


return 0;
}