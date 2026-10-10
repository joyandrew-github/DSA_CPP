//min and max in array

#include<iostream>
using namespace std;

int main(){
    int arr[]= {-5, -12, -2, -20, -8};
    int n=5;
    int maxi=arr[0];
    int mini=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<mini){
            mini=arr[i];
        }
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    cout<<mini<<endl;
    cout<< maxi;
    return 0;
}