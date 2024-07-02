#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dfs(vector<vector<int> >&matrix,int n,int m,vector<vector<int> >&visited,int row,int col,int dirX[],int dirY[],vector<pair<int,int> >&v,int originX,int originY){
    visited[row][col]=1;
    pair<int,int>p;
    p.first=row-originX;
    p.second=col-originY;
    v.push_back(p);
    for(int i=0;i<4;i++){
        int nrow=row+dirX[i];
        int ncol=col+dirY[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==1 && !visited[nrow][ncol]){
            dfs(matrix,n,m,visited,nrow,ncol,dirX,dirY,v,originX,originY);
        }
    }
}

int numIslands(vector<vector<int> >&matrix,int n,int m){
    vector<vector<int> >visited(n,vector<int>(m,0));
    set<vector<pair<int,int> > >st;
    int dirX[]={0,+1,0,-1};
    int dirY[]={+1,0,-1,0};
    int counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1 && visited[i][j]==0){
                vector<pair<int,int> >v;
                dfs(matrix,n,m,visited,i,j,dirX,dirY,v,i,j);
                st.insert(v);
                counter++;
            }
        }
    }

    cout<<"The set will be :"<<endl;
    for(auto it:st){
        for(auto i:it){
            cout<<"{"<<i.first<<","<<i.second<<"},";
        }
        cout<<endl;
    }
    return st.size();
}
 
int main(){
    int n;
    cout<<"Enter the number of rows : ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns : ";
    cin>>m;

    cout<<"Enter the matrix : "<<endl;
    vector<vector<int> >matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int inp;
            cin>>inp;
            matrix[i][j]=inp;
        }
    }

    int ans=numIslands(matrix,n,m);

    cout<<"The number of distinct Islands : "<<ans<<endl;

return 0;
}