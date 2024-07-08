#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int> >&matrix,int n,int m,vector<vector<int> >&visited,queue<pair<int,int> >&q){
    int dirX[]={0,+1,0,-1};
    int dirY[]={+1,0,-1,0};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=row+dirX[i];
            int ncol=col+dirY[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==1 && visited[nrow][ncol]==0){
                visited[nrow][ncol]=1;
                pair<int,int>p;
                p.first=nrow;
                p.second=ncol;
                q.push(p);
            }
        }
    }
}

int numEnclaves(vector<vector<int> >&matrix,int n,int m){
    vector<vector<int> >visited(n,vector<int>(m,0));
    queue<pair<int,int> >q;
    for(int j=0;j<m;j++){
        if(matrix[0][j]==1){
            pair<int,int>p;
            p.first=0;
            p.second=j;
            visited[p.first][p.second]=1;
            q.push(p);
        }
        if(matrix[n-1][j]==1){
            pair<int,int>p;
            p.first=n-1;
            p.second=j;
            visited[p.first][p.second]=1;
            q.push(p);
        }
    }
    for(int i=0;i<n;i++){
        if(matrix[i][0]==1){
            pair<int,int>p;
            p.first=i;
            p.second=0;
            visited[p.first][p.second]=1;
            q.push(p);
        }
        if(matrix[i][m-1]==1){
            pair<int,int>p;
            p.first=i;
            p.second=m-1;
            visited[p.first][p.second]=1;
            q.push(p);
        }
    }

    bfs(matrix,n,m,visited,q);
    int counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1 && visited[i][j]==0){
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

    int ans=numEnclaves(matrix,n,m);

    cout<<"The number of enclaves are : "<<ans<<endl;
return 0;
}