#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfs(vector<vector<int> >&adj,int n,int start){
    vector<int>ans;
    int vis[n+1];
    for(int i=0;i<n+1;i++){
        vis[i]=0;
    }
    vis[start]=1;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it); 
            }
        }
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

    vector<vector<int> >adj(n+1);
    cout<<"Enter the edges : "<<endl;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    int start;
    cout<<"Enter the Starting Node:";
    cin>>start;

    vector<int>ans=bfs(adj,n,start);

    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}