#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int>rank,parent;

    public:
    DisjointSet(int n){
        for(int i=0;i<=n;i++){
            rank.push_back(0);
            parent.push_back(i);
        }
    }

    int findParent(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node]=findParent(parent[node]);

    }

    void unionRank(int u,int v){
        int pu=parent[u];
        int pv=parent[v];
        if(pu==pv)return;

        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }

};
 
int main(){
    DisjointSet s(7);
    s.unionRank(1,2);
    s.unionRank(2,3);
    s.unionRank(4,5);
    s.unionRank(6,7);
    s.unionRank(5,6);
    if(s.findParent(1)==s.findParent(4)){
        cout<<"Yes, same parent"<<endl;
    }
    else{
        cout<<"No, not same parent"<<endl;
    }
    s.unionRank(2,5);
    if(s.findParent(1)==s.findParent(4)){
        cout<<"Yes, same parent"<<endl;
    }
    else{
        cout<<"No, not same parent"<<endl;
    }

    
return 0;
}