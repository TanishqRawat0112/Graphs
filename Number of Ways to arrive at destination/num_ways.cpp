#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int num_ways(vector<vector<pair<int,int> > >&adj,int n){
    priority_queue<pair<int,int> , vector<pair<int,int> >,greater<pair<int,int> > >pq;
    int counter=0;
    int minCost=1e9;
    vector<int>dist(n,1e9);
    dist[0]=0;
    pair<int,int>p;
    p.first=0;
    p.second=0;
    pq.push(p);
    while(!pq.empty()){
        int cost=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(node==n-1){
                if(cost==minCost){
                    counter++;
                }
                else if(cost<minCost){
                    minCost=cost;
                    counter=1;
                }
                else{
                    break;
                }
            }
        
        for(auto it:adj[node]){
            int adjNode=it.first;
            int adW=it.second;
            if(cost + adW <= dist[adjNode]){
                dist[adjNode]=cost+adW;
                p.first=dist[adjNode];
                p.second=adjNode;
                pq.push(p);
            }
        }
    }
    return counter;
}
 
int main(){
    int n;
    cout<<"Enter the number of cities : ";
    cin>>n;

    int m;
    cout<<"Enter the number of roads : ";
    cin>>m;

    vector<vector<pair<int,int> > >adj(n);
    cout<<"Enter the roads connecting the cities : "<<endl;
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

    int ans=num_ways(adj,n);

    cout<<"The Number of ways to arrive at destination will be : "<<ans<<endl;

return 0;
}