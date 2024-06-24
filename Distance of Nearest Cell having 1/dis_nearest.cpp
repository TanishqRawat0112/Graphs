#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int> >&matrix,int row,int col,int n,int m,vector<vector<int> >&ans){
    int currDistance;
    vector<vector<int> >visited(n,vector<int>(m,0));
    visited[row][col]=1;
    queue<pair<pair<int,int>,int> >q;
    pair<pair<int,int>,int >indexDis;
    pair<int,int>index;
    index.first=row;
    index.second=col;
    indexDis.first=index;
    indexDis.second=1;
    q.push(indexDis);
    int dirX[]={0,+1,0,-1};
    int dirY[]={+1,0,-1,0};
    while(!q.empty()){
        index=q.front().first;
        currDistance=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int distance=currDistance;
            int nrow=index.first + dirX[i];
            int ncol=index.second + dirY[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==0 && visited[nrow][ncol]==0){
                visited[nrow][ncol]=1;
                index.first=nrow;
                index.second=ncol;
                distance++;
                indexDis.first=index;
                indexDis.second=distance;
                q.push(indexDis);
            }
            else if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==1 && visited[nrow][ncol]==0){
                ans[row][col]=distance;
                return;
            }
        }
    }
}

vector<vector<int> > dis_nearest(vector<vector<int> >&matrix,int rows,int cols){
    vector<vector<int> >ans(rows,vector<int>(cols,0));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==0){
                bfs(matrix,i,j,rows,cols,ans);
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

    vector<vector<int> > ans=dis_nearest(matrix,n,m);

    cout<<"The distance between each cell and the nearest cell having 1 :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}