#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> >build_matrix(vector<vector<int> >&positions,int k){
    vector<vector<int> >matrix(k,vector<int>(k,0));
    for(int i=1;i<=k;i++){
        int r=positions[i][0];
        int c=positions[i][1];
        matrix[r][c]=i;
    }
    return matrix;
}

vector<vector<int> >find_position(vector<int>&topoRow,vector<int>&topoCol,int k){
    vector<vector<int> >positions(k+1);
    for(int i=0;i<k;i++){
        positions[topoRow[i]].push_back(i);
    }
    for(int i=0;i<k;i++){
        positions[topoCol[i]].push_back(i);
    }
    return positions;
}

vector<int> topo_sort(vector<vector<int> >&adj,vector<int>&indegree,int k){
    queue<int>q;
    indegree[0]=1e9;
    for(int i=0;i<=k;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    if(q.empty())return topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(topo.size()!=k){
        vector<int>fake;
        return fake;
    }
    return topo;
}
 
int main(){
    int k;
    cout<<"Enter the dimension of Matrix : ";
    cin>>k;

    int rowConditions;
    cout<<"Enter the number of conditions of rows : ";
    cin>>rowConditions;

    cout<<"Enter the conditions of rows : "<<endl;
    vector<vector<int> >rows(k+1);
    vector<int>inRow(k+1);
    for(int i=0;i<rowConditions;i++){
        int first,second;
        cin>>first>>second;
        rows[first].push_back(second);
        inRow[second]++;
    }

    int colConditions;
    cout<<"Enter the number of conditions of columns : ";
    cin>>colConditions;

    cout<<"Enter the conditions of columns : "<<endl;
    vector<vector<int> >cols(k+1);
    vector<int>inCol(k+1);
    for(int i=0;i<colConditions;i++){
        int first,second;
        cin>>first>>second;
        cols[first].push_back(second);
        inCol[second]++;
    }

    vector<int> topoRow=topo_sort(rows,inRow,k);
    vector<int> topoCol=topo_sort(cols,inCol,k);
    if(topoRow.size()==0 || topoCol.size()==0){
        cout<<"[ ]"<<endl;
        return 0;
    }

    vector<vector<int> >positions=find_position(topoRow,topoCol,k);

    vector<vector<int> >ans=build_matrix(positions,k);
    cout<<"Resultant Matrix will be : "<<endl;
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

return 0;
}