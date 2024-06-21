#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int> >&matrix,vector<vector<int> >&visited,int newColor,int startRow,int startCol){
    queue<pair<int,int> >q;
    pair<int,int>p;
    p.first=startRow;
    p.second=startCol;
    q.push(p);
    int fixedColor=matrix[startRow][startCol];
    matrix[startRow][startCol]=newColor;
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();

        int dirX[]={+1,0,0,-1};
        int dirY[]={0,-1,+1,0};

        for(int i=0;i<4;i++){
            int newRow=row+dirX[i];
            int newCol=col+dirY[i];
            if(newRow>=0 && newRow<matrix.size() && newCol>=0 && newCol<matrix[0].size() && matrix[newRow][newCol]==fixedColor && visited[newRow][newCol]==0){
                visited[newRow][newCol]=1;
                matrix[newRow][newCol]=newColor;
                p.first=newRow;
                p.second=newCol;
                q.push(p);
            }
        }
    }
}

void flood_fill(vector<vector<int> >&matrix,int newColor,int startRow,int startCol){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int> >visited(n,vector<int>(m,0));
    visited[startRow][startCol]=1;
    bfs(matrix,visited,newColor,startRow,startCol);
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

    int newColor;
    cout<<"Enter the new color : ";
    cin>>newColor;

    int sr,sc;
    cout<<"Enter the starting row : ";
    cin>>sr;
    cout<<"Enter the starting column : ";
    cin>>sc;

    flood_fill(matrix,newColor,sr,sc);

    cout<<"Updated matrix after coloring : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}