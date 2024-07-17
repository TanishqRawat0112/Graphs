#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>shortest_path(vector<vector<pair<int,int> > >&adj,int n,int m,int src,int dest){
    vector<int>dist(n+1,INT_MAX);
    vector<int>parent(n+1);
    priority_queue< pair<int,int> , vector<pair<int,int> >,greater<pair<int,int> > >pq;
    for(int i=0;i<n+1;i++){
        parent[i]=i;
    }
    dist[src]=0;
    pair<int,int>p;
    p.first=0;
    p.second=src;
    pq.push(p);
    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        for(auto it:adj[node]){
            int adjNode=it.first;
            int adjwt=it.second;
            if(dis+adjwt < dist[adjNode]){
                dist[adjNode]=dis + adjwt;
                p.first=dist[adjNode];
                p.second=adjNode;
                parent[adjNode]=node;
                pq.push(p);
            }
        }
    }

    vector<int>ans;
    int node=dest;
    ans.insert(ans.begin(),node);
    
    while(parent[node]!=node){
        ans.insert(ans.begin(),parent[node]);
        node=parent[node];
    }
    // ans.insert(ans.begin(),src);

    return ans;
    
    
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<vector<pair<int,int> > >adj(n+1);
    cout<<"Enter the edges and weights : "<<endl;
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

    int dest;
    cout<<"Enter the destination node : ";
    cin>>dest;

    vector<int>ans=shortest_path(adj,n,m,src,dest);

    cout<<"The shortest to reach the destination from the source node will be : "<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}