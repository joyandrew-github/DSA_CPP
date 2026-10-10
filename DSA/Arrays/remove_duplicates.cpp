#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3};
    // Approach:Two pointer
    if (arr.empty())
    {
        return 0;
    }
    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    for (int x = 0; x <= i; x++)
    {
        cout << arr[x] << " ";
    }
    cout << "Unique Elements count" << i + 1;
    return 0;
}