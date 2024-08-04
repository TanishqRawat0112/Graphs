#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class DisjointSet{
    public:
    vector<int>size,parent;
    DisjointSet(int n){
        for(int i=0;i<n;i++){
            size.push_back(1);
            parent.push_back(i);
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

bool isValid(int ni,int nj,int n){
    return ni>=0 && ni<n && nj>=0 && nj<n;
}

int large_island(vector<vector<int> >&matrix,int n){
    DisjointSet ds(n*n);
    int dirX[]={1,0,-1,0};
    int dirY[]={0,1,0,-1};
    //checking for the ones here :
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                for(int k=0;k<4;k++){
                    int ni=i+dirX[k];
                    int nj=j+dirY[k];
                    if(isValid(ni,nj,n) && matrix[ni][nj]==1){
                        int node=i*n + j;
                        int adjNode=ni*n + nj;
                        if(ds.findParent(node)!=ds.findParent(adjNode)){
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
    }

    //checking the size :
    cout<<"The size vector will be : "<<endl;
    for(auto it:ds.size){
        cout<<it<<" ";
    }
    cout<<endl;

    //checking for the zero:
    int maxSize=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                int totalIslands=0;
                unordered_map<int,int>mpp;
                for(int k=0;k<4;k++){
                    int ni=i + dirX[k];
                    int nj=j+dirY[k];
                    if(isValid(ni,nj,n) && matrix[ni][nj]==1){ 
                            int node=i*n + j;
                            int adjNode=ni*n + nj;
                            int par=ds.findParent(adjNode);
                            
                            if(mpp.find(par)==mpp.end()){
                                mpp[par]=1;
                                totalIslands+=ds.size[ds.findParent(adjNode)];
                            }
                    }
                }
                maxSize=max(maxSize,totalIslands+1);
            }
        }
    }
    int maxVec=*max_element(ds.size.begin(),ds.size.end());
    return max(maxSize,maxVec);
}
 
int main(){
    int n;
    cout<<"Enter the size of matrix : ";
    cin>>n;

    vector<vector<int> >matrix(n,vector<int>(n,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int inp;
            cin>>inp;
            matrix[i][j]=inp;
        }
    }

    int ans=large_island(matrix,n);

    cout<<"The largest island will be of the size : "<<ans<<endl;

return 0;
}