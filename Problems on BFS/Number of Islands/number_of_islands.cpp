#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int> >&islands,vector<vector<int> >&visited,int row,int col,int dirX[],int dirY[]){
    visited[row][col]=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(row+dirX[i]<0 || row+dirX[i]>=islands.size() || col+dirY[j]<0 || col+dirY[j]>=islands[0].size() || (dirX[i]==0 && dirY[j]==0)){
                continue;
            }
                if(islands[row+dirX[i]][col+dirY[j]]==1){
                    if(visited[row+dirX[i]][col+dirY[j]]==0){
                    dfs(islands,visited,row+dirX[i],col+dirY[j],dirX,dirY);
                }
            }
        }
    }
}

int numIslands(vector<vector<int> >&islands,int rows,int columns){
    vector<vector<int> >visited(rows,vector<int>(columns,0));
    int counter=0;
    int dirX[]={+1,0,-1};
    int dirY[]={-1,0,+1};

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(islands[i][j]==1){
                if(visited[i][j]==0){
                    dfs(islands,visited,i,j,dirX,dirY);
                    counter++;
                }
            }
        }
    }
    return counter;
}
 
int main(){
    int n;
    cout<<"Enter the number of rows in matrix : ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns in matrix: ";
    cin>>m;

    vector<vector<int> >islands(n,vector<int>(m,0));
    cout<<"Enter the islands : "<<endl;
    int inp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>inp;
            islands[i][j]=inp;
        }
    }

    cout<<"The Number of Islands are : "<<numIslands(islands,n,m)<<endl;
return 0;
}