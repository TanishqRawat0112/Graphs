#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int> >&adj,int vis[],int node){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(adj,vis,it);
        }
    }
}

int num_of_prov(vector<vector<int> >&adj,int n,int start){
    int vis[n+1];
    for(int i=0;i<n+1;i++){
        vis[i]=0;
    }
    int counter=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(adj,vis,i);
            counter++;
        }
    }
    return counter;
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<vector<int> >adj(n+1);
    cout<<"Enter the edges :"<<endl;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    int start;
    cout<<"Enter the starting node :";
    cin>>start;

    int numOfProv=num_of_prov(adj,n,start);

    cout<<"The number of provinces in the Graph are : "<<numOfProv<<endl;


return 0;
}