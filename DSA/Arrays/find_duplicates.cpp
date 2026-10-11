#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 2, 4, 1, 5};

    unordered_set<int>seen;
    unordered_set<int>duplicate;
    for(int i=0;i<arr.size();i++){
        if(seen.find(arr[i])!=seen.end()){
            duplicate.insert(arr[i]);
        }
        else{
            seen.insert(arr[i]);
        }
    }
    for(int x:duplicate){
        cout<<x<<" ";
    }
    return 0;
}