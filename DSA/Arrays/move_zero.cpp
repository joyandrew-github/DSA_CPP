#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={0, 1, 0, 3, 12};

    int i=0;
    for(int j=0;j<arr.size();j++){
        if(arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
        }

    }
    for(int x:arr){
        cout<<x<<" ";

    }
    return 0;
}