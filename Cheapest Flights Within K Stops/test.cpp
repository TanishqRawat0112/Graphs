#include<iostream>
using namespace std;

int hashf(string s){
    int hash=0;
    for (int i=0;i<s.length();i++){
        hash+=(i+1)*(s[i]-'a'+1);
    }
    return hash;
}
 
int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;

    int l1=hashf(s1);
    int l2=hashf(s2);

    cout<<l1<<" "<<l2<<endl;


return 0;
}