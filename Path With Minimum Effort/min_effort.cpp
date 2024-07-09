#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int min_effort(vector<vector<int> >&heights,int n,int m){
    int minEff=INT_MAX;
    vector<vector<int> > visited(n,vector<int>(m,0));
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > >pq;
    visited[0][0]=1;
    pair<int,pair<int,int> >p;
    p.first=0;
    p.second.first=0;
    p.second.second=0;
    pq.push(p);
    int dirX[]={0,+1,0,-1};
    int dirY[]={+1,0,-1,0};
    while(!pq.empty()){
        int effort=pq.top().first;
        int r=pq.top().second.first;
        int c=pq.top().second.second;
        if(r==n-1 && c==m-1){
            minEff=min(minEff,effort);
        }
        visited[r][c]=1;
        pq.pop();
        for(int i=0;i<4;i++){
            int nr=r+dirX[i];
            int nc=c+dirY[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && visited[nr][nc]==0){
                int diff=abs(heights[nr][nc]-heights[r][c]);
                int mineff=max(effort,diff);
                p.first=mineff;
                p.second.first=nr;
                p.second.second=nc;
                pq.push(p);
            }
        }

    }
    return minEff;
}
 
int main(){
    int n;
    cout<<"Enter the number of rows : ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns : ";
    cin>>m;

    cout<<"Enter the heights : "<<endl;
    vector<vector<int> >heights(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int inp;
            cin>>inp;
            heights[i][j]=inp;
        }
    }

    int ans=min_effort(heights,n,m);

    cout<<"The minimum effort to reach the destination will be : "<<ans<<endl;


return 0;
}