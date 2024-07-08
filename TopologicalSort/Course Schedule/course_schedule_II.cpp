#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>course_schedule(vector<vector<int> >&adj,vector<int>&indegree,int numCourses,int m){
    queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
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
        if(topo.size()==numCourses){
            return topo;
        }
        vector<int>nl;
        return nl;
}
 
int main(){
    int n;
    cout<<"Enter the number of courses : ";
    cin>>n;

    int m;
    cout<<"Enter the number of prerequisites : ";
    cin>>m;

    vector<vector<int> >adj(n);
    vector<int>indegree(n);
    cout<<"Enter the prerequisites : "<<endl;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first>>second;
        adj[second].push_back(first);
        indegree[first]++;
    }

    vector<int>ans=course_schedule(adj,indegree,n,m);

    cout<<"The Course Schedule should be : ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
return 0;
}