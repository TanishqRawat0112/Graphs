#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(vector<vector<int> >&adj,vector<int>&visited,int node,stack<int>&st){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(adj,visited,it,st);
        }
    }
    st.push(node);
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<vector<int> >edges;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        vector<int>edge;
        edge.push_back(first);
        edge.push_back(second);
        edges.push_back(edge);
    }

    vector<vector<int> >adj(n);
    vector<vector<int> >adjRev(n);
    for(auto it:edges){
        int first=it[0];
        int second=it[1];
        adj[first].push_back(second);
        adjRev[second].push_back(first);
    }

    stack<int>st;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,visited,i,st);
        }
    }
    vector<int>visCheck(n,0);
    stack<int>temp;
    int ans=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visCheck[node]){
            dfs(adjRev,visCheck,node,temp);
            ans++;
        }
    }

    cout<<"The Number of Strongly Connected Components in the given graph will be : "<<ans<<endl;

return 0;
}