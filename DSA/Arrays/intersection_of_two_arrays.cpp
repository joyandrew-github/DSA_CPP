#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 3, 5, 6};

    set<int>s(arr1.begin(),arr1.end());
    set<int>res;

    for(int x:arr2){
        if(s.find(x)!=s.end()){
            res.insert(x);
        }
    }
    for(int x:res){
        cout<<x<<" ";
    }
    return 0;
}