#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int> >&adj,int n,int m,vector<int>&color,int start,int col){
    color[start]=col;
    for(auto it:adj[start]){
        if(color[it]==-1){
            if(dfs(adj,n,m,color,it,!col)==false){
                return false;
            }
        }
        else if(color[it]==color[start]){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int> >&adj,int n,int m){
    vector<int>color(n+1,-1);
    return dfs(adj,n,m,color,1,0);
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    cout<<"Enter the edges : "<<endl;
    vector<vector<int> >adj(n+1);
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    bool ans=isBipartite(adj,n,m);
    if(ans){
        cout<<"Yes, the given graph is bipartite."<<endl;
    }
    else{
        cout<<"No, the given graph is not bipartite."<<endl;
    }
return 0;
}