#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>shortest_dist(vector<vector<int> >&adj,int n,int m,int src){
    queue<pair<int,int> >q;
    vector<int>dist(n,INT_MAX);
    pair<int,int>p;
    p.first=src;
    p.second=0;
    q.push(p);
    while(!q.empty()){
        int node=q.front().first;
        int wt=q.front().second;
        q.pop();
        dist[node]=min(dist[node],wt);
        for(auto it:adj[node]){
            if(dist[it]==INT_MAX){
                p.first=it;
                p.second=wt+1;
                q.push(p);
            }
        }
    }
    return dist;
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
        adj[second].push_back(first);
    }

    int src;
    cout<<"Enter the source node : ";
    cin>>src;

    vector<int>ans=shortest_dist(adj,n,m,src);

    cout<<"The shortest distance from the source node to each node will be : ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}