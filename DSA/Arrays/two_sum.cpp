// #include<iostream>
// #include <vector>
// using namespace std;

// int main(){
//     vector<int>arr={2, 7, 11, 15};
//     int target=9;

//     for(int i=0;i<arr.size();i++){
//         for(int j=i+1;j<arr.size();j++){
//             if(arr[i]+arr[j]==target){
//                 cout<<"Indexes:" <<i<<" "<<j;
//                 return 0;
//             }
//         }
//     }
// }




//Optimized using Hashmap


// Needed=target-curr value

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        int need=target-arr[i];
        if(mp.find(need)!=mp.end()){
            cout<<mp[need]<<" "<<i;

        }
        mp[arr[i]]=i;
    }
    return 0;
}