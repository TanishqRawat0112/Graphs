#include<iostream>
#include<vector>
using namespace std;

int timer=0;

void dfs(vector<vector<int> >&adj,int node,int parent,vector<int>&visited,vector<int>&tin,vector<int>&low,vector<vector<int> >&ans){
    visited[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it:adj[node]){
        if(it==parent)continue;
        if(!visited[it]){
            dfs(adj,it,node,visited,tin,low,ans);
            low[node]=min(low[node],low[it]);
            if(low[it] > tin[node]){
                vector<int>br;
                br.push_back(it);
                br.push_back(node);
                ans.push_back(br);
            }
        }
        else{
            low[node]=min(low[node],low[it]);
        }
    }
}

vector<vector<int> >bridges(vector<vector<int> >&adj,int n,int m){
    vector<int>visited(n,0);
    vector<int>tin(n,0);
    vector<int>low(n,0);
    vector<vector<int> >ans;
    dfs(adj,0,-1,visited,tin,low,ans);
    return ans;
}

int num_bridges(vector<vector<int> >&adj,int n,int m){
    vector<int>visited(n,0);
    vector<int>tin(n,0);
    vector<int>low(n,0);
    vector<vector<int> >ans;
    dfs(adj,0,-1,visited,tin,low,ans);
    return ans.size();
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<vector<int> >adj(n);
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    int ans=num_bridges(adj,n,m);
    vector<vector<int> >bridge=bridges(adj,n,m);

    cout<<"The number of bridges in the given graph will be : "<<ans<<endl;

    cout<<"The bridges in the given graph will be : "<<endl;
    for(auto it:bridge){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
return 0;
}