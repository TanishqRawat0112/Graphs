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

int max_stones_removal(vector<pair<int,int> >&stones,int n){
    DisjointSet ds(n);
    
}
 
int main(){
    int n;
    cout<<"Enter the the number of stones present in 2-D plane : ";
    cin>>n;

    vector<pair<int,int> >stones;
    cout<<"Enter the co-ordinates of stones : "<<endl;
    for(int i=0;i<n;i++){
        int row,col;
        cin>>row>>col;
        pair<int,int>p;
        p.first=row;
        p.second=col;
        stones.push_back(p);
    }

    int ans=max_stones_removal(stones,n);

    cout<<"The maximum stones that can be removed will be : "<<ans<<endl;


return 0;
}