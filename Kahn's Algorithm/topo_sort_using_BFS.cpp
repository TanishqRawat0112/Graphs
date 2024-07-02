#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>kahn_topo(vector<vector<int> >&adj,vector<int>&indegree,int n,int m){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
        ans.push_back(node);
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

    vector<vector<int> >adj(n);
    vector<int>indegree(n);
    cout<<"Enter the directed edges : "<<endl;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        indegree[second]++;
    }

    vector<int>topo=kahn_topo(adj,indegree,n,m);

    cout<<"The topological sort for this graph will be : "<<endl;
    for(int it:topo){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}