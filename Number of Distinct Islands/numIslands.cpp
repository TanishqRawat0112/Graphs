#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int> >&matrix,int n,int m,vector<vector<int> >&visited,int row,int col,int dirX[],int dirY[]){
    visited[row][col]=1;
    for(int i=0;i<4;i++){
        int nrow=row+dirX[i];
        int ncol=col+dirY[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==1 && !visited[nrow][ncol]){
            dfs(matrix,n,m,visited,nrow,ncol,dirX,dirY);
        }
    }
}

int numIslands(vector<vector<int> >&matrix,int n,int m){
    vector<vector<int> >visited(n,vector<int>(m,0));
    int dirX[]={0,+1,0,-1};
    int dirY[]={+1,0,-1,0};
    int counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1 && visited[i][j]==0){
                dfs(matrix,n,m,visited,i,j,dirX,dirY);
                counter++;
            }
        }
    }
    return counter;
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