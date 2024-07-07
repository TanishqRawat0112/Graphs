#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<string.h>
using namespace std;

int word_ladder(vector<string>&wordList,string bw,string ew){
    queue<pair<string,int> >q;
    unordered_set<string>st(wordList.begin(),wordList.end());
    pair<string,int>p;
    p.first=bw;
    p.second=1;
    q.push(p);
    st.erase(bw);
    while(!q.empty()){
        string check=q.front().first;
        int len=q.front().second;
        if(check==ew){
            return len;
        }
        q.pop();
        for(int i=0;i<check.size();i++){
            char original=check[i];
            for(char ch='a';ch<='z';ch++){
                check[i]=ch;
                if(st.find(check)!=st.end()){
                    st.erase(check);
                    p.first=check;
                    p.second=len+1;
                    q.push(p);
                }
            }
            check[i]=original;
        }
    }
    return 0;
}
 
int main(){
    string bw;
    cout<<"Enter the Begin Word : ";
    cin>>bw;

    string ew;
    cout<<"Enter the End Word : ";
    cin>>ew;

    vector<string>wordList;
    cout<<"Enter the word List : "<<endl;
    while(true){
        string temp;
        cin>>temp;
        if(temp=="-1"){
            break;
        }
        wordList.push_back(temp);
    }

    int ans=word_ladder(wordList,bw,ew);

    cout<<"The Length of the Sequence to reach End Word from begin Word is : "<<ans<<endl;
return 0;
}