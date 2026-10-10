#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr={10,20,30,40,50};
    int maxi=INT_MIN;
    int second_largest=INT_MIN;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>maxi){
            second_largest=maxi;
            maxi=arr[i];
        }
        else if(arr[i]>second_largest && arr[i]!=maxi){
            second_largest=arr[i];
        }
    }
    cout<<second_largest;
    return 0;
}