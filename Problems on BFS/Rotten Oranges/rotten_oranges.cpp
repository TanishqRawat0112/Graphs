#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int bfs(vector<vector<int> >&matrix,queue<pair<pair<int,int>,int> >&q,vector<vector<int> >&visited){
    int time;
    pair<int,int>index;
    pair<pair<int,int>,int> indTime;
    int n=matrix.size();
    int m=matrix[0].size();

    int dirX[]={-1,0,0,+1};
    int dirY[]={0,-1,+1,0};

    while(!q.empty()){
        pair<int,int>currIndex=q.front().first;
        time=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nRow=currIndex.first + dirX[i];
            int nCol=currIndex.second + dirY[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && visited[nRow][nCol]==0 && matrix[nRow][nCol]==1){
                visited[nRow][nCol]=1;
                matrix[nRow][nCol]=2;
                index.first=nRow;
                index.second=nCol;
                indTime.first=index;
                indTime.second=time+1;
                q.push(indTime);
            }
        }
    }
    //Checking if all the fresh oranges are converted to rotten:
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1){
                return -1;
            }
        }
    }

    return time;

}

int rotAll(vector<vector<int> >&matrix){
    queue<pair<pair<int,int>,int> >q;
    pair<int,int>index;
    pair<pair<int,int>,int> indTime;
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int> >visited(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==2){
                index.first=i;
                index.second=j;
                indTime.first=index;
                indTime.second=0;
                q.push(indTime);
                visited[i][j]=1;
            }
        }
    }
    return bfs(matrix,q,visited);
}
 
int main(){
    int n;
    cout<<"Enter the number of rows : ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns : ";
    cin>>m;

    vector<vector<int> >matrix(n,vector<int>(m,0));
    cout<<"Enter the matrix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int inp;
            cin>>inp;
            matrix[i][j]=inp;
        }
    }
    
    cout<<"Minimum time required to rot all oranges : "<<rotAll(matrix)<<endl;
return 0;
}