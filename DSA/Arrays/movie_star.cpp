#include <bits/stdc++.h>
using namespace std;

string solve(vector<string> names, vector<vector<int>> mat) {
    int n = names.size();

    for (int i = 0; i < n; i++) {
        bool celebrity = true;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            // Celebrity knows nobody
            // Everyone knows the celebrity
            if (mat[i][j] == 1 || mat[j][i] == 0) {
                celebrity = false;
                break;
            }
        }

        if (celebrity) {
            return names[i];
        }
    }

    return "No celebrity";
}

int main() {
    vector<string> names = {"A", "B", "C", "D", "E"};

    vector<vector<int>> mat = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    cout << solve(names, mat);

    return 0;
}