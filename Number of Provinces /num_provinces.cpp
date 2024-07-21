#include<iostream>
#include<vector>
#include<set>
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
            if(parent[node]==node){
                return node;
            }
            return parent[node]=findParent(parent[node]);
        }

        void unionBySize(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);
            if(pu==pv)return;
            if(size[pu]<size[pv]){
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else{
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }
};

vector<vector<int> >mat2list(vector<vector<int> >&adjMat,int n){
    vector<vector<int> >adj(n+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(adjMat[i][j]==1){
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }
        }
    }
    return adj;
}

int num_province(vector<vector<int> >&adj,int n,int m){
    DisjointSet ds(n);
    for(int i=0;i<=n;i++){
        for(auto it:adj[i]){
            if(ds.findParent(i)!=ds.findParent(it)){
                ds.unionBySize(i,it);
            }
        }
    }
    set<int>st;
    for(int i=0;i<=n;i++){
        st.insert(ds.findParent(i));
    }
    return st.size()-1;
}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    vector<vector<int> >adjMat(n,vector<int>(n,0));
    cout<<"Enter the edge matrix : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int inp;
            cin>>inp;
            adjMat[i][j]=inp;
        }
    }

    vector<vector<int> >adj=mat2list(adjMat,n);
    int m=adj.size();

   int ans= num_province(adj,n,m);
        
    cout<<"The number of provinces will be : "<<ans<<endl;

return 0;
}