#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<vector<int> >&adj,int n,int m){
    vector<int>visited(n+1);
    queue<pair<int,int> >q;
    pair<int,int>p;
    p.first=1;
    p.second=1;
    q.push(p);
    visited[p.first]=p.second;
    while(!q.empty()){

        int node=q.front().first;
        int currColor=q.front().second;
        q.pop();
        for(auto it:adj[node]){
            int color=currColor;
            if(visited[it]==0){
                color*=-1;
                visited[it]=color;

                p.first=it;
                p.second=color; 
                q.push(p);
            }
            else if(visited[it]==currColor){
                return false;
            }
        }
    }
    return true;
}
 
int main(){
    int n;
    cout<<"Enter the number if nodes : ";
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

    if(!ans){
        cout<<"Yes, the graph is a bipartite graph."<<endl;
    }
    else{
        cout<<"No, the graph is not bipartite."<<endl;
    }
    
return 0;
}