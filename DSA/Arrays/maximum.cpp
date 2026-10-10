//. Find the largest element
#include<iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int n=5;
    int maxi=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    cout<< maxi;
    return 0;
}