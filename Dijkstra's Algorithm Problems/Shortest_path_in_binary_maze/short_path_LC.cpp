#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int shortest_path(vector<vector<int> >&maze,int n,int m){
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
    vector<vector<int> >dist(n,vector<int>(m,INT_MAX));
    pair<int,int>src;
    src.first=0;
    src.second=0;

    pair<int,int>dest;
    dest.first=n-1;
    dest.second=m-1;

    pair<int,pair<int,int> > p;
    p.first=1;
    p.second=src;
    dist[src.first][src.second]=1;
    pq.push(p);
    while(!pq.empty()){
        pair<int,int>cell=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        int dirX[]={-1,0,+1};
        int dirY[]={-1,0,+1};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int nr=cell.first + dirX[i];
                int nc=cell.second + dirY[j];
                if(nr==dest.first && nc==dest.second){
                    return dis+1;
                }
                if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc]==0 && (dis + 1 < dist[nr][nc])){
                    dist[nr][nc]=dis+1;
                    p.first=dist[nr][nc];
                    p.second.first=nr;
                    p.second.second=nc;
                    pq.push(p);
                }
            }
            
        }
    }
    return -1;
}
 
int main(){
    int n;
    cout<<"Enter the number of rows : ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns : ";
    cin>>m;

    cout<<"Enter the maze : "<<endl;
    vector<vector<int> >maze(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int inp;
            cin>>inp;
            maze[i][j]=inp;
        }
    }

    int ans=shortest_path(maze,n,m);

    cout<<"The shortest distance from the source location to the destination location will be : "<<ans<<endl;

return 0;
}