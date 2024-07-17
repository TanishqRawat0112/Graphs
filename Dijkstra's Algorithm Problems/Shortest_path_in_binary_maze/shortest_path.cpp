#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int shortest_path(vector<vector<int> >&maze,int n,int m,pair<int,int>&src,pair<int,int>&dest){
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
    vector<vector<int> >dist(n,vector<int>(m,INT_MAX));
    pair<int,pair<int,int> > p;
    p.first=0;
    p.second=src;
    dist[src.first][src.second]=0;
    pq.push(p);
    while(!pq.empty()){
        pair<int,int>cell=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        int dirX[]={0,+1,0,-1};
        int dirY[]={+1,0,-1,0};
        for(int i=0;i<4;i++){
            int nr=cell.first + dirX[i];
            int nc=cell.second + dirY[i];
            if(nr==dest.first && nc==dest.second){
                return dis+1;
            }
            if(nr>=0 && nr<n && nc>=0 && nc<m && (dis + 1 < dist[nr][nc])){
                dist[nr][nc]=dis+1;
                p.first=dist[nr][nc];
                p.second.first=nr;
                p.second.second=nc;
                pq.push(p);
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

    pair<int,int>src;
    cout<<"Enter the Source Location : ";
    int r,c;
    cin>>r>>c;
    src.first=r;
    src.second=c;

    pair<int,int>dest;
    cout<<"Enter the Destination Location : ";
    cin>>r>>c;
    dest.first=r;
    dest.second=c;

    int ans=shortest_path(maze,n,m,src,dest);

    cout<<"The shortest distance from the source location to the destination location will be : "<<ans<<endl;

return 0;
}