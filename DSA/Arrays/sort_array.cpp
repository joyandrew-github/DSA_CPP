// Sort an Array of 0s, 1s, and 2s


#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 0, 1, 2, 1, 0};
    int zeros=0;
    int ones=0;
    int twos=0;
    // for(int x:arr){
    //     if(x==0){
    //         zeros++;
    //     }
    //     else if(x==1){
    //         ones++;
    //     }
    //     else if(x==2){
    //         twos++;
    //     }
    // }
    // int i=0;
    // while(zeros>0){
    //     arr[i]=0;
    //     i++;
    //     zeros--;
    // }
    // while(ones>0){
    //     arr[i]=1;
    //     i++;
    //     ones--;
    // }
    // while(twos>0){
    //     arr[i]=2;
    //     i++;
    //     twos--;
    // } 
    // for(int x:arr){
    //     cout<<x<<" ";
    // }

    int low=0;
    int mid=0;
    int high=arr.size()-1;
    while(mid<=high){
         if(arr[mid]==0)
            {
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1)
            {
                mid++;
            }
            else if(arr[mid]==2)
            {
                swap(arr[mid],arr[high]);
                high--;
            }
    }
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;
}