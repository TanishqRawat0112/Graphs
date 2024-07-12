#include<iostream>
#include<vector>
#include<set>
using namespace std;

int min_multi(vector<int>&multi,int n,int start,int end){
    set<pair<int,int> >st;
    pair<int,int>p;
    p.first=start;
    p.second=0;
    st.insert(p);
    while(!st.empty()){
        auto pr=*(st.begin());
        int currNum=pr.first;
        int steps=pr.second;
        st.erase(pr);
        for(auto it:multi){
            int ins=(currNum*it)%100000;
            if(ins==end){
                return steps+1;
            }
            if(ins < end){
                p.first=ins;
                p.second=steps+1;
                st.insert(p);
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