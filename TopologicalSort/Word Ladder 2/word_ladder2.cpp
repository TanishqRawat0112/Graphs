#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

vector<vector<string> >word_ladder(vector<string>&wordList,string bw,string ew){
    vector<vector<string> >ans;
    queue<vector<string> >q;
    unordered_set<string>st(wordList.begin(),wordList.end());
    vector<string>p;
    p.push_back(bw);
    q.push(p);
    st.erase(bw);
    int level=0;
    int minlen=INT_MAX;
    while(!q.empty()){
        vector<string> wordQ=q.front();
        string word=wordQ[wordQ.size()-1];
        if(wordQ.size()>level){
            level++;
            for(auto it:p){
                st.erase(it);
            }
            p.clear();
        }
        if(word==ew){
            if(wordQ.size()<=minlen){
                minlen=wordQ.size();
                ans.push_back(wordQ);
            }
            else{
                break;
            }
        }
        q.pop();
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(int ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    wordQ.push_back(word);
                    p.push_back(word);
                    q.push(wordQ);
                    wordQ.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return ans;

}
 
int main(){
    string bw;
    cout<<"Enter the begin word : ";
    cin>>bw;

    string ew;
    cout<<"Enter the end word : ";
    cin>>ew;

    cout<<"Enter the word List : "<<endl;
    vector<string>wordList;
    while(true){
        string t;
        cin>>t;
        if(t=="-1"){
            break;
        }
        wordList.push_back(t);
    }

    vector<vector<string> >ans=word_ladder(wordList,bw,ew);

    for(auto it:ans){
        cout<<"[ ";
        for(auto i:it){
            cout<<i<<"-->";
        }
        cout<<"]"<<endl;
    }
return 0;
}