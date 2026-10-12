#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        if (!isalnum(s[left]))
        {
            left++;
        }
        else if (!isalnum(s[right]))
        {
            right--;
        }
        else
        {
            if (tolower(s[left]) != tolower(s[right]))
            {
                cout << "Not Palindrome";
                return 0;
            }
            left++;
            right--;
        }
    }
    cout << "Palindrome";
    return 0;
}