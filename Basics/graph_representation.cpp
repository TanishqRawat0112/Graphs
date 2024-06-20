#include<iostream>
using namespace std;
 
int main(){
    int n;
    cout<<"Enter the number of nodes :";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    int adj[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            adj[i][j]=0;
        }
    }

    cout<<"Enter the edges : "<<endl;

    for(int i=0;i<m;i++){
        int first,second;
        cin>>first;
        cin>>second;
        adj[first][second]=1;
        adj[second][first]=1;
    }

    cout<<"The adjacency matrix : "<<endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}