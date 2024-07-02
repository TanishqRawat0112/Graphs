#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isCycle(vector<vector<int> >&adj,vector<int>&indegree,int n,int m){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(topo.size()==n){
        return false;
    }
    return true;
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of directed edges : ";
    cin>>m;

    vector<vector<int> >adj(n+1);
    vector<int>indegree(n+1);
    cout<<"Enter the directed edges : "<<endl;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        indegree[second]++;
    }

    bool ans=isCycle(adj,indegree,n,m);

    if(ans){
        cout<<"Yes, there is a cycle present in the given graph."<<endl;
    }
    else{
        cout<<"No, there is no cycle present in the graph."<<endl;
    }

return 0;
}