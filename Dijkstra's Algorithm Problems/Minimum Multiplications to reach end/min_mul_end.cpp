#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int min_multi(vector<int>&multi,int n,int start,int end){
    queue<pair<int,int> >st;
    vector<int>dist(100000,1e9);
    dist[start]=0;
    if(end==start)return 0;
    pair<int,int>p;
    p.first=0;
    p.second=start;
    st.push(p);
    while(!st.empty()){
        auto pr=st.front();
        int currNum=pr.second;
        int steps=pr.first;
        st.pop();
        for(auto it:multi){
            int ins=(currNum*it)%100000;
            if(ins==end){
                return steps+1;
            }
            else{
                if(steps + 1 < dist[ins]){
                    dist[ins]=steps+1;
                    p.second=ins;
                    p.first=steps+1;
                    st.push(p);
                }
            }
        }
    }
    return -1;
}
 
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    cout<<"Enter the multiplication array : "<<endl;
    vector<int>multi;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        multi.push_back(inp);
    }

    int start,end;
    cout<<"Enter the starting number : ";
    cin>>start;

    cout<<"Enter the ending number : ";
    cin>>end;

    int ans=min_multi(multi,n,start,end);

    cout<<"The minimum multiplication steps required to reach the end number will be : "<<ans<<endl;

return 0;
}