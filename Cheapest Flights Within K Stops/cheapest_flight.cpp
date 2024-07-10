#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int cheapest_flight(vector<vector<pair<int,int> > >&flights,int n,int src,int dest,int k){
    vector<int>prices(n,1e9);
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
    int ans=INT_MAX;
    prices[src]=0;
    pair<int,pair<int,int> >p;
    p.first=0;
    p.second.first=0;
    p.second.second=src;
    pq.push(p);
    while(!pq.empty()){
        int price=pq.top().first;
        int stops=pq.top().second.first;
        int node=pq.top().second.second;
        if(node==dest){
            ans=min(ans,price);
        }
        pq.pop();
        for(auto it:flights[node]){
            if(price + it.second < prices[it.first]){
                if(it.first==dest){
                    prices[it.first]=price + it.second;
                    p.first=prices[it.first];
                    p.second.first=stops;
                    p.second.second=it.first;
                    pq.push(p);
                }
                if(stops+1<=k){
                    prices[it.first]=price + it.second;
                    p.first=prices[it.first];
                    p.second.first=stops+1;
                    p.second.second=it.first;
                    pq.push(p);
                }
            }
        }
    }
    return ans;
}
 
int main(){
    int n;
    cout<<"Enter the number of cities : ";
    cin>>n;

    int m;
    cout<<"Enter the number of flights : ";
    cin>>m;

    vector<vector<pair<int,int> > >flights(n);
    cout<<"Enter the cities and flights details : "<<endl;
    for(int i=0;i<m;i++){
        int from,to,price;
        cin>>from>>to>>price;
        pair<int,int>p;
        p.first=to;
        p.second=price;
        flights[from].push_back(p);
    }

    int src,dest,maxStops;
    cout<<"Enter the source city :";
    cin>>src;

    cout<<"Enter the destination City : ";
    cin>>dest;

    cout<<"Enter Maximum Stops allowed : ";
    cin>>maxStops;

    int ans=cheapest_flight(flights,n,src,dest,maxStops);

    cout<<"The Cheapest Flight with at most "<<maxStops<<" stops will cost : "<<ans<<endl;

return 0;
}