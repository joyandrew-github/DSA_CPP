#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<int,int>mp;

    for(char ch:s){
        mp[ch]++;
    }
    for(int i=0;i<s.size();i++){
        if(mp[s[i]]==1){
            cout<<i;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}