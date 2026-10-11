#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int curr_sum=arr[0];
    int maxi_sum=arr[0];
    for(int i=1;i<arr.size();i++){
        curr_sum=max(arr[i],curr_sum+arr[i]);  //calculate curr subarray sum
        maxi_sum=max(maxi_sum,curr_sum);

    }
    cout<<maxi_sum;
    return 0;
}