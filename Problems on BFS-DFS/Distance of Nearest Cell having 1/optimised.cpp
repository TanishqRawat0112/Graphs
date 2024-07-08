#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int> >& matrix,queue<pair<pair<int,int>,int>  >&q,vector<vector<int> >&ans,int n, int m){
        vector<vector<int> >visited(n,vector<int>(m,0));
        int dirX[]={+1,0,-1,0};
        int dirY[]={0,-1,0,+1};
        while(!q.empty()){
            auto index=q.front().first;
            int distance=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int currDistance=distance;
                int nrow=index.first + dirX[i];
                int ncol=index.second + dirY[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==1 && visited[nrow][ncol]==0){
                    visited[nrow][ncol]=1;
                    currDistance++;
                    pair<pair<int,int>,int>entry;
                    entry.first.first=nrow;
                    entry.first.second=ncol;
                    entry.second=currDistance;
                    q.push(entry);
                    ans[nrow][ncol]=currDistance;
                }
            }
        }

    }

vector<vector<int> >dis_nearest(vector<vector<int> >matrix,int n,int m){
    queue<pair<pair<int,int>,int> >q;
        vector<vector<int> >ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    pair<pair<int,int>,int>entry;
                    pair<int,int>p;
                    p.first=i;
                    p.second=j;
                    entry.first=p;
                    entry.second=0;
                    q.push(entry);
                }
            }
        }
        bfs(matrix,q,ans,n,m);
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