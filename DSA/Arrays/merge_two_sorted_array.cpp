#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};
    vector<int> res=arr1;
    for(int n:arr2){
        res.push_back(n);
    }
    sort(res.begin(),res.end());

    for(int x:res){
        cout<<x<<" ";
    }
    // int i=0,j=0;


    // while(i<arr1.size() && j<arr2.size()){
    //     if(arr1[i]<arr2[j]){
    //         res.push_back(arr1[i]);
    //         i++;
    //     }else{
    //         res.push_back(arr2[j]);
    //         j++;
    //     }
    // }
    // while(i<arr1.size()){
    //     res.push_back(arr1[i]);
    //     i++;
    // }
    // while(j<arr2.size()){
    //     res.push_back(arr2[j]);
    //     j++;
    // }
    // for(int x:res){
    //     cout<<x<<" ";
    // }

    return 0;
}