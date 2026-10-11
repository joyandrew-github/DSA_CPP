#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    int temp = arr[n - 1]; // points to the index 4
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = temp;
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}