#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string>strs;
    int n;

    cout<<"Enter number of Strings :";
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        strs.push_back(s);
    }

    unordered_map<string,vector<string>>mp;

    for(string s:strs){
        string key=s;
        sort(key.begin(),key.end());

        mp[key].push_back(s);
    }
    cout<<"Group Anagrams :";

    for(auto &it:mp){
        for(string s:it.second){
            cout<<s<<" ";
        }
        cout<<endl;
    }

    return 0;
}