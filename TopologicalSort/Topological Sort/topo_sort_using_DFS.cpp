#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(vector<vector<int> >&adj,stack<int>&st,vector<int>&visited,int node){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(adj,st,visited,it);
        }
    }
    st.push(node);
}

vector<int>topo_sort(vector<vector<int> >&adj,int n,int m){
    stack<int>st;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,st,visited,i);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        int element=st.top();
        st.pop();
        ans.push_back(element);
    }
    return ans;
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<vector<int> >adj(n);
    cout<<"Enter the edges : "<<endl;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
    }

    vector<int>topo=topo_sort(adj,n,m);

    cout<<"The Topological Sort will be : "<<endl;
    for(auto it:topo){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}