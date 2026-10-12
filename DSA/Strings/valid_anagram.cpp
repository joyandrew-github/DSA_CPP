#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;

    if(s.size()!=t.size()) 
    {
        cout<<"False";
        return 0;
    }
    unordered_map<int,int>mp;

    for(char c:s){
        mp[c]++;
    }
    for(char c:t){
        mp[c]--;
    }
    for(auto it:mp){
        if(it.second!=0){
            cout<<"False";
            return 0;
        }
    }
    cout<<"True";
    return 0;
}