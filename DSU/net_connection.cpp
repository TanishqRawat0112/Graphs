#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int>size,parent;
    public:
        DisjointSet(int n){
            for(int i=0;i<=n;i++){
                size.push_back(1);
                parent.push_back(i);
            }
        }
    
        int findParent(int node){
            if(parent[node]==node){
                return node;
            }
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

int dsu(vector<vector<int> >edges,int n,int m){
    DisjointSet ds(n);
    for(int i=0;i<m;i++){
        
    }
}
 
int main(){
    int n;
    cout<<"Enter the number of Nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<vector<int> >edges(m,vector<int>(2,0));
    cout<<"Enter the edges : ";
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        edges[i][0]=first;
        edges[i][1]=second;
    }

    if(edges.size()<n-1){
        cout<<"-1"<<endl;
        return 0;
    }

    int ans=dsu(edges,n,m);

    cout<<"The number of operations to make the network connected : "<<ans<<endl;

return 0;
}