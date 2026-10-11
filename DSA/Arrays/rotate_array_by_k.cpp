#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    int n = arr.size();

    k=k%n;
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;
}