#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>safe_states(vector<vector<int> >&adj,vector<int>&outdegree,int n,int m){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(outdegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            outdegree[it]--;
            if(outdegree[it]==0){
                q.push(it);
            }
        }
    }
    sort(topo.begin(),topo.end());
    return topo;
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of directed edges : ";
    cin>>m;

    cout<<"Enter the directed edges : "<<endl;
    vector<vector<int> >adj(n);
    vector<int>outdegree(n);
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[second].push_back(first);
        outdegree[first]++;
    }

    vector<int>ans=safe_states(adj,outdegree,n,m);

    cout<<"The Safe States present in the graph are : ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}