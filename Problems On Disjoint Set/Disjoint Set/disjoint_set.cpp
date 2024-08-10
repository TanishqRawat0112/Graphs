#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;

    public:
    DisjointSet(int n){
        for(int i=0;i<=n;i++){
            rank.push_back(0);
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

    void unionSize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv){
            return;
        }

        if(size[pu]>=size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }

    int sizeOfComp(int n){
        int p=findParent(n);
        return size[p];
    }

};
 
int main(){
    DisjointSet s(7);
    s.unionSize(1,2);
    s.unionSize(2,3);
    s.unionSize(4,5);
    s.unionSize(6,7);
    s.unionSize(5,6);
    if(s.findParent(1)==s.findParent(4)){
        cout<<"Yes, same parent"<<endl;
    }
    else{
        cout<<"No, not same parent"<<endl;
    }

    cout<<"size of component in which node-4 is : "<<s.sizeOfComp(4)<<endl;
    s.unionSize(2,5);
    if(s.findParent(1)==s.findParent(4)){
        cout<<"Yes, same parent"<<endl;
    }
    else{
        cout<<"No, not same parent"<<endl;
    }

    
return 0;
}