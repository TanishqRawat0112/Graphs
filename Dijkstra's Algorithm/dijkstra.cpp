#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>dijkstra( vector<vector<pair<int,int> > >&adj,int n,int m,int src){
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
    vector<int>dist(n,INT_MAX);
    int distan=0;
    dist[src]=distan;
    pair<int,int>p;
    p.first=distan;
    p.second=src;
    pq.push(p);
    while(!pq.empty()){
        int distance=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            if((dist[node]+it.second) < dist[it.first]){
                dist[it.first]=dist[node] + it.second;
                p.first=dist[it.first];
                p.second=it.first;
                pq.push(p);
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

    cout<<"Enter the edges and the weight : "<<endl;
    vector<vector<pair<int,int> > >adj(n);
    for(int i=0;i<m;i++){
        int first,second,wt;
        cin>>first>>second>>wt;
        pair<int,int>p;
        p.first=second;
        p.second=wt;
        adj[first].push_back(p);
        p.first=first;
        adj[second].push_back(p);
    }

    int src;
    cout<<"Enter the source node : ";
    cin>>src;

    vector<int>ans=dijkstra(adj,n,m,src);

    cout<<"The minimum distance of each node from the source node will be : ";
    for(auto it:ans){
        cout<<it<<" ";
    }

    cout<<endl;

return 0;
}