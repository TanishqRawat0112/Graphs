#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int> >prims(vector<vector<pair<int,int> > >&adj,int n){
    vector<pair<int,int> >mst;
    int sum=0;
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
    vector<int>visited(n,0);
    pair<int,pair<int,int> > p;
    p.first=0;
    p.second.first=0;
    p.second.second=-1;
    pq.push(p);
    while(!pq.empty()){
        int dist=pq.top().first;
        int node=pq.top().second.first;
        int parent=pq.top().second.second;
        pq.pop();
        
        if(visited[node]==0){
            for(auto it:adj[node]){
                if(it.first==parent){
                    sum+=it.second;
                }
            }
            if(parent!=-1){
                pair<int,int>edge;
                edge.first=node;
                edge.second=parent;
                mst.push_back(edge);
            }
        }
        visited[node]=1;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int adW=it.second;
            if(visited[adjNode]==0){
                p.first=dist+adW;
                p.second.first=adjNode;
                p.second.second=node;
                pq.push(p);
            }
        }
    }
    return mst;
}
int prims2(vector<vector<pair<int,int> > >&adj,int n){
    vector<pair<int,int> >mst;
    int sum=0;
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
    vector<int>visited(n,0);
    pair<int,pair<int,int> > p;
    p.first=0;
    p.second.first=0;
    p.second.second=-1;
    pq.push(p);
    while(!pq.empty()){
        int dist=pq.top().first;
        int node=pq.top().second.first;
        int parent=pq.top().second.second;
        pq.pop();
        
        if(visited[node]==0){
            for(auto it:adj[node]){
                if(it.first==parent){
                    sum+=it.second;
                }
            }
            if(parent!=-1){
                pair<int,int>edge;
                edge.first=node;
                edge.second=parent;
                mst.push_back(edge);
            }
        }
        visited[node]=1;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int adW=it.second;
            if(visited[adjNode]==0){
                p.first=dist+adW;
                p.second.first=adjNode;
                p.second.second=node;
                pq.push(p);
            }
        }
    }
    return sum;
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<vector<pair<int,int> > >adj(n);
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

    vector<pair<int,int> >ans=prims(adj,n);
    int ans2=prims2(adj,n);

    cout<<"The cost of Minimum spanning tree will be : "<<ans2<<endl;

    cout<<"The edges included in the Minimum Spanning Tree will be : "<<endl;
    for(auto it:ans){
        cout<<it.first<<"-->"<<it.second<<endl;
    }

return 0;
}