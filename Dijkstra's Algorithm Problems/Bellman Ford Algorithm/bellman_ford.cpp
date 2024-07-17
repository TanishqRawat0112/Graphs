#include<iostream>
#include<vector>
using namespace std;

vector<int> bellman_ford(vector<vector<int> >&edges,int n,int m,int src){
    vector<int>dist(n,1e9);
    dist[src]=0;
    for(int i=1;i<n;i++){
        for(auto it:edges){
            if(dist[it[0]]!=1e9 && dist[it[0]] + it[2] < dist[it[1]]){
                dist[it[1]]=dist[it[0]] + it[2];
            }
        }
    }

    for(auto it:edges){
        if(dist[it[0]]!=1e9 && dist[it[0]]+it[2] < dist[it[1]]){
            vector<int>def(1,-1);
            return def;
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

    vector<vector<int> >edges;
    vector<int>edge(3);
    cout<<"Enter the edges : "<<endl;
    for(int i=0;i<m;i++){
        int first,second,wt;
        cin>>first>>second>>wt;
        edge[0]=first;
        edge[1]=second;
        edge[2]=wt;
        edges.push_back(edge);
    }

    int src;
    cout<<"Enter the source node : ";
    cin>>src;

    vector<int> ans=bellman_ford(edges,n,m,src);

    cout<<"The minimum distance from Source Node to Destination Node will be : "<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}