#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(vector<vector<pair<int,int> > >&adj,stack<int>&st,vector<int>&visited,int n,int node){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it.first]){
            dfs(adj,st,visited,n,it.first);
        }
    }
    st.push(node);
}

void topo_sort(vector<vector<pair<int,int> > >&adj,stack<int>&st,vector<int>&visited,int n){
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,st,visited,n,i);
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

    vector<vector<pair<int,int> > >adj(n);
    cout<<"Enter the directed edges with their weights : ";
    for(int i=0;i<m;i++){
        int first,second,weight;
        cin>>first>>second>>weight;
        pair<int,int>p;
        p.first=second;
        p.second=weight;
        adj[first].push_back(p);
    }

    int src;
    cout<<"Enter the source node : ";
    cin>>src;
    stack<int>st;
    vector<int>visited(n,0);
    topo_sort(adj,st,visited,n);

    vector<int>dist(n,INT_MAX);
    while(st.top()!=src){
        st.pop();
    }
    dist[st.top()]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto it:adj[node]){
            dist[it.first]=min(dist[it.first],dist[node]+it.second);
        }

    }

    cout<<"Minimum Distance should be : "<<endl;
    for(auto it:dist){
        if(it==INT_MAX){
            cout<<"INF"<<" ";
            continue;
        }
        cout<<it<<" ";
    }
    cout<<endl;


return 0;
}