#include<iostream>
#include<vector>
using namespace std;

void make_zero(vector<vector<int> >&matrix,vector<vector<int> >&visited,vector<vector<int> >&ans,int n,int m,int row,int col){
    int dirX[]={0,+1,0,-1};
    int dirY[]={+1,0,-1,0};
    visited[row][col]=1;
    ans[row][col]=0;
    for(int i=0;i<4;i++){
        int nrow=row+dirX[i];
        int ncol=col+dirY[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==0 && visited[nrow][ncol]==0){
            make_zero(matrix,visited,ans,n,m,nrow,ncol);
        }
    }
}

vector<vector<int> >surrounded(vector<vector<int> >&matrix,int n,int m){
    vector<vector<int> >visited(n,vector<int>(m,0));
    vector<vector<int> >ans(n,vector<int>(m,1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(matrix[i][j]==0 && visited[i][j]==0){
                    make_zero(matrix,visited,ans,n,m,i,j);
                }
            }
        }
    }
    return ans;
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

    vector<vector<int> >ans=surrounded(matrix,n,m);
    cout<<"The updated matrix will be : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}