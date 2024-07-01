#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int> >adj, vector<int>&visited,int n,int m,int node,int parent,vector<int>&path){
    visited[node]=1;
    path[node]=1;
    for(auto it:adj[node]){
        if(visited[it]==0){
            if(dfs(adj,visited,n,m,it,node,path)==true){
                return true;
            }
        }
        else if(path[it]==1){
            return true;
        }
    }
    path[node]=0;
    return false;
}

bool isCycle(vector<vector<int> >adj,int n,int m){
    vector<int>visited(n+1,0);
    vector<int>path(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(adj,visited,n,m,i,-1,path)==true){
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
    cout<<"Enter the number of directed edges : ";
    cin>>m;

    vector<vector<int> >adj(n+1);
    cout<<"Enter the directed edges : "<<endl;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
    }

    bool ans=isCycle(adj,n,m);
    if(ans){
        cout<<"Yes, there is a cycle present in the given directed graph."<<endl;
    }
    else{
        cout<<"No, there is not any cycle present in the given directed graph."<<endl;
    }

return 0;
}