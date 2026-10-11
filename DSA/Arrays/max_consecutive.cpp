
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int count=0;
    int maxi_count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
            maxi_count=max(count,maxi_count);
        }
        else{
            count=0;
        }

    }
    cout<<maxi_count;
    return 0;
}