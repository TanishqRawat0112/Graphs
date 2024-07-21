#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int>size,parent;
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
            if(pu==pv){
                return;
            }
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

vector<pair<int,int> >kruskal(vector<pair<int,pair<int,int> > >&edges,int n,int m){
    vector<pair<int,int> >mst;
    pair<int,int>p;
    DisjointSet ds(n);
    for(auto it:edges){
        if(ds.findParent(it.second.first)==ds.findParent(it.second.second)){
            continue;
        }
        ds.unionBySize(it.second.first,it.second.second);
        p.first=it.second.first;
        p.second=it.second.second;
        mst.push_back(p);
    }

    return mst;

}
 
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<pair<int,pair<int,int> > >edges;
    cout<<"Enter the edges along with weight : ";
    for(int i=0;i<m;i++){
        pair<int,pair<int,int> >p;
        int u,v,wt;
        cin>>u>>v>>wt;
        p.first=wt;
        p.second.first=u;
        p.second.second=v;
        edges.push_back(p);
    }
    sort(edges.begin(),edges.end());

    vector<pair<int,int> >ans=kruskal(edges,n,m);

    cout<<"Edges included in Minimum Spanning Tree will be : "<<endl;
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }

return 0;
}