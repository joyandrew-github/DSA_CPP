#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    unordered_set<int>st;
    int left=0;
    int maxi=0;

    for(int i=0;i<s.size();i++){
        while(st.count(s[i])){
            st.erase(s[left]);
            left++;
        }
        st.insert(s[i]);
        maxi=max(maxi,i-left+1);
    }
    cout<< maxi;
}