
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={10, 20, 30, 40, 50};
    //{10,30,60,20,5}
    bool sorted =true;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]){
            sorted=false;
            break;
        }

    }
    if(sorted){
        cout<<"Sorted";
    }
    else{
        cout<<"Not sorted";
    }
    return 0;
}