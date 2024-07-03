#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void topo_sort(vector<vector<int> >&adj,vector<int>&indegree,int K,vector<char>&ans){
    queue<int>q;
    for(int i=0;i<K;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node+'a');
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
}

vector<char>alien_dict(vector<string>&dict,int N,int K){
    vector<vector<int> >adj(K);
    vector<int>indegree(K);
    for(int i=0;i<N-1;i++){
        string s1=dict[i];
        string s2=dict[i+1];
        int j=0;
        while(j<s1.size() && j<s2.size()){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                indegree[s2[j]-'a']++;
                break;
            }
            j++;
        }
    }

    vector<char>ans;
    topo_sort(adj,indegree,K,ans);

    return ans;
}
 
int main(){
    int n;
    cout<<"Enter the number of words in the dictionary : ";
    cin>>n;

    int m;
    cout<<"Enter the number of alphabets : ";
    cin>>m;

    vector<string>dict;
    cout<<"Enter the words of dictionary : "<<endl;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        dict.push_back(s);
    }

    vector<char>ans=alien_dict(dict,n,m);

    if(ans.size()==m){
        cout<<"The order of the Alien Letters should be : "<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }
    }
    else{
        cout<<"The order for the alien alphabets is not possible.";
    }
    
    cout<<endl;


return 0;
}