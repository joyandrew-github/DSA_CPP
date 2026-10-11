
//union of sorted arrays
// #include <iostream>
// #include <vector>
// #include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 3, 5, 6};
    // vector<int> res;

    // int i=0,j=0;
    // while(i<arr1.size() && j<arr2.size()){
    //     int x;
    //     if(arr1[i]<arr2[j]){
    //         x=arr1[i];
    //         i++;
    //     }
    //     else if(arr1[i]>arr2[j]){
    //         x=arr2[j];
    //         j++;
    //     }
    //     else{
    //         x=arr2[i];
    //         i++;
    //         j++;

    //     }
    // }
    set<int>s;
    for(int x:arr1){
        s.insert(x);
    }
    for(int x:arr2){
        s.insert(x);
    }
    for(int x:s){
        cout<<x<<" ";
    }
    return 0;
}