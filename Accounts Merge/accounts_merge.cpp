#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class DisjointSet{
    vector<int>parent,size;
    public:
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
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]]=i;
                }
                else{
                    int u=mpp[accounts[i][j]];
                    int v=i;
                    ds.unionBySize(u,v);
                }
            }
        }

        vector<vector<string>>ans(n);
        for(auto it:mpp){
            int index=ds.findParent(it.second);
            ans[index].push_back(it.first);
        }
        for(int i=0;i<n;i++){
            if(ans[i].size()==0)continue;
            sort(ans[i].begin(),ans[i].end());
            ans[i].insert(ans[i].begin(),accounts[i][0]);
        }
        vector<vector<string>>final;
        for(auto it:ans){
            if(it.size()){
                final.push_back(it);
            }
        }

        return final;
    }
 
int main(){
    int n;
    cout<<"Enter the size of the list : ";
    cin>>n;

    int m;
    
return 0;
}