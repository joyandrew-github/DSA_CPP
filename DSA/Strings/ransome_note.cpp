#include<bits/stdc++.h>
using namespace std;

int main(){
    string ransomNote,magazine;
    cin>>ransomNote>>magazine;

    unordered_map<int,int>mp;
    for(char ch:magazine){
        mp[ch]++;
    }
    for(char c:ransomNote){
        if(mp[c]==0){
            cout<<"False";
            return 0;
        }
        mp[c]--;
    }
    cout<<"True";
    return 0;
}