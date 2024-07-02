#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int> >&adj,int n,int m,vector<int>&ans,vector<int>&visited,vector<int>&path,int node){
    visited[node]=1;
    path[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(dfs(adj,n,m,ans,visited,path,it)==true){
                return true;
            }
        }
        else if(path[it]==1){
            return true;
        }
    }
    path[node]=0;
    ans.push_back(node);
    return false;
}

void safe_nodes(vector<vector<int> >&adj,int n,int m,vector<int>&ans){
    vector<int>path(n,0);
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,n,m,ans,visited,path,i);
        }
    }
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of directed edges : ";
    cin>>m;

    vector<vector<int> >adj(n);
    cout<<"Enter the directed edges : "<<endl;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
    }

    vector<int>ans;
    safe_nodes(adj,n,m,ans);

    cout<<"The safe nodes present in the graph are : ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;

return 0;
}