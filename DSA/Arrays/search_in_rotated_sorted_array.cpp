#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums={4, 5, 6, 7, 0, 1, 2};
    int target=0;
    //binary search
    int left=0; //first index of the array.
    int right=nums.size()-1;  //last index of the array, because there are 7 elements.

    while(left<=right){
        int mid=left+(right-left)/2;
        
        //mid element is target
        if(nums[mid]==target){
            cout<<mid;
            return 0;
        }

        //left half
        if(nums[left]<=nums[mid]){
            if(nums[left]<=target && target<nums[mid]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }

        //right half
        else {
            if(nums[mid]<target && target<=nums[right]){
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }
    
    }
    cout<<"-1";
    return 0;
}