#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int>parent,size;
    public:
        DisjointSet(int n){
            for(int i=0;i<=n;i++){
                parent.push_back(i);
                size.push_back(1);
            }
        }

    int findParent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v){
            size[ulp_u]++;
            return;
        }

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

bool isValid(int nr,int nc,int n,int m){
    return (nr>=0 && nr<n && nc>=0 && nc<m);
}

int main(){
    int n;
    cout<<"Enter the number of rows in matrix : ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns in matrix : ";
    cin>>m;

    vector<vector<int> >matrix(n,vector<int>(m,0));

    int queries;
    cout<<"Enter the number of queries : ";
    cin>>queries;

    int nodes=(n*m)-1;

    DisjointSet ds(nodes);
    cout<<"set is created successfully"<<endl;
    int uniqueIslands=0;

    for(int quer=0;quer<queries;quer++){
        int qR,qC;
        cin>>qR>>qC;
        cout<<"Running query : "<<endl;
        if(matrix[qR][qC]==1){
            cout<<"Number of Islands : "<<uniqueIslands<<endl;
            continue;
        }
        matrix[qR][qC]=1;

        int node=qR*m + qC;
        int dirX[]={-1,0,+1,0};
        int dirY[]={0,+1,0,-1};

        for(int i=0;i<4;i++){
            int nr=qR+dirX[i];
            int nc=qC+dirY[i];
            if(isValid(nr,nc,n,m)==true && matrix[nr][nc]==1){
                int newNode=nr*m + nc;
                if(ds.findParent(node)!=ds.findParent(newNode)){
                    ds.unionBySize(node,newNode);
                    uniqueIslands--;
                }
            }
        }
        uniqueIslands++;
        cout<<"Number of Islands : "<<uniqueIslands<<endl;
    }
return 0;
}