#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    // for(int i=arr.size()-1;i>=0;i--){
    //     cout<<arr[i]<<" ";
    // }
    // return 0;

    // Two pointer
    // int i = 0;
    // int j = arr.size() - 1;
    // while (i < j)
    // {
    //     int temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;
    //     i++;
    //     j--;
    // }
    // for (int x : arr)
    // {
    //     cout << x << " " << endl;
    // }
    // return 0;




    //Using Stack--LIFO
    stack<int>st;
    //Push
    for(int i=0;i<arr.size();i++){
        st.push(arr[i]);
    }

    //Pop
    for(int i=0;i<arr.size();i++){
        arr[i]=st.top();
        st.pop();
    }

    //reverse
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;

}