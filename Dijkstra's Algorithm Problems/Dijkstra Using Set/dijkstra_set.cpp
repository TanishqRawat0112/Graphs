#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int>dijkstra(vector<vector<pair<int,int> > >&adj,int n,int m,int src){
    set<pair<int,int> >st;
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    pair<int,int>p;
    p.first=0;
    p.second=src;
    st.insert(p);
    while(!st.empty()){
        auto pr=*(st.begin());
        int dis=pr.first;
        int node=pr.second;
        st.erase(pr);
        for(auto it:adj[node]){
            if(it.second + dist[node] < dist[it.first]){
                if(dist[node]!=INT_MAX){
                    p.first=dist[node];
                    p.second=node;
                    st.erase(p);
                }
                dist[it.first]=it.second + dist[node];
                p.first=dist[it.first];
                p.second=it.first;
                st.insert(p);
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

    cout<<":Enter the edges and weight : "<<endl;
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