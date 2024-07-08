#include<iostream>
#include<vector>
using namespace std;
 
int main(){
    int n;
    cout<<"Enter the number of nodes :";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    vector<vector<int> >adj_list(n+1);

    cout<<"Enter the edges :"<<endl;
    for(int i=0;i<m;i++){
        int first,second;
        cin>>first;
        cin>>second;
        adj_list[first].push_back(second);
        adj_list[second].push_back(first);
    }

    cout<<"Adjacency List will be :"<<endl;
    for(int i=1;i<n+1;i++){
        cout<<i<<"-->";
        for(int j=0;j<adj_list[i].size();j++){
            cout<<adj_list[i][j]<<",";
        }
        cout<<endl;
    }
return 0;
}