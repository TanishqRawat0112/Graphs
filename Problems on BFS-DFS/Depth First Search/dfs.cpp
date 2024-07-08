#include<iostream>
#include<vector>
using namespace std;

void depthFirstSearch(vector<vector<int> >&adj,int start,int n,vector<int>&trav,int vis[]){  
    trav.push_back(start);
    vis[start]=1;
    for(auto it:adj[start]){
        if(!vis[it]){
            depthFirstSearch(adj,it,n,trav,vis);
        }
    }
    return;
    
}
 
int main(){
    int nodes;
    cout<<"Enter the number of nodes : ";
    cin>>nodes;

    int edges;
    cout<<"Enter the number of edges :";
    cin>>edges;

    vector<vector<int> >adj(nodes+1);
    cout<<"Enter the edges :"<<endl;
    for(int i=0;i<edges;i++){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    int start;
    cout<<"Enter the starting node :";
    cin>>start;

    vector<int>trav;

    int vis[nodes+1];
    for(int i=0;i<nodes+1;i++){
        vis[i]=0;
    }

    depthFirstSearch(adj,start,nodes,trav,vis);

    cout<<"The DFS Traversal :"<<endl;
    for(auto it:trav){
        cout<<it<<" ";
    }
    cout<<endl;

return 0;
}