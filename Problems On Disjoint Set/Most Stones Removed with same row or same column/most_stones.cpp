#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    public:
    vector<int>parent,size;

    DisjointSet(int n){
        for(int i=0;i<n;i++){
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
            size[ulp_v]+=size[ulp_v];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int max_stones_removal(vector<vector<int,int> >&stones,int n){
    DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    cout<<i<<" "<<j<<endl;
                    ds.unionBySize(i,j);
                    // break;
                }
            }
        }
        int singleparent=0;
        for(int i=0;i<ds.parent.size();i++){
            if(ds.parent[i]==i){
                singleparent++;
            }
        }
        return n-singleparent;
    
}
 
int main(){
    int n;
    cout<<"Enter the the number of stones present in 2-D plane : ";
    cin>>n;

    vector<vector<int,int> >stones;
    cout<<"Enter the co-ordinates of stones : "<<endl;
    for(int i=0;i<n;i++){
        int row,col;
        cin>>row>>col;
        vector<int,int>p;
        p.push_back(row);
        p.push_back(col);
        stones.push_back(p);
    }

    int ans=max_stones_removal(stones,n);

    cout<<"The maximum stones that can be removed will be : "<<ans<<endl;


return 0;
}