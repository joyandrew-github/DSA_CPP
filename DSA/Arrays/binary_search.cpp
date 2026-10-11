#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={10, 20, 30, 40, 50, 60, 70};
    int target=30;

    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]==target){
            cout<<"Found at Index :"<<mid;
            return 0;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }else if(arr[mid]>target){
            high=mid-1;
        }
    }
    cout<<"Not found";
    return 0;

}