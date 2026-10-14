#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    if (strs.empty())
    {
        cout << "";
        return 0;
    }

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++)
    {
        int j = 0;

        while (j < prefix.size() &&
               j < strs[i].size() &&
               prefix[j] == strs[i][j])
        {
            j++;
        }

        prefix = prefix.substr(0, j);

        if (prefix.empty())
        {
            cout << "";
            return 0;
        }
    }

    cout << "Longest Common Prefix: " << prefix;

    return 0;
}